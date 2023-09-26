#include <stdio.h>
#include <stdlib.h>

struct Sommet {
	int id;
	unsigned int distance;
};

struct Arc {
	int poids;
	struct Sommet *debut;
	struct Sommet *fin;
};


struct Graphe { 
	struct Sommet *sommets;
	int nombreSommets;
	struct Arc *arcs;
	int nombreArcs;
};

void initialisation(struct Graphe* g, int debut) {
	for (int i = 0; i < g->nombreSommets; i++) {
		g->sommets[i].distance = -1;
	}	
	g->sommets[debut].distance = 0;
}

//create sub domain q
int trouve_adjacent (struct Graphe* p, int id, struct Sommet* found) {

	struct Arc* arcs = p->arcs;
	int nbrArc = p->nombreArcs;
	
	if (found != NULL) free(found);

	found = malloc(sizeof(struct Sommet)*nbrArc);
	int foundNumber = 0;

	for (int i = 0; i < nbrArc; i++) {
		if        ( arcs[i].debut->id == id) {
			found[foundNumber] = *(arcs[i].fin);
			foundNumber++;
		} else if ( arcs[i].fin->id == id ) {
			found[foundNumber] = *(arcs[i].debut);
			foundNumber++;
		}
	}

	return foundNumber;
}

//find min in sub domain q
struct sommet* trouve_min (struct Graphe* q) {
	// trouve le sommet le plus proche
	return NULL;
}

int main (int argc, char** argv) {
	struct Sommet s1 = {0, 1};
	struct Sommet s2 = {1, 1};
	struct Sommet s3 = {2, 1};

	struct Sommet listeSommet[] = {s1, s2, s3}; 

	struct Arc a1 = {1, &s1, &s2};
	struct Arc a2 = {2, &s2, &s3};
	struct Arc a3 = {4, &s3, &s1};

	struct Arc listeArc[] = {a1, a2, a3};

	struct Graphe* g = malloc(sizeof(struct Graphe));
	g->nombreSommets = 3;
	g->sommets = listeSommet;
	g->arcs = listeArc;
	g->nombreArcs = 3;
	initialisation(g, 0);
	
	struct Sommet* s = NULL;
	int result = trouve_adjacent (g, 0, s);
	printf("Adjacent: %d\n", result);

	return 0;
}
