#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	int distance[MAX], visited[MAX],parent[MAX];
	int count,mindistance,nextnode,i,j;
	for(i=1;i<=n;i++){
		distance[i]=INFINITY;
		visited[i]=-0;
		parent[i]=-1;
	}
	distance[startnode]=0;
	for(count=1;count<n;count++){
		mindistance=INFINITY;
		nextnode=-1;
		for(i=1;i<=n;i++){
			if(!visited[i] && distance[i]<mindistance){
				mindistance=distance[i];
				nextnode=i;
			}
		}
		if(nextnode==-1) break;
		visited[nextnode]=1;
		for(i=1;i<=n;i++){
			if(!visited[i] && G[nextnode][i] && G[nextnode][i] !=INFINITY){
				if(distance[nextnode] + G[nextnode][i] < distance[i]){
					distance[i]=distance[nextnode]+G[nextnode][i];
					parent[i]=nextnode;
				}
			}
		}
	}
	printf("Node\tDistance\tPath\n");
	for(i=1;i<=n;i++){
		if(i==startnode) continue;
		if(distance[i]==INFINITY){
			printf("   %d\t     INF\tNO PATH\n",i);
		} else {
			printf("   %d\t       %d\t",i, distance[i]);
			int path[MAX],k=0;
			int current=i;
			while(current!=-1){
				path[k++]=current;
					current=parent[current];
			}
			for(j=0;j<k;j++){
				printf("%d", path[j]);
				if(j!=k-1) printf("<-");
			}
			printf("\n");
		}
	}
	
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
