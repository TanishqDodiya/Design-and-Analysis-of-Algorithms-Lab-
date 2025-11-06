#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N
int main() {
	int n, e;
	int dist[MAX_N][MAX_N];

	
	printf("Enter the number of vertices : ");
	scanf("%d", &n);

	printf("Enter the number of edges : ");
	scanf("%d", &e);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = (i == j) ? 0 : INF;

	for (int i = 0; i < e; i++) {
	int u, v, w;
		printf("Enter source : ");
		scanf("%d", &u);
		printf("Enter destination : ");
		scanf("%d", &v);
		printf("Enter weight : ");
		scanf("%d", &w);
		dist[u - 1][v - 1] = w; 
	}


	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];


	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == INF)
				printf("%5s", "INF");
			else
				printf("%5d", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}

