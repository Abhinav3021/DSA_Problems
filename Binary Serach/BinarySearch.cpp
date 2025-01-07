
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid;
        while(end-start>1){
            mid=start+ (end-start)/2;
            if(nums[mid]<target){start=mid+1;}
            else{end=mid;}

        }
        if(nums[start]==target){return start;}
        else if(nums[end]==target){return end;}
        else{
            return -1;
        }
    }
};