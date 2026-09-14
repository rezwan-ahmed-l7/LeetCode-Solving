class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<vector<int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            int end = jobs[i][0];
            int start = jobs[i][1];
            int p = jobs[i][2];
            
            int skip = dp[i];
            
            int low = 0, high = i - 1, j = -1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(jobs[mid][0] <= start) {
                    j = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            int take = p;
            if(j != -1) {
                take += dp[j + 1];
            }
            
            dp[i + 1] = max(skip, take);
        }
        
        return dp[n];
    }
};