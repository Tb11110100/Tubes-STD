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
        cout << "- " << grupName(grup) << " members: ";
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
}
