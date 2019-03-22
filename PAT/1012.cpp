#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    map<int,vector<string> > C;
    map<int,vector<string> > M;
    map<int,vector<string> > E;
    map<int,vector<string> > A;
    string id;
    int c,_m,e;
    for(int i = 0;i < n;i++){
        cin>>id;
        cin>>c>>_m>>e;
        C[c].push_back(id);
        M[_m].push_back(id);
        E[e].push_back(id);
        A[(c+_m+e)/3].push_back(id);
    }
    map<string,vector<int> >  mp;
    int rank = 1;
    for(auto it = A.rbegin();it != A.rend();it++){
        for(int i = 0;i < it->second.size();i++)
            mp[it->second[i]].push_back(rank);
        rank += it->second.size();
    }
    rank = 1;
    for(auto it = C.rbegin();it != C.rend();it++){
        for(int i = 0;i < it->second.size();i++)
            mp[it->second[i]].push_back(rank);
        rank += it->second.size();
    }
    rank = 1;
    for(auto it = M.rbegin();it != M.rend();it++){
        for(int i = 0;i < it->second.size();i++)
            mp[it->second[i]].push_back(rank);
        rank += it->second.size();
    }
    rank = 1;
    for(auto it = E.rbegin();it != E.rend();it++){
        for(int i = 0;i < it->second.size();i++)
            mp[it->second[i]].push_back(rank);
        rank += it->second.size();
    }

    vector<char> temp = {'A','C','M','E'};
    for(int i = 0;i < m;i++){
        string t;
        cin>>t;
        if(!mp.count(t))
            cout<<"N/A"<<endl;
        else{
            int index = -1;
            int minRank = INT_MAX;
            for(int j = 0;j < mp[t].size();j++){
                if(mp[t][j] < minRank){
                    index = j;
                    minRank = mp[t][j];
                }
            }
            cout<<minRank<<" "<<temp[index]<<endl;
        }
    }
    return 0;
}