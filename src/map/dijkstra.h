#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

#define INF 999999
#define AVG_SPEED_KMH 30

/*
 * Returns the shortest distance between source and destination.
 */
int shortestDistance(
    Graph *g,
    int source,
    int destination
);

/*
 * Prints the shortest path and its distance.
 */
void printShortestPath(
    Graph *g,
    int source,
    int destination
);

/*
 * Returns an estimated travel time in minutes.
 */
int estimateTime(int distance);

#endif