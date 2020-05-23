#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define V 20
  
void fwarshall(int graph[][V],int src,int n){
    int dist[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=graph[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++)
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
        }
    }
    for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            if(graph[i][j]==INT_MAX) printf("\t INF");
            else printf("\t%d",graph[i][j]);
        }
    }
}

int main(){
    int n ; int src;
    scanf("%d",&n);
    int graph[n][20];
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) graph[i][j] = 0;
            else{
                printf("Enter dist bw vertex %d and %d ",i,j);
                scanf("%d",&graph[i][j]);
            }
            if(i!=j && graph[i][j]==0) graph[i][j] = INT_MAX;
        }
    }
    printf("\n Source : ");
   
    scanf("%d",&src);
    fwarshall(graph,src,n);
   return 0;
}