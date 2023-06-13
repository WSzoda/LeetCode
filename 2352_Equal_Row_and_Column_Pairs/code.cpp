class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int counter = 0;
        for (int rowMain = 0; rowMain < grid.size(); rowMain++)
        {
            for (int rowSecond = 0; rowSecond < grid.size(); rowSecond++)
            {
                bool Equal = true;
                for (int col = 0; col < grid.size(); col++)
                {
                    if (grid[col][rowSecond] != grid[rowMain][col])
                    {
                        Equal = false;
                    }
                }
                if (Equal)
                    counter++;
            }
        }
        return counter;
    }
};