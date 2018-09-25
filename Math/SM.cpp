class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int a,b;
        set<int> s;
        for(int i=0;i < n;i++){
            sum += nums[i];
            if(s.count(nums[i]))
                a = nums[i];
            s.insert(nums[i]);
        }
        b = a+n*(n+1)/2-sum;
        return {a,b};
    }
};