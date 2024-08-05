#include <stdio.h>
#include "graph.h"
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
struct Graph* createGraph(int numNodes,int isDirected){
    struct Graph* pGraph = (struct Graph*) malloc(sizeof(struct Graph));
    pGraph->n = numNodes;
    pGraph->AdjMatrix = (int*) malloc(sizeof(int) * pGraph->n * pGraph->n);
    pGraph->isDirected=isDirected;
    memset(pGraph->AdjMatrix,0,sizeof(int) * pGraph->n * pGraph->n);
    return pGraph;
    
}

void createEdge(struct Graph* pGraph,int fromNode,int toNode,int edge_value){
    *(pGraph->AdjMatrix+getIndexFromRowCol(pGraph,fromNode,toNode)) = edge_value;
    if(!pGraph->isDirected){
        pGraph->AdjMatrix[getIndexFromRowCol(pGraph,toNode,fromNode)] = edge_value;
    }
}

int getIndexFromRowCol (struct Graph* pGraph,int row,int col){
    return row*(pGraph->n) + col;
}

void deleteEdge(struct Graph* pGraph,int fromNode,int toNode,int edge_value){
    pGraph->AdjMatrix[getIndexFromRowCol(pGraph,fromNode,toNode)] = 0;
    if(!pGraph->isDirected){
        pGraph->AdjMatrix[getIndexFromRowCol(pGraph,toNode,fromNode)] = 0;
    }
}

void printAdjMatrix(struct Graph* pGraph){
    for(int i=0;i<(pGraph->n)*(pGraph->n);i++){
        if(i%pGraph->n == 0){
        printf("\n %d ",pGraph->AdjMatrix[i]);
        }
        else{
            printf("%d ",pGraph->AdjMatrix[i]);
        }
    } 
}

void graphDFS(struct Graph *pGraph,int nodeNum,int* visitedArray){
    //set the node we are visitng as visited on the array
    visitedArray[nodeNum] = 1;
    printf("visiting node %d \n",nodeNum);
    for(int u=0;u<pGraph->n;u++){
        if(pGraph->AdjMatrix[getIndexFromRowCol(pGraph,nodeNum,u)] != 0 && visitedArray[u] != 1){
            graphDFS(pGraph,u,visitedArray);
        }
    }
    

    }

void graphBFS(struct Graph *pGraph,int nodeNum, QueuePtr pQueue,int* visitedArray){
    enqueue(pQueue,nodeNum);
    while(!isQueueEmpty(pQueue)){
       int currNode = dequeue(pQueue);
       if (visitedArray[currNode] != 1){
        visitedArray[currNode] = 1;
        printf("visting node %d\n",currNode);
       }
       for (int u = 0;u<pGraph->n;u++){
        if(pGraph->AdjMatrix[getIndexFromRowCol(pGraph,currNode,u)] != 0 && visitedArray[u] != 1){
            enqueue(pQueue,u);
        }
       }

    }

}


void printStackNodes(StackPtr pStack,int n){
    StackNodePtr currNode=  pStack->LLHeadNodePtr;
    int count = 0;
    printf("cycle of length %d\n",n);
    while(count<n){
    printf("%d\n",currNode->value);
    currNode = currNode->nextNode;
    count++;
    }
}

int getNumNodesInCycle(int cycleEndNode,struct Graph *pGraph,StackPtr nodesOnStack){
    int counter = 0;
    int currValue;
    StackNodePtr currNode = nodesOnStack->LLHeadNodePtr;
    do{
        currValue = currNode->value;
        currNode = currNode->nextNode;
        counter++;
    }while(currValue != cycleEndNode && currNode);
    if(currValue == cycleEndNode){
        return counter;
    }
    return 0;
}



int detect_cycle(struct Graph *pGraph,int vistingNode,StackPtr nodesOnStack,int* visited){
    pushStack(nodesOnStack,vistingNode);
    for(int v=0;v<pGraph->n;v++){
        if(visited[v]!=1 && pGraph->AdjMatrix[getIndexFromRowCol(pGraph,vistingNode,v)] != 0){
            int numNodesInCycle = getNumNodesInCycle(v,pGraph,nodesOnStack);
            if(numNodesInCycle == 0){
                detect_cycle(pGraph,v,nodesOnStack,visited);
            }
            else if(numNodesInCycle==2 && !pGraph->isDirected){
                continue;
            }
            else{
                printStackNodes(nodesOnStack,numNodesInCycle);
            }
        }
    }
    visited[vistingNode] = 1;
    popStack(nodesOnStack);
}



