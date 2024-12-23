#ifndef GRAF_H
#define GRAF_H

#include <iostream>
using namespace std;

// Graf
#define firstAkun(G) G.firstAkun
#define firstGrup(G) G.firstGrup

// VertexAkun
#define namaAkun(V) V->namaAkun
#define firstFollow(V) V->firstFollow
#define nextAkun(V) V->nextAkun

// EdgeFollow
#define nextFollow(E) E->nextFollow
#define followName(E) E->amaAkun

// VertexGrup
#define grupName(V) V->namaGrup
#define firstMember(V) V->firstMember
#define nextGrup(V) V->nextGrup

// EdgeMember
#define nextMember(E) E->nextMember
#define memberName(E) E->namaAkun

#define Nil NULL

typedef struct VertexAkun* adrVertexAkun;
typedef struct VertexGrup* adrVertexGrup;
typedef struct EdgeFollow* adrEdgeFollow;
typedef struct EdgeMember* adrEdgeMember;

struct EdgeFollow {
    string amaAkun;
    adrEdgeFollow nextFollow;
};

struct EdgeMember {
    string namaAkun;
    adrEdgeMember nextMember;
};

struct VertexAkun {
    string namaAkun;
    adrEdgeFollow firstFollow;
    adrVertexAkun nextAkun;
};

struct VertexGrup {
    string namaGrup;
    adrEdgeMember firstMember;
    adrVertexGrup nextGrup;
};

struct Graph {
    adrVertexAkun firstAkun;
    adrVertexGrup firstGrup;
};

void initGraph(Graph& G);
void addAkun(Graph& G, string namaAkun);
void addGrup(Graph& G, string namaGrup);
void addFollow(Graph& G, string akun1, string akun2);
void addMember(Graph& G, string grup, string akun);
void printGraph(const Graph& G);

#endif
