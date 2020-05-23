/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<bits/stdc++.h>
#include <iostream>

using namespace std;
void fintwt(int n ,int t[],int wt[],int quantum){
    int rem_t[n],clk = 0;
    for(int i=0;i<n;i++){
        rem_t[i] = t[i];
    }
    
    while(1){
        bool done = true;
        for(int i = 0;i<n;i++){
            if(rem_t[i]>0){
                done = false;
                if(rem_t[i]>quantum){
                    clk+=quantum;
                    rem_t[i] -=quantum;
                }
                else{
                    clk+=rem_t[i];
                    rem_t[i] = 0;
                    wt[i] = clk - t[i];
                }
            }
        }
        if(done == true) break;
    }
}

void finttat(int n,int t[],int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i] = t[i] + wt[i];
    }
}


void findavgtime(int n, int t[], int quantum){
    int wt[n],tat[n],totalwt=0,totaltat=0;
    fintwt(n,t,wt,quantum);
    finttat(n,t,wt,tat);
    for(int i=0;i<n;i++){
        cout<<i<<" "<<t[i]<<" "<<wt[i]<<" "<<tat[i]<<endl;
        totalwt+=wt[i];
        totaltat+=tat[i];
    }
    cout<<"\n"<<float(totalwt)/float(n)<<"\t"<<float(totaltat)/float(n);
}

int main()
{
    int n;
    cout<<"Process #s ";
    cin>>n;
    int t[n];
    cout<<"\nBust times ";
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    int quantum;
    cout<<"Quantunm ";
    cin>>quantum;
    findavgtime(n,t,quantum);
    return 0;
}
