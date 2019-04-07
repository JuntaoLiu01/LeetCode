class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<vector<int> > prev;
        int now = 0;
        sort(clips.begin(),clips.end());
        for(int i = 0;i < clips.size();i++){
            if(clips[i][0] > now)
                return -1;
            if(clips[i][1] <= now)
                continue;
            for(int j = prev.size()-1;j >= 0;j--){
                if(clips[i][0] == prev[j][0])
                    prev.pop_back();
                else if(j > 0 && clips[i][0] <= prev[j-1][1])
                    prev.pop_back();
            }
            prev.push_back(clips[i]);
            now = clips[i][1];
            if(now >= T)
                return prev.size();
        }
        return -1;
    }
};