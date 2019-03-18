class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        if(n1 < n2){
            sort(nums2.begin(),nums2.end());
            for(int i = 0;i < n1;i++){
                int l = 0,r = nums2.size()-1;
                while(l <= r){
                    int m = (l+r)/2;
                    if(nums2[m] == nums1[i]){
                        res.push_back(nums1[i]);
                        nums2.erase(nums2.begin()+m);
                        break;
                    }
                    else if(nums2[m] < nums1[i])
                        l = m + 1;
                    else 
                        r = m - 1;
                }
            }
        }
        else
        {
            sort(nums1.begin(),nums1.end());
            for(int i = 0;i < n2;i++){
                int l = 0,r = nums1.size()-1;
                while(l <= r){
                    int m = (l+r)/2;
                    if(nums1[m] == nums2[i]){
                        res.push_back(nums2[i]);
                        nums1.erase(nums1.begin()+m);
                        break;
                    }
                    else if(nums1[m] < nums2[i])
                        l = m + 1;
                    else 
                        r = m - 1;
                }
            }
        }
        return res;       
    }
};