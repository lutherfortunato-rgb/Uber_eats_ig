#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

Graph *createGraph() {
    Graph *g = malloc(sizeof(Graph));

    if (g == NULL) {
        return NULL;
    }

    g->vertexCount = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        g->vertices[i].head = NULL;
        g->vertices[i].name[0] = '\0';
    }

    return g;
}

int addVertex(Graph *g, const char *name) {

    if (g->vertexCount >= MAX_VERTICES) {
        return -1;
    }

    strcpy(g->vertices[g->vertexCount].name, name);
    g->vertices[g->vertexCount].head = NULL;

    g->vertexCount++;

    return g->vertexCount - 1;
}

int findVertex(Graph *g, const char *name) {

    for (int i = 0; i < g->vertexCount; i++) {

        if (strcmp(g->vertices[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void addEdge(Graph *g,
             int source,
             int destination,
             int weight) {

    Edge *newEdge = malloc(sizeof(Edge));

    if (newEdge == NULL) {
        return;
    }

    newEdge->destination = destination;
    newEdge->weight = weight;

    newEdge->next = g->vertices[source].head;
    g->vertices[source].head = newEdge;

    /*
        Undirected graph:
        Add reverse edge
    */

    Edge *reverseEdge = malloc(sizeof(Edge));

    if (reverseEdge == NULL) {
        return;
    }

    reverseEdge->destination = source;
    reverseEdge->weight = weight;

    reverseEdge->next = g->vertices[destination].head;
    g->vertices[destination].head = reverseEdge;
}

void printGraph(Graph *g) {

    printf("\n===== CITY MAP =====\n");

    for (int i = 0; i < g->vertexCount; i++) {

        printf("%s:\n", g->vertices[i].name);

        Edge *current = g->vertices[i].head;

        while (current != NULL) {

            printf(" -> %s (%d km)\n",
                   g->vertices[current->destination].name,
                   current->weight);

            current = current->next;
        }

        printf("\n");
    }
}

void freeGraph(Graph *g) {

    for (int i = 0; i < g->vertexCount; i++) {

        Edge *current = g->vertices[i].head;

        while (current != NULL) {

            Edge *temp = current;
            current = current->next;

            free(temp);
        }
    }

    free(g);
}
