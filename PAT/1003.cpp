#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n,m,start,terminal;
int dist[501],team[501],graph[501][501];
int sumRoad[501],sumTeam[501];
bool visit[501];

int main(){
    cin>>n>>m>>start>>terminal;
    for(int i = 0;i < n;i++)
        cin>>team[i];
    fill(dist,dist+501,INT_MAX);
    fill(graph[0],graph[0]+501*501,INT_MAX);
    fill(sumRoad,sumRoad+501,0);
    fill(sumTeam,sumTeam+501,0);
    fill(visit,visit+501,false);
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b] = graph[b][a] = c;
    }
    dist[start] = 0;
    sumTeam[start] = team[start];
    sumRoad[start] = 1;
    for(int i = 0;i < n;i++){
        int u = -1,minDis = INT_MAX;
        for(int j = 0;j < n;j++){
            if(!visit[j] && dist[j] < minDis){
                u = j;
                minDis = dist[j]; 
            }
        }
        if(u==-1) break;
        visit[u] = true;
        for(int v = 0;v < n;v++){
            if(!visit[v] && graph[u][v] != INT_MAX){
                if(dist[u]+graph[u][v] < dist[v]){
                    dist[v] = dist[u]+graph[u][v];
                    sumRoad[v] = sumRoad[u];
                    sumTeam[v] = sumTeam[u] + team[v];
                }
                else if(dist[u]+graph[u][v] == dist[v]){
                    sumRoad[v] += sumRoad[u];
                    if(sumTeam[u] + team[v] > sumTeam[v])
                        sumTeam[v] = sumTeam[u] + team[v];
                }
            }
        }
    }
    cout<<sumRoad[terminal]<<" "<<sumTeam[terminal];
    return 0;
}