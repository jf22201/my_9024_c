#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include "dijkstra.h"
void main(){
    
  long edges[][3] = {
        {3, 0, 4},
        {3, 4, 2},
        {0, 2, 3},
        {0, 4, 4},
        {4, 2, 4},

        {4, 6, 5},
        {2, 5, 5},
        {1, 2, 2},
        {1, 5, 2},
        {6, 5, 5},
        {6, 7, 3},  
    }; 
    struct Graph *myGraph = createGraph(8,0);
    for(int i=0;i<sizeof(edges)/sizeof(edges[0]);i++){
        createEdge(myGraph,edges[i][0],edges[i][1],edges[i][2]);
    }
    printAdjMatrix(myGraph);
    printf("\n");

    // QueuePtr BFSQueue = createQueue();
    // int *visited = malloc(sizeof(int)*(myGraph->n));
    // memset(visited,0,sizeof(int)*(myGraph->n));
    // // graphBFS(myGraph,3,BFSQueue,visited);
    // StackPtr nodesOnStack = createStack();
    // detect_cycle(myGraph,3,nodesOnStack,visited);
    dijkstra(myGraph,3);


}