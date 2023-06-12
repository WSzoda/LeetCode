class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lIndex = 0;
        int rIndex = nums.size() - 1;

        while (lIndex <= rIndex)
        {
            int mid = lIndex + (rIndex - lIndex) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
            {
                rIndex = mid - 1;
            }
            else
            {
                lIndex = mid + 1;
            }
        }
        return -1;
    }
};