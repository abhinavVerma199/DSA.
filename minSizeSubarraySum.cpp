class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int e = 0;
        int len = INT_MAX;
        int sum = 0;

        while( e < nums.size()) {
            //sum me include karo value
            sum = sum + nums[e];
            //ho skta hai, sum == target ho
            //ho skta hai sum > target ho
            //ho skta hai, sum < target

            //minimise -> equal or greater
            //explore -> lesser
            while(sum >= target) {
                //minimise
                len = min(len , e-s+1);
                //current element, pointed by start, should be removed fro sum 
                sum = sum - nums[s];
                s++;
            }
            
            //loop se bahar matalba, guarantee -> sum < target
            //explore
                e++;
        }
        if(len == INT_MAX) {
            return 0;
        }
        else {
            return len;
        }
        
    }
};