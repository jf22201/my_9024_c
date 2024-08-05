#include "graph.h"
#include <limits.h>
#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#define INF INT_MAX;
void dijkstra(GraphPtr pGraph,int startNode);
int findShortestDistNode(GraphPtr pGraph,int* distanceArr,int* visitedArr);




#endif