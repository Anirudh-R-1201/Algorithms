/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#define V 20

int bfs(int graph[][V],int s,int t,int parent[],int n){
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    
    visited[s] = true;
    parent[s] = -1;
    queue<int> q ;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[u][i]){
                visited[i] = true;
                parent[i] = u;
                q.push(i);
            }
        }
    }
    if(visited[t]) return 1;
    else return 0;
}


void dfs(int graph[][V],int s, bool visited[],int n){
    visited[s]=true;
    for(int i=0;i<n;i++){
        if(graph[s][i]>0 && !visited[i])
            dfs(graph,i,visited,n);
    }
}

void mincut(int graph[][V],int s,int t,int n){
    int temp[n][V];
    bool visited[n];
    int parent[n];
    for(int i =0;i<n;i++){
        visited[i] =false;
        parent[i] = -1;
        for(int j=0;j<n;j++){
            temp[i][j] = graph[i][j];
        }
    }
    
    while(bfs(temp,s,t,parent,n)){
        int minflow = INT_MAX;
        
        for(int i = t;i!=s;i=parent[i]){
            minflow = min(minflow,temp[parent[i]][t]);
        }
        for(int i = t;i!=s;i=parent[i]){
            temp[parent[i]][i] -= minflow;
        }
    }
    
    for(int i =0;i<n;i++){
        visited[i] =false;
    }
    
    dfs(temp,s,visited,n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i]&&!visited[j])
                cout<<i<<" - "<<j<<endl;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int graph[n][V];
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
    int a = 1;
    int x,y,w;
    while(a==1){
        cout<<"Enetr vertexes : ";
        cin>>x>>y;
        cout<<"Enter weight :";
        cin>>w;
        graph[x-1][y-1] = w;
        cout<<"Add more? 1/0 ";
        cin>>a;
    }
    cout<<"Enter s and t ";
    int s,t;
    cin>>s>>t;
    mincut(graph,s,t,n);
    return 0;
}
