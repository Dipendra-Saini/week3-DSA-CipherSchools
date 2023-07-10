#include "bits/stdc++.h"
using namespace std;

//DAG Theory

//Bipartite graph
bool colorGraph(int G[][V],int color[],int pos, int c){

    if(color[pos] != -1 && color[pos] !=c)
        return false;
    color[pos] = c;
    bool ans = true;
    for(int i=0;i<V;i++){
        if(G[pos][i]){
            if(color[i] == -1)
                ans &= colorGraph(G,color,i,1-c);

            if(color[i] !=-1 && color[i] != 1-c)
                return false;
        }
        if (!ans)
            return false;
    }

    return true;
}

bool isBipartite(int G[][V]){
    int color[V];
    for(int i=0;i<V;i++)
        color[i] = -1;
    int pos = 0;
    return colorGraph(G,color,pos,1);

}

int main(){
    cout<<"Nice approach"<<endl;
    return 0;
}