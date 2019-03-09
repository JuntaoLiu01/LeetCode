class Solution {
public:
    int father[26];
    void init(){
        for(int i = 0;i < 26;i++)
            father[i]=i;
    }
    int root(int a){
        if(father[a]==a)
            return a;
        return root(father[a]);
    }
    void join(int a,int b){
        int ra=root(a);
        int rb=root(b);
        father[rb] = ra;
    }
    bool equationsPossible(vector<string>& equations) {
        init();
        for(auto str:equations){
            if(str[1]=='=')
                join(str[0]-'a',str[3]-'a');
        }
        for(auto str:equations){
            if(str[1]=='!'){
                if(root(str[0]-'a')==root(str[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};