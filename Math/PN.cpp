class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        for(int i = 2;i <= sqrt(num);i++){
            if(num%i==0){
                if(i*i==num)
                    sum += i;
                else sum += num/i + i;
            }
        }
        return sum==num;
    }
};