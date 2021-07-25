class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()>1){
        int index = min_element(nums, target);
         if(index == -1) return -1;
         if(nums[index]==target) return index;
         int res1 = binary_search(nums,0,index,target);
         int res2 = binary_search(nums,index+1,nums.size()-1, target);
         if(res1!=-1) return res1;
         if(res2!=-1) return res2; 
        }else{
            return nums[0] == target? 0 : -1;
        }
        return -1;
    }
    int binary_search(vector<int>& nums, int start, int end, int target){
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid]==target) 
                return mid;
            else if(nums[mid]<target)
                start = mid+1;
            else 
                end = mid-1;
        }
        return -1;
    }
    
    int min_element(vector<int>& nums, int target){
        int N = nums.size();
        int start = 0;
        int end = N-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            int prev = (mid-1+N)%N;
            int next = (mid+1)%N;
            
            if(nums[prev]==target) return prev;
            if(nums[mid]==target) return mid;
            if(nums[next]==target) return next;
            
            if(nums[prev]>=nums[mid] && nums[mid]<=nums[next]){
                return mid;
            }
            
            if(nums[mid]>=nums[end]){
                start = mid+1;
            }else {
                end = mid-1;
            }
        }
        return -1;
    }
};