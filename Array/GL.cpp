#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        int dx[8] = {-1,-1,-1,0, 0,1,1,1};
        int dy[8] = {-1, 0,1, -1,1,-1,0,1};
        for(int i = 0; i <  board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                int cnt = 0;
                for(int k = 0;k < 8;k++){
                    int x = i+dx[k],y = j+dy[k];
                    if(x>=0 && x<board.size() && y>=0 && y<board[0].size()){
                        if(board[x][y] == 1 || board[x][y] == 2)
                            cnt++;
                    }
                }
                if(board[i][j] && (cnt<2 || cnt>3))
                    board[i][j] = 2;
                if(!board[i][j] && cnt == 3)
                    board[i][j] = 3;
            }
        }
        for(int i = 0;i < board.size();i++)
            for(int j = 0;j < board[0].size();j++)
                board[i][j] %= 2;
    }
};