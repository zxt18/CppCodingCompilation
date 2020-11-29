#include <bits/stdc++.h>


using namespace std;

void dfs(int);


static vector<int> graphs [100000];
static int count=0;
static int cost=0;
static bool visit[100000];

int roadsAndLibraries(int n, int m, int c_lib, int c_road){


    ;
    if(c_lib<=c_road || m==0){
        cost=n*c_lib;
    }

    else{
        for(int i=1; i<n+1; i++){
            if(!vis[i]){
                count=0;
                dfs(i);
                cost+=c_lib + ((count-1)*c_road);
            }
        }
    }
    return cost;
}

void dfs(int node){
    visited[node]=true;
    count++
    cout<<"Node now is "<<node<<"  ";

    for(auto i : adj[node]){
        if(!visited[node])
        dfs(i);
    }

}
