#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 100

typedef struct Edge {
    int destination;
    int weight;
    struct Edge *next;
} Edge;

typedef struct {
    char name[50];
    Edge *head;
} Vertex;

typedef struct {
    Vertex vertices[MAX_VERTICES];
    int vertexCount;
} Graph;

/* Creation */
Graph *createGraph();

/* Vertex operations */
int addVertex(Graph *g, const char *name);
int findVertex(Graph *g, const char *name);

/* Edge operations */
void addEdge(Graph *g, int source, int destination, int weight);

/* Route helper */
void printRouteByName(
    Graph *g,
    const char *sourceName,
    const char *destinationName
);

/* Visualization */
void printGraph(Graph *g);

/* Cleanup */
void freeGraph(Graph *g);

#endif