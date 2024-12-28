#include "GRAF.h"

int main() {
    string dummyString1;
    string dummyString2;
    Graph G;
    initGraph(G);

    int userChoice = -1;


    while (userChoice != 0) {
        cetakMenu();
        cout << "Masukan pilihan anda : ";
        cin >> userChoice;
        switch(userChoice) {
        case 0:
            cout << "Terimakasih." << endl << endl;
        case 1:
            cout << "Masukan nama akun : ";
            cin >> dummyString1;
            addAkun(G, dummyString1);
            cout << "Akun telah dibuat." << endl << endl;
            break;
        case 2:
            cout << "Masukan nama akun : ";
            cin >> dummyString1;
            deleteAccount(G, dummyString1);
            cout << "Akun telah dihapus." << endl << endl;
            break;
        case 3:
            cout << "Masukan nama grup : ";
            cin >> dummyString1;
            addGrup(G, dummyString1);
            cout << "Grup telah dibuat." << endl << endl;
            break;
        case 4:
            cout << "Masukan nama grup : ";
            cin >> dummyString1;
            deleteGroup(G, dummyString1);
            cout << "Grup telah dihapus." << endl << endl;
            break;
        case 5:
            cout << "Masukan nama akun ke-1 : ";
            cin >> dummyString1;
            cout << "Masukan nama akun ke-2 :";
            cin >> dummyString2;
            addFollow(G, dummyString1, dummyString2);
            cout << dummyString1 << " telah follow " << dummyString2 << "." << endl << endl;
            break;
        case 6:
            cout << "Masukan nama akun ke-1 : ";
            cin >> dummyString1;
            cout << "Masukan nama akun ke-2 :";
            cin >> dummyString2;
            unfollow(G, dummyString1, dummyString2);
            cout << dummyString1 << " telah unfollow " << dummyString2 << "." << endl << endl;
            break;
        case 7:
            cout << "Masukan nama grup : ";
            cin >> dummyString1;
            cout << "Masukan nama akun : ";
            cin >> dummyString2;
            addMember(G, dummyString1, dummyString2);
            cout << dummyString2 << " telah masuk grup " << dummyString1 << "." << endl << endl;
            break;
        case 8:
            cout << "Masukan nama grup : ";
            cin >> dummyString1;
            cout << "Masukan nama akun : ";
            cin >> dummyString2;
            quit(G, dummyString1, dummyString2);
            cout << dummyString2 << " telah keluar grup " << dummyString1 << "." << endl << endl;
            break;
        case 9:
            cout << "Masukan nama akun ke-1 : ";
            cin >> dummyString1;
            cout << "Masukan nama akun ke-2 :";
            cin >> dummyString2;
            if (isMutual(G, dummyString1, dummyString2)){
                cout << dummyString1 << " dan " << dummyString2 << " is mutual" << endl << endl;
            } else {
                cout << dummyString1 << " dan " << dummyString2 << " is not mutual" << endl << endl;
            }
            break;
        case 10:
            cout << "Akun dengan follower terbanyak adalah : " << mostFollowed(G) << endl << endl;
            break;
        case 11:
            cout << "Grup dengan anggota terbanyak adalah : " <<  mostJoined(G)<< endl << endl;
            break;
        case 12:
            printGraph(G);
            cout << endl;
            break;
        case 13:
            prebuildGraf(G);
            break;
        default:
            cout << "Pilihan tidak tersedia, silahkan pilih ulang." << endl << endl;
        }
    }
    return 0;
}
