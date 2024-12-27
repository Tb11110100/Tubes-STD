#include "GRAF.h"

void initGraph(Graph& G) {
    firstAkun(G) = Nil;
    firstGrup(G) = Nil;
}

void addAkun(Graph& G, string namaAkun) {
    adrVertexAkun newAkun = new VertexAkun;
    namaAkun(newAkun) = namaAkun;
    firstFollow(newAkun) = Nil;
    nextAkun(newAkun) = Nil;

    if (firstAkun(G) == Nil) {
        firstAkun(G) = newAkun;
    } else {
        adrVertexAkun temp = firstAkun(G);
        while (nextAkun(temp) != Nil) {
            temp = nextAkun(temp);
        }
        nextAkun(temp) = newAkun;
    }
}

void addGrup(Graph& G, string namaGrup) {
    adrVertexGrup newGrup = new VertexGrup;
    grupName(newGrup) = namaGrup;
    firstMember(newGrup) = Nil;
    nextGrup(newGrup) = Nil;

    if (firstGrup(G) == Nil) {
        firstGrup(G) = newGrup;
    } else {
        adrVertexGrup temp = firstGrup(G);
        while (nextGrup(temp) != Nil) {
            temp = nextGrup(temp);
        }
        nextGrup(temp) = newGrup;
    }
}

void addFollow(Graph& G, string akun1, string akun2) {
    adrVertexAkun src = firstAkun(G);
    while (src != Nil && namaAkun(src) != akun1) {
        src = nextAkun(src);
    }

    if (src != Nil) {
        adrEdgeFollow newFollow = new EdgeFollow;
        followName(newFollow) = akun2;
        nextFollow(newFollow) = Nil;

        if (firstFollow(src) == Nil) {
            firstFollow(src) = newFollow;
        } else {
            adrEdgeFollow temp = firstFollow(src);
            while (nextFollow(temp) != Nil) {
                temp = nextFollow(temp);
            }
            nextFollow(temp) = newFollow;
        }
    }
}

void addMember(Graph& G, string grup, string akun) {
    adrVertexGrup group = firstGrup(G);
    while (group != Nil && grupName(group) != grup) {
        group = nextGrup(group);
    }

    if (group != Nil) {
        adrEdgeMember newMember = new EdgeMember;
        memberName(newMember) = akun;
        nextMember(newMember) = Nil;

        if (firstMember(group) == Nil) {
            firstMember(group) = newMember;
        } else {
            adrEdgeMember temp = firstMember(group);
            while (nextMember(temp) != Nil) {
                temp = nextMember(temp);
            }
            nextMember(temp) = newMember;
        }
    }
}


void printGraph(const Graph& G) {
    cout << "====================GRAF SOSIAL MEDIA====================" << endl << endl;

    cout << "Akun:" << endl;
    adrVertexAkun akun = firstAkun(G);
    while (akun != Nil) {
        cout << namaAkun(akun) << " follows:";
        adrEdgeFollow follow = firstFollow(akun);
        while (follow != Nil) {
            cout << followName(follow);
            follow = nextFollow(follow);
            if (follow != Nil) {
                cout << ", ";
            }
        }
        cout << endl;
        akun = nextAkun(akun);
    }

    cout << endl;
    cout << "Grup: " << endl;
    adrVertexGrup grup = firstGrup(G);
    while (grup != Nil) {
        cout << grupName(grup) << " members: ";
        adrEdgeMember member = firstMember(grup);
        while (member != Nil) {
            cout << memberName(member);
            member = nextMember(member);
            if (member != Nil) {
                cout << ", ";
            }
        }
        cout << endl;
        grup = nextGrup(grup);
    }
    cout << "=========================================================" << endl;
}

bool isMutual(const Graph& G, string akun1, string akun2){
    adrVertexAkun a1 = firstAkun(G);
    while (a1 != Nil && namaAkun(a1) != akun1){
        a1 = nextAkun(a1);
    }
    adrVertexAkun a2 = firstAkun(G);
    while (a2 != Nil && namaAkun(a2) != akun2) {
        a2 = nextAkun(a2);
    }
    if (a1 == Nil || a2 == Nil) return false;
    bool followsA1toA2 = false, followsA2toA1 = false;
    adrEdgeFollow follow = firstFollow(a1);
    while (follow != Nil) {
        if (followName(follow) == akun2) {
            followsA1toA2 = true;
            break;
        }
        follow = nextFollow(follow);
    }
    follow = firstFollow(a2);
    while (follow != Nil) {
        if (followName(follow) == akun1) {
            followsA2toA1 = true;
            break;
        }
        follow = nextFollow(follow);
    }
    return followsA1toA2 && followsA2toA1;
}

string mostFollowed(const Graph& G) {
    string mostFollowedAkun;
    int maxFollowers = 0;

    adrVertexAkun akun = firstAkun(G);
    while (akun != Nil) {
        int count = 0;
        adrVertexAkun temp = firstAkun(G);
        while (temp != Nil) {
            adrEdgeFollow follow = firstFollow(temp);
            while (follow != Nil) {
                if (followName(follow) == namaAkun(akun)) {
                    count++;
                    break;
                }
                follow = nextFollow(follow);
            }
            temp = nextAkun(temp);
        }

        if (count > maxFollowers) {
            maxFollowers = count;
            mostFollowedAkun = namaAkun(akun);
        }

        akun = nextAkun(akun);
    }

    return mostFollowedAkun;
}

