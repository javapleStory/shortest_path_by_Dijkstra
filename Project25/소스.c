#include <stdio.h>
#define Max_vert 7
#define INF 1000

int weight[Max_vert][Max_vert] = {
	{0, 7, INF, INF, 3, 10, INF},
	{7, 0, 4, 10, 2, 6, INF},
	{INF, 4, 0, 2, INF, INF, INF},
	{INF, 10, 2, 0, 11, 9, 4},
	{3, 2, INF, 11, 0, INF, 5},
	{10, 6, INF, 9, INF, 0, INF},
	{INF, INF, INF, 4, 5, INF, 0}
};

int distance[Max_vert];
int found[Max_vert];

int choose(int distance[], int n, int found[])
{
	int min, minpos;
	min = INF;
	minpos = -1;
	for (int i = 0; i < n; i++)
	{
		if (min > distance[i] && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void shortest_path(int start, int n)
{
	for (int i = 0; i < n; i++)
	{
		found[i] = 0;
		distance[i] = weight[start][i];
	}

	found[start] = 1;
	distance[start] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int u = choose(distance, n, found);
		found[u] = 1;

		for (int k = 0; k < n; k++)
		{
			if (!found[k] && (distance[u] + weight[u][k] < distance[k]))
			{
				distance[k] = distance[u] + weight[u][k];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("< %d > ", distance[i]);
	}
	printf("\n");
}

int main()
{
	shortest_path(0, Max_vert);

	return 0;
}