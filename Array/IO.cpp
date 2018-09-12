#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<int> pointsA,pointsB;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(A[i][j])
                    pointsA.push_back(i*n+j);
                if(B[i][j])
                    pointsB.push_back(i*n+j);
            }
        }
        unordered_map<string,int> m;
        int res = 0;
        for(const auto& pA:pointsA){
            for(const auto& pB:pointsB){
                int xA = pA / n, yA = pA % n, xB = pB / n, yB = pB % n;
                string key = to_string(xA - xB) + ":" + to_string(yA - yB);
                m[key]++;
                res = max(res,m[key]);
            }
        }
        return res;
    }
};