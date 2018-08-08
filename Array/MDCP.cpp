#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int ret = 0,len = 0,flag = -seats.front();
        for(int i = 0;i < seats.size();i++){
            if(seats[i] == 0)
                len++;
            else{
                flag++;
                ret = max(ret,flag==0?++len/2:len);
                flag = -1;
                len = 0;
            }
        }
        ret = max(ret,len);
        return ret;
    }
};
