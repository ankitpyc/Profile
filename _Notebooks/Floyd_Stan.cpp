#include<stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 99999

#define MAX 25000
#define V 7700

typedef struct
{
    int source;
    int target;
    int weight;
}record;

static int graph[V][V] = {INF};
static record edge[MAX];
static int dist[V][V];

void printSolution(int dist[][V]);

void floydWarshall (int graph[V][V])
{
    int i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[V][V])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    FILE *fp;
    int count = 0;
    fp = fopen("soc-sign-bitcoinalpha.csv","r");
    if(fp == NULL)
    {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }
     while (fscanf(fp, "%d,%d,%d", &edge[count].source, &edge[count].target, &edge[count].weight) == 3)
     {
         count++;
     }
printf("count is %d\n",count);
     for(int i = 0; i < count; i++)
     {
         graph[edge[i].source][edge[i].target] = edge[i].weight;
     }
//printf("After forming adjacency matrix\n");
//     for(int i = 0; i < count; i++)
//     {
//        for(int j = 0; j < count; j++)
//        {
//            printf("%d ",graph[i][j]);
//        }
//        printf("\n");
//     }

    // Print the solution
    floydWarshall(graph);
    return 0;
}
