#include "GRAF.h"

int main() {
    Graph G;
    initGraph(G);

    addAkun(G, "Tubagus");
    addAkun(G, "Zidan");
    addAkun(G, "Ilham");
    addAkun(G, "Razky");
    addAkun(G, "Damai");

    addFollow(G, "Tubagus", "Zidan");
    addFollow(G, "Tubagus", "Ilham");
    addFollow(G, "Tubagus", "Razky");
    addFollow(G, "Tubagus", "Damai");

    addFollow(G, "Zidan", "Tubagus");
    addFollow(G, "Zidan", "Ilham");
    addFollow(G, "Zidan", "Damai");

    addFollow(G, "Ilham", "Zidan");

    addFollow(G, "Razky", "Tubagus");
    addFollow(G, "Razky", "Ilham");
    addFollow(G, "Razky", "Zidan");

    addFollow(G, "Damai", "Zidan");
    addFollow(G, "Damai", "Razky");


    addGrup(G, "FitRent");
    addMember(G, "FitRent", "Tubagus");
    addMember(G, "FitRent", "Zidan");
    addMember(G, "FitRent", "Ilham");
    addMember(G, "FitRent", "Damai");
    addMember(G, "FitRent", "Razky");

    addGrup(G, "SES");
    addMember(G, "SES", "Tubagus");

    addGrup(G, "CCI");
    addMember(G, "CCI", "Damai");
    addMember(G, "CCI", "Ilham");

    addGrup(G, "Telkom Radio");
    addMember(G, "Telkom Radio", "Razky");



    printGraph(G);

    return 0;
}