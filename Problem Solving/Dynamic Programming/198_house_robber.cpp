class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        else if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> memo(nums.size(),0);
        for(int i=0;i<2;i++){
            memo[i] = nums[i];
        }
        memo[2] = memo[0] + nums[2];

        for(int i=3;i<nums.size();i++){
            if(memo[i-2]>memo[i-3]) memo[i] = memo[i-2] + nums[i];
            else memo[i] = memo[i-3] + nums[i];
        }
        
        return max(memo[nums.size()-2], memo[nums.size()-1]);
    }
};