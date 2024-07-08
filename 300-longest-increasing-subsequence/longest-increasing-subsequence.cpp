class Solution { // 256 ms, faster than 42.84%
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n, 1);
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < i; j++)
        //         if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
        //             dp[i] = dp[j] + 1;
        // return *max_element(dp.begin(), dp.end());
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

