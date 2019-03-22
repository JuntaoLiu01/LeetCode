#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > tree(n+1,vector<int>(n+1,0));
    for(int i = 0;i < m;i++){
        int id,k;
        cin>>id>>k;
        for(int j = 0;j < k;j++){
            int t;
            cin>>t;
            tree[id][t] = 1;
        }
    }
    queue<int> q;
    q.push(1);
    int f = true;
    while(!q.empty()){
        int count = 0;
        int size = q.size();
        for(int i = 0;i < size;i++){
            int id = q.front();
            q.pop();
            bool hasLeaf = false;
            for(int j = 1;j <= n;j++)
                if(tree[id][j]){
                    hasLeaf = true;
                    q.push(j);
                }
            if(!hasLeaf)
                count++;
        }
        if(f){
            cout<<count;
            f = false;
        }
        else
            cout<<" "<<count;
    }
    return 0;
}