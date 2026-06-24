#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "dijkstra.h"

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

    if (g == NULL || name == NULL) {
        return -1;
    }

    /* Prevent duplicate locations */
    int existing = findVertex(g, name);

    if (existing != -1) {
        return existing;
    }

    if (g->vertexCount >= MAX_VERTICES) {
        return -1;
    }

    strncpy(
        g->vertices[g->vertexCount].name,
        name,
        sizeof(g->vertices[g->vertexCount].name) - 1
    );

    g->vertices[g->vertexCount].name[
        sizeof(g->vertices[g->vertexCount].name) - 1
    ] = '\0';

    g->vertices[g->vertexCount].head = NULL;

    g->vertexCount++;

    return g->vertexCount - 1;
}

int findVertex(Graph *g, const char *name) {

    if (g == NULL || name == NULL) {
        return -1;
    }

    for (int i = 0; i < g->vertexCount; i++) {

        if (strcmp(g->vertices[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void addEdge(
    Graph *g,
    int source,
    int destination,
    int weight
) {

    if (g == NULL) {
        return;
    }

    if (source < 0 || source >= g->vertexCount ||
        destination < 0 || destination >= g->vertexCount) {
        return;
    }

    /* Dijkstra requires non-negative weights */
    if (weight < 0) {
        return;
    }

    /* No self-loops in the city map */
    if (source == destination) {
        return;
    }

    Edge *newEdge = malloc(sizeof(Edge));
    Edge *reverseEdge = malloc(sizeof(Edge));

    if (newEdge == NULL || reverseEdge == NULL) {
        free(newEdge);
        free(reverseEdge);
        return;
    }

    /* Forward edge */
    newEdge->destination = destination;
    newEdge->weight = weight;
    newEdge->next = g->vertices[source].head;

    g->vertices[source].head = newEdge;

    /* Reverse edge (undirected graph) */
    reverseEdge->destination = source;
    reverseEdge->weight = weight;
    reverseEdge->next = g->vertices[destination].head;

    g->vertices[destination].head = reverseEdge;
}

void printRouteByName(
    Graph *g,
    const char *sourceName,
    const char *destinationName
) {

    if (g == NULL ||
        sourceName == NULL ||
        destinationName == NULL) {

        return;
    }

    int source = findVertex(g, sourceName);
    int destination = findVertex(g, destinationName);

    if (source == -1 || destination == -1) {

        printf("Location not found.\n");
        return;
    }

    printShortestPath(
        g,
        source,
        destination
    );
}

void printGraph(Graph *g) {

    if (g == NULL) {
        return;
    }

    printf("\n===== CITY MAP =====\n");

    for (int i = 0; i < g->vertexCount; i++) {

        printf("%s:\n", g->vertices[i].name);

        Edge *current = g->vertices[i].head;

        while (current != NULL) {

            printf(
                " -> %s (%d km)\n",
                g->vertices[current->destination].name,
                current->weight
            );

            current = current->next;
        }

        printf("\n");
    }
}

void freeGraph(Graph *g) {

    if (g == NULL) {
        return;
    }

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