/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <string>
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int size = s.length();
        // int i = 0;
        // for (i = 0; i * k * 2 < size; i++)
        // {
        //     reverse(s.begin() + i * k * 2, s.begin() + i * k * 2 + k);
        // }
        // if ((size - i * k * 2 - 1) >= k)
        // {
        //     reverse(s.begin() + i * k * 2, s.begin() + i * k * 2 + k);
        // }
        // if ((size - i * k * 2 - 1) < k)
        // {
        //     reverse(s.begin() + i * k * 2, s.begin() + size);
        // }
        // return s;
        for (int i = 0; i < size; i += 2 * k)
        {
            reverse(s.begin() + i, s.begin() + min(i + k, size));
        }
        return s;
    }
};
// @lc code=end
