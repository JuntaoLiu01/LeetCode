#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int res = 0;
        for(int i = 0;i < A.size()-1;i++){
            for(int j = i+1;j < A.size();j++){
                int cnt = 0;
                int num1 = A[i],num2 = A[j];
                int left = j+1,right = A.size();
                while(left < right){
                    int mid = (left+right)/2;
                    if(A[mid] == num1+num2){
                        cnt++;
                        num1 = num2,num2 = A[mid];
                        left = mid+1,right = A.size();
                    }
                    else if(A[mid] < num1+num2)
                        left = mid+1;
                    else 
                        right = mid-1;
                }
                res = max(res,cnt);
            }
            
        }
        return res==0?0:res+2;
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        int res = 0;
        unordered_map<int,int> m;
        for(int i = 0;i < n;i++)
            m[A[i]] = i;
        vector<vector<int> > dp(n,vector<int>(n,2));
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                int t = A[j]-A[i];
                if(t>=A[i])
                    continue;
                auto it = m.find(t);
                if(it != m.end()){
                    int index = it->second;
                    dp[i][j] = dp[index][i] + 1;
                    res = max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};
