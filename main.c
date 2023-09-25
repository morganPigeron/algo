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
};

void initialisation(struct Graphe* g, int debut) {
	for (int i = 0; i < g->nombreSommets; i++) {
		g->sommets[i].distance = -1;
	}	
	g->sommets[debut].distance = 0;
}

int main (int argc, char** argv) {
	struct Sommet s1 = {0, 1};
	struct Sommet s2 = {1, 1};
	struct Sommet s3 = {2, 1};

	struct Sommet list[] = {s1, s2, s3}; 

	struct Graphe* g = malloc(sizeof(struct Graphe));
	g->nombreSommets = 3;
	g->sommets = list;

	initialisation(g, 0);

	printf("done\n");

	return 0;
}
