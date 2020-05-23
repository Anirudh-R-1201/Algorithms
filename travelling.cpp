/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int getmin(int a[],int n){
    int min = INT_MAX,minindex;
    for(int i=0;i<n;i++){
        if(min>a[i]){
            min = a[i];
            minindex = i;
        }
    }
    return minindex;
}

bool cover(bool p[],int n){
    for(int i=0;i<n;i++){
        if(p[i]==false)
            return p[i];
    }
    return true;
}

int main()
{
    
    int n;
    cout<<"Enetr no of vertices  ";
    cin>>n;
    int graph[n][n];
    bool present[n];
    for(int i =0;i<n;i++)
        present[i] =false;
        
    for(int i=0;i<n;i++){
        graph[i][i] = INT_MAX;
        for(int j=i+1;j<n;j++){
            int x;
            cout<<"weigth of edge bw "<<i+1<<" & "<<j+1<<"  ";
            cin>>x;
            graph[i][j]=(x);
            graph[j][i]=(x);
        }
    }
    int i = 0;
    while(!cover(present,n) && i<n){
        cout<<i+1<<" ";
        present[i]=true;
        int minpos = getmin(graph[i],n);
        graph[i][minpos] = INT_MAX;
        i = minpos;
    }
    return 0;
}
