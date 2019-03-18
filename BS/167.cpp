class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0;i < n-1;i++){
            int l = i+1,r = n-1,t = target-numbers[i];
            while(l <= r){
                int m = (l+r)/2;
                if(numbers[m]==t)
                    return {i+1,m+1};
                else if(numbers[m] < t)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return {1,n};
    }
};