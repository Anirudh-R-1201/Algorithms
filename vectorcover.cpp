#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    vector<int> *adj;
    public:
    graph(int V);
    void addvertex(int a,int b);
    void vetexcover();
};

graph::graph(int V){
    this->v = V;
    adj = new vector<int>[V];
}

void graph::addvertex(int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void graph::vetexcover(){
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
        
    vector<int>::iterator it;
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            for(it = adj[i].begin();it!=adj[i].end();++it){
                int j = *it;
                if(!visited[j]){
                    visited[i] = true;
                    visited[j] = true;
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        if(visited[i]==true) printf("\t%d",i);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    graph g(n); int a=1;
    
            while(a==1){
                int x,y;
                printf("Enetr vertexes : ");
                scanf("%d%d",&x,&y);
                g.addvertex(x,y);
                printf("\nAdd more? 1/0 :");
                scanf("%d",&a);
            }
        
    g.vetexcover();
    return 0;
}

