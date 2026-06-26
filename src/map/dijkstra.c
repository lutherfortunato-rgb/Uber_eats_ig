#include <stdio.h>

#include "dijkstra.h"

/*
 * Returns the index of the unvisited vertex
 * with the smallest distance.
 */
static int minDistance(
    int dist[],
    int visited[],
    int vertexCount
) {

    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < vertexCount; i++) {

        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int shortestDistance(
    Graph *g,
    int source,
    int destination
) {

    if (g == NULL) {
        return INF;
    }

    if (source < 0 || source >= g->vertexCount ||
        destination < 0 || destination >= g->vertexCount) {
        return INF;
    }

    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < g->vertexCount; i++) {

        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < g->vertexCount - 1; count++) {

        int u = minDistance(
            dist,
            visited,
            g->vertexCount
        );

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        Edge *current = g->vertices[u].head;

        while (current != NULL) {

            int v = current->destination;

            if (!visited[v] &&
                dist[u] != INF &&
                dist[u] + current->weight < dist[v]) {

                dist[v] = dist[u] + current->weight;
            }

            current = current->next;
        }
    }

    return dist[destination];
}

void printShortestPath(
    Graph *g,
    int source,
    int destination
) {

    if (g == NULL) {
        return;
    }

    if (source < 0 || source >= g->vertexCount ||
        destination < 0 || destination >= g->vertexCount) {

        printf("Invalid source or destination.\n");
        return;
    }

    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int previous[MAX_VERTICES];

    for (int i = 0; i < g->vertexCount; i++) {

        dist[i] = INF;
        visited[i] = 0;
        previous[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < g->vertexCount - 1; count++) {

        int u = minDistance(
            dist,
            visited,
            g->vertexCount
        );

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        Edge *current = g->vertices[u].head;

        while (current != NULL) {

            int v = current->destination;

            if (!visited[v] &&
                dist[u] != INF &&
                dist[u] + current->weight < dist[v]) {

                dist[v] = dist[u] + current->weight;
                previous[v] = u;
            }

            current = current->next;
        }
    }

    if (dist[destination] == INF) {

        printf("No route found.\n");
        return;
    }

    int path[MAX_VERTICES];
    int count = 0;

    int current = destination;

    while (current != -1) {

        path[count++] = current;
        current = previous[current];
    }

    printf("\n===== BEST ROUTE =====\n");

    for (int i = count - 1; i >= 0; i--) {

        printf("%s", g->vertices[path[i]].name);

        if (i > 0) {
            printf(" -> ");
        }
    }

    printf("\n");

    printf("Distance: %d km\n", dist[destination]);

    printf(
        "Estimated Time: %d minutes\n",
        estimateTime(dist[destination])
    );
}

int estimateTime(int distance) {

    if (distance <= 0) {
        return 0;
    }

    return (distance * 60) / AVG_SPEED_KMH;
}