class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int first = 0,second = n-1;
        while(first < second){
            if(numbers[first] + numbers[second] == target)
                return {first+1,second+1};
            else if(numbers[first] + numbers[second] > target)
                second--;
            else
                first++;
        }
        return {first+1,second+1};
    }
};