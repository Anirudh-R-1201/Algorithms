#include <limits.h> 
#include <iostream>
#include <stdio.h> 
#define V 20
  
int minDistance(int dist[], bool visited[],int n ){ 
    int min = INT_MAX, min_index; 
    for (int v = 0; v < n; v++) 
        if (visited[v] == false && dist[v] <= min){ 
            min = dist[v], min_index = v; 
        }
    return min_index; 
} 

void dijkstra(int graph[][V], int src,int n) 
{ 
    int dist[n]; 
    bool visited[n]; 
    for (int i = 0; i < n; i++){ 
        dist[i] = INT_MAX, visited[i] = false; 
    }
    dist[src] = 0; 
    for (int i = 0; i < n - 1; i++) { 
        int u = minDistance(dist, visited,n); 
        visited[u] = true; 
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
        }
    } 
    for (int i = 0; i < n; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 

int main(){
    int n ; int src;
    scanf("%d",&n);
    int graph[n][20];
    for(int i =0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j) graph[i][j] = 0;
            else{
                printf("Enter dist bw vertex %d and %d ",i,j);
                scanf("%d",&graph[i][j]);
                graph[j][i]=graph[i][j];
            }
        }
    }
    printf("\n Source : ");
   
    scanf("%d",&src);
    dijkstra(graph,src,n);
   return 0;
}