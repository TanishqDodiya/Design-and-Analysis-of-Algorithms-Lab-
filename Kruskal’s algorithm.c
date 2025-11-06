#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 9999
typedef struct{
int src;
int dest;
int weight;
}Edge;

int find(int parent[], int i) {
// Write your code here..
	if (parent[i]!=i)
		parent[i]=find(parent,parent[i]);
	return parent[i];

}


void union1(int parent[], int rank[], int i, int j) {
	int root_i=find(parent,i);
	int root_j=find(parent,j);
	if (rank[root_i]<rank[root_j])
		parent[root_i]=root_j;
	else if(rank[root_i]>rank[root_j])
		parent[root_j]=root_i;
	else{
		parent[root_j]=root_i;
		rank[root_i]++;
	}
	// Write your code here...
}
int compareEdges(const void *a, const void *b){
	const Edge *e1=(const Edge *)a;
	const Edge *e2=(const Edge *)b;
	if(e1->weight!=e2->weight)
		return e1->weight - e2->weight;
	if(e1->src!=e2->src)
		return e1->src-e2->src;
	return e1->dest-e2->dest;
}

void kruskalMST(int **cost, int V) {
	Edge edges[V * V];
	int edgeCount=0;
	int i,j;
	for(i=0;i<V;i++){
		for(j=i+1;j<V;j++){
			if(cost[i][j]!=INF){
				edges[edgeCount].src=i;
				edges[edgeCount].dest=j;
				edges[edgeCount].weight=cost[i][j];
				edgeCount++;
			}
		}
	}
	qsort(edges,edgeCount,sizeof(Edge),compareEdges);
	int parent[V],rank[V];
	for(i=0;i<V;i++){
		parent[i]=i;
		rank[i]=0;
	}
	int totalCost=0;
	int edgesUsed=0;
	int edgeIndex=0;
	while(edgesUsed < V -1 && edgeIndex < edgeCount){
		Edge e=edges[edgeIndex++];
		int set_u=find(parent,e.src);
		int set_v=find(parent,e.dest);
		if(set_u!=set_v){
			printf("Edge %d:(%d, %d) cost:%d\n", edgesUsed,e.src,e.dest, e.weight);
			totalCost+=e.weight;
			union1(parent,rank,set_u,set_v);
			edgesUsed++;
		}
	}
	printf("Minimum cost= %d\n",totalCost);

	// Write your code here...
	
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
