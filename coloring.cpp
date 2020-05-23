/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class graph{
  int v;
  std::vector<int> *adj ;
  public:
  graph(int V);
  void addv(int a ,int b);
  void colour(int n);
};

graph::graph(int V){
    this->v = V;
    adj = new vector<int>[V];
}

void graph::addv(int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int minpallet(bool used[],int n){
    for(int i=0;i<n;i++){
        if(used[i])
            return i;
    }
}

void graph::colour(int n){
 //   int pallet[n];
    bool used[n][n],visited[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            used[i][j] =true;
        }
    }
    int st = 0;
    for(int i = 0;i<n;i++){
        vector<int>::iterator it;
        for(it = adj[i].begin();it!=adj[i].end();it++){
            used[*it][minpallet(used[i],n)] = false;
        }
    }
    for(int i=0;i<n;i++)
        cout<<i<<":"<<minpallet(used[i],n)<<" ";
}


int main(){
    int n;
    cin>>n;
    graph g(n);
    int a=1;int x,y;
    while(a==1){
        cout<<"Enter vertices  ";
        cin>>x>>y;
        g.addv(x,y);
        cout<<"More? 1/0 ";
        cin>>a;
    }
    g.colour(n);
    return 0;
}
