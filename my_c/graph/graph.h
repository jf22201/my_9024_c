#include "stack.h"
#define MAX_NAME_LEN 127
#include "queue.h"
#define CONNECTED 1
#define MatrixElement(pGraph,row,col) (pGraph->AdjMatrix[pGraph->n * row + col])
struct graphNode{
    char name[MAX_NAME_LEN];
    struct graphNode* next;
};

struct Graph{
    int* AdjMatrix;
    struct graphNode* pGNodes;
    int n;
    int isDirected;
};
struct Graph* createGraph(int numNodes,int isDirected);
void createEdge(struct Graph* pGraph,int fromNode,int toNode,int edge_value);
int getIndexFromRowCol (struct Graph* pGraph,int row,int col);
void deleteEdge(struct Graph* pGraph,int fromNode,int toNode,int edge_value);
void printAdjMatrix(struct Graph* pGraph);
void graphDFS(struct Graph *pGraph,int nodeNum,int* visitedArray);
void graphBFS(struct Graph *pGraph,int nodeNum, QueuePtr pQueue,int* visitedArray);
int detect_cycle(struct Graph *pGraph,int vistingNode,StackPtr nodesOnStack,int* visited);
typedef struct Graph * GraphPtr;
