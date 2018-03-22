#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


#define size 7605
#define start 1
#define max 200

int mindist(int distance[],int visited[]);
int printSolution(int dist[]);
void readFileandReturnGraph(int* graph);


int g[size][size]  ;
int dist[size];
int visited[size];


int main(){
		 /* Let us create the example graph discussed above */
	clock_t c_time ;
	c_time = clock();

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			g[i][j] = 0 ;
		}
	}

	readFileandMakeGraph(g);
	dijkstra(g,dist,visited);
	printSolution(dist);
	c_time = clock()-c_time;
	double time_taken = ((double)c_time)/CLOCKS_PER_SEC;
	printf("Time taken is %f\n",time_taken);
	return 0;
}

void dijkstra(int g[size][size],int dist[size],int visited[size]){

	for(int i=0;i<size;i++){
		dist[i] = max ;
		visited[i] = 0;
	}

	dist[start] = 0 ;
	//printf("%d\n",dist[start]);

	for(int i = start;i<size-1;i++){
		int u = mindist(dist,visited);
		visited[u] = 1;
		for(int j=start;j<size;j++){
			if(!visited[j] && dist[u]!=max && g[u][j]){
				if(dist[j]>dist[u]+g[u][j]) dist[j] = dist[u] + g[u][j];
			}
		}

	}
}

int mindist(int distance[],int visited[]){
	int min_index ;
	int current_min = max ;
	for(int i=start;i<size;i++){
		if(visited[i]==0 && distance[i]<=current_min){
			min_index = i ;
			current_min = distance[i];
		}
	}
	//printf("%d\n",min_index);
	return min_index;

}

void readFileandMakeGraph(int graph[size][size]){
	//int graph[size][size]

	FILE* file_pt = fopen("soc-sign-bitcoinotc.csv","r");
	char line[1024];
	while(fgets(line,1024,file_pt)){
		char* source_c ;
		char* dest_c ;
		char* weight_c ;

		char* temp = strdup(line);
		const char* tok;
 		tok = strtok(line,",");
		source_c = tok ;
		dest_c = strtok(NULL,",");
		weight_c = strtok(NULL,",");


		int source = atoi(source_c);
		int dest = atoi(dest_c);
		int weight = atoi(weight_c);
		//printf("%d\t%d\t%d\t\n",source,dest,weight);
		graph[source][dest] = weight ;
	}
}





int printSolution(int dist[])
{
   printf("NodeId   MinmumRating\n");
   for (int i = start; i < size; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
