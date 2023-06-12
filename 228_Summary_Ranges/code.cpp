class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int start = 0;
        int end = 0;
        if(nums.size() == 0){
            return result;
        }

        for(int i = 0; i <= nums.size(); i++){
            if (i != nums.size() && (nums[end] + 1 == nums[i] || nums[end] == nums[i]))
                end = i;
            else {
                if(start == end)
                    result.push_back(to_string(nums[start]));
                else
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                
                start = i;
                end = i;
            }
        }
        return result;
    }
};