string mostJoined(const Graph& G) {
    string mostJoinedGroup;
    int maxMembers = 0;

    adrVertexGrup grup = firstGrup(G);
    while (grup != Nil) {
        int count = 0;
        adrEdgeMember member = firstMember(grup);
        while (member != Nil) {
            count++;
            member = nextMember(member);
        }

        if (count > maxMembers) {
            maxMembers = count;
            mostJoinedGroup = grupName(grup);
        }

        grup = nextGrup(grup);
    }

    return mostJoinedGroup;
}

void deleteAccount(Graph& G, string akun) {
    // Menghapus akun dari daftar followers setiap akun
    adrVertexAkun akunToDelete = firstAkun(G);
    while (akunToDelete != Nil && namaAkun(akunToDelete) != akun) {
        akunToDelete = nextAkun(akunToDelete);
    }

    if (akunToDelete != Nil) {
        // Menghapus follow pada akun lain
        adrVertexAkun temp = firstAkun(G);
        while (temp != Nil) {
            adrEdgeFollow follow = firstFollow(temp);
            adrEdgeFollow prevFollow = Nil;
            while (follow != Nil) {
                if (followName(follow) == akun) {
                    if (prevFollow == Nil) {
                        firstFollow(temp) = nextFollow(follow);
                    } else {
                        nextFollow(prevFollow) = nextFollow(follow);
                    }
                    delete follow;
                    break;
                }
                prevFollow = follow;
                follow = nextFollow(follow);
            }
            temp = nextAkun(temp);
        }

        // Menghapus akun dari daftar follow
        adrEdgeFollow follow = firstFollow(akunToDelete);
        while (follow != Nil) {
            adrEdgeFollow tempFollow = follow;
            follow = nextFollow(follow);
            delete tempFollow;
        }

        // Menghapus akun dari daftar akun
        if (firstAkun(G) == akunToDelete) {
            firstAkun(G) = nextAkun(akunToDelete);
        } else {
            adrVertexAkun prevAkun = firstAkun(G);
            while (nextAkun(prevAkun) != akunToDelete) {
                prevAkun = nextAkun(prevAkun);
            }
            nextAkun(prevAkun) = nextAkun(akunToDelete);
        }
        delete akunToDelete;
    }
}

void deleteGroup(Graph& G, string grup) {
    adrVertexGrup grupToDelete = firstGrup(G);
    while (grupToDelete != Nil && grupName(grupToDelete) != grup) {
        grupToDelete = nextGrup(grupToDelete);
    }

    if (grupToDelete != Nil) {
        // Menghapus semua anggota dari grup
        adrEdgeMember member = firstMember(grupToDelete);
        while (member != Nil) {
            adrEdgeMember tempMember = member;
            member = nextMember(member);
            delete tempMember;
        }

        // Menghapus grup dari daftar grup
        if (firstGrup(G) == grupToDelete) {
            firstGrup(G) = nextGrup(grupToDelete);
        } else {
            adrVertexGrup prevGrup = firstGrup(G);
            while (nextGrup(prevGrup) != grupToDelete) {
                prevGrup = nextGrup(prevGrup);
            }
            nextGrup(prevGrup) = nextGrup(grupToDelete);
        }
        delete grupToDelete;
    }
}

void unfollow(Graph& G, string akun1, string akun2) {
    adrVertexAkun a1 = firstAkun(G);
    while (a1 != Nil && namaAkun(a1) != akun1) {
        a1 = nextAkun(a1);
    }
    adrVertexAkun a2 = firstAkun(G);
    while (a2 != Nil && namaAkun(a2) != akun2) {
        a2 = nextAkun(a2);
    }

    if (a1 != Nil && a2 != Nil) {
        // Menghapus follow dari akun1 ke akun2
        adrEdgeFollow follow = firstFollow(a1);
        adrEdgeFollow prevFollow = Nil;
        while (follow != Nil) {
            if (followName(follow) == akun2) {
                if (prevFollow == Nil) {
                    firstFollow(a1) = nextFollow(follow);
                } else {
                    nextFollow(prevFollow) = nextFollow(follow);
                }
                delete follow;
                break;
            }
            prevFollow = follow;
            follow = nextFollow(follow);
        }

        // Menghapus follow dari akun2 ke akun1 jika mutual
        follow = firstFollow(a2);
        prevFollow = Nil;
        while (follow != Nil) {
            if (followName(follow) == akun1) {
                if (prevFollow == Nil) {
                    firstFollow(a2) = nextFollow(follow);
                } else {
                    nextFollow(prevFollow) = nextFollow(follow);
                }
                delete follow;
                break;
            }
            prevFollow = follow;
            follow = nextFollow(follow);
        }
    }
}
