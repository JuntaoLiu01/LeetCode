class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(),n = nums[0].size();
        if(!r || !c || m*n != r*c)
            return nums;
        vector<vector<int> > res(r,vector<int>(c));
        int a = 0,b = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                res[a][b++] = nums[i][j];
                if(b == c){
                    a += 1;
                    b = 0;
                }
            }
        }
        return res;
    }
};