#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> pre;
vector<int> mid;


struct  Node
{
    int val;
    Node* left;
    Node* right;
};

Node* buildTree(int pl,int pr,int ml,int mr){
    if(pl == pr)
        return NULL;
    Node* root = new Node;
    root->val = pre[pl];
    int i = ml;
    while(i < mr){
        if(mid[i] == pre[pl])
            break;
        i++;
    }
    int len = i-ml;
    root->left = buildTree(pl+1,pl+len+1,ml,i);
    root->right = buildTree(pl+len+1,pr,i+1,mr);
    return root;
}

void printNode(Node* root,int num){
    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i < n;i++){
            Node* t = q.front();
            q.pop();
            cout<<t->val;
            cnt++;
            if(cnt == num)
                cout<<endl;
            else 
                cout<<" ";
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int i = 0;
    int tmp;
    while(i < n){
        cin>>tmp;
        pre.push_back(tmp);
        i++;
    }
    i = 0;
    while(i < n){
        cin>>tmp;
        mid.push_back(tmp);
        i++;
    }
    Node* root = buildTree(0,n,0,n);
    printNode(root,n);
    return 0;
}
