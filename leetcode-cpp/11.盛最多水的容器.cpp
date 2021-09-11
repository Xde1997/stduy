/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int s = 0;
        while (i < j)
        {
            s = s > (j - i) * min(height[j], height[i]) ? s : (j - i) * min(height[j], height[i]);
            if (height[i] < height[j])
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        return s;
    }
};
// @lc code=end
