#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include <string.h>



void dijkstra(GraphPtr pGraph,int startNode){
    int visitedArr[pGraph->n];
    memset(visitedArr,0,sizeof(int)*pGraph->n);
    int distanceArr[pGraph->n];
    //set all the values to INF
    for(int i=0;i<pGraph->n;i++){
        distanceArr[i] = INF;
    }
    int viaArr[pGraph->n];
    memset(viaArr,0,sizeof(int)*pGraph->n);
    //set the distance to the startNode to 0 and its via value to itself
    distanceArr[startNode] = 0;
    viaArr[startNode] = startNode;
    for(int i = 0;i<pGraph->n;i++){
        int visitingNode = findShortestDistNode(pGraph,distanceArr,visitedArr);
        if(visitingNode==-1){
            //if no valid node to visit exists
            continue;
        }
        visitedArr[visitingNode] = 1;
        for(int v=0;v<pGraph->n;v++){
            if(MatrixElement(pGraph,visitingNode,v) != 0 && (distanceArr[visitingNode] + MatrixElement(pGraph,visitingNode,v))<distanceArr[v]){
                distanceArr[v] = distanceArr[visitingNode] + MatrixElement(pGraph,visitingNode,v);
                viaArr[v] = visitingNode;
            }
        }
    }
    //printing out result
    for(int i=0;i<pGraph->n;i++){
        printf("shortest path from node %d to node %d is %d via %d\n",startNode,i,distanceArr[i],viaArr[i]);
    }
        

}

int findShortestDistNode(GraphPtr pGraph,int* distanceArr,int* visitedArr){
    //find shortest distance node that has yet to be visited
    int returnNode=-1;
    int currMin = INF;
    for(int i=0;i<pGraph->n;i++){
        if(distanceArr[i] < currMin && visitedArr[i] != 1){
            returnNode = i;
            currMin = distanceArr[i];
        }
        }
    return returnNode;
}



   