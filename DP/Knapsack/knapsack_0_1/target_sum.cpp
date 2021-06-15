int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        int count = 0;
        for(int x : nums){
            sum+=x;
            if(x == 0) count++;
        }
        if(S>sum){
            return 0;
        }
        if((S+sum)%2!=0){
            return 0;
        }
        return subsetSum(nums,(S+sum)/2, count);
    }
    
    int subsetSum(vector<int>& nums, int S, int c){
        int t[nums.size()+1][S+1];
        
        for(int i=0; i < S+1; i++){
            t[0][i] = 0;
        }
        for(int i=0; i < nums.size()+1; i++){
            t[i][0] = 1;
        }
        
        for(int i=1; i<nums.size()+1; i++){
            for(int j = 1; j < S+1; j++){
                if(nums[i-1] == 0){
                    t[i][j] = t[i-1][j];
                }
                else if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return pow(2,c)*t[nums.size()][S];
        
    }

    int main(){
        //494. Target Sum
        //https://leetcode.com/problems/target-sum/
        vector<int> nums = {1, 1, 1, 1, 1};
        int sum = 3;
        findTargetSumWays(nums,sum)
    }