#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool findLetter(vector<vector<char> >& board,string word,int x,int y,int index){
        if(index == word.size())
            return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return false;
        if(board[x][y] != word[index])
            return false;
        board[x][y] = '$';
        bool findNextLetter = findLetter(board,word,x-1,y,index+1) || findLetter(board,word,x+1,y,index+1) 
                                        || findLetter(board,word,x,y-1,index+1) || findLetter(board,word,x,y+1,index+1);
        board[x][y] = word[index];
        return findNextLetter;
    }
public:
    bool exist(vector<vector<char> >& board, string word) {
        if(board.size() <= 0)
            return false;
        if(board[0].size() <= 0)
            return false;
        for(int i = 0;i < board.size();i++)
            for(int j = 0;j < board[0].size();j++){
                if(findLetter(board,word,i,j,0))
                    return true;
            }
        return false;
    }
};

int main(){
    char tmp[1][1] = {{'a'}};
    vector<vector<char> > test;
    test.resize(1);
    for(int i = 0;i < 1;i++){
        test[i].resize(1);
        for(int j = 0;j < 1;j++)
            test[i][j] = tmp[i][j];
    }
    string word = "ab";
    Solution s = Solution();
    bool ret = s.exist(test,word);
    cout<<ret<<endl;
    return 0;
}