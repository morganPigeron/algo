#include <stdio.h>
#include <stdlib.h>

struct Point {
	int id;
	unsigned int distance;
};

void print_point(const struct Point* s) {
	if (s == NULL) {
		printf("NULL point\n");
		return ;
	}
	printf("Point : %d with distance %u\n", s->id, s->distance);
}

struct Arc {
	int poids;
	struct Point *debut;
	struct Point *fin;
};


void print_arc(const struct Arc* a) {
	if (a == NULL) {
		printf("NULL arc\n");
		return;
	}
	printf("Arc : %d |--- %d ---> %d\n", a->debut->id, a->poids, a->fin->id);
}


struct Graphe { 
	struct Point *points;
	int numberPoints;
	struct Arc *arcs;
	int numberArcs;
};

void initialisation(struct Graphe* g, int debut) {
	for (int i = 0; i < g->numberPoints; i++) {
		g->points[i].distance = -1;
	}	
	g->points[debut].distance = 0;
}

//create sub domain q
int find_neigh (struct Graphe* p, int id, struct Point** found) {

	struct Arc* arcs = p->arcs;
	int nbrArc = p->numberArcs;
	
	if (found != NULL) free(*found);

	*found = malloc(sizeof(struct Point)*nbrArc);
	int foundNumber = 0;

	for (int i = 0; i < nbrArc; i++) {
		if        ( arcs[i].debut->id == id) {
			found[foundNumber] = arcs[i].fin;
			foundNumber++;
		} else if ( arcs[i].fin->id == id ) {
			found[foundNumber] = arcs[i].debut;
			foundNumber++;
		}
	}

	return foundNumber;
}
//find min in sub domain q
struct Point* trouve_min (struct Graphe* q) {
	// trouve le point le plus proche
	return NULL;
}

int main (int argc, char** argv) {
	struct Point s1 = {0, 1};
	struct Point s2 = {1, 1};
	struct Point s3 = {2, 1};

	struct Point listePoint[] = {s1, s2, s3}; 

	struct Arc a1 = {1, &s1, &s2};
	struct Arc a2 = {2, &s2, &s3};
	struct Arc a3 = {4, &s3, &s1};

	struct Arc listeArc[] = {a1, a2, a3};
	
	for ( int i = 0; i<3; i++) {
		print_arc(&listeArc[i]);	
	}

	struct Graphe* g = malloc(sizeof(struct Graphe));
	g->numberPoints = 3;
	g->points = listePoint;
	g->arcs = listeArc;
	g->numberArcs = 3;
	initialisation(g, 0);
	
	struct Point* s = NULL;
	int result = find_neigh(g, 0, &s);
	for (int i=0; i<result; i++) {
		print_point(&s[i]);
	}
	
	printf("Adjacent: %d\n", result);

	return 0;
}
