/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        string s;
        char temp = chars[0];
        int index = 0;
        for (int i = 0; i < chars.size(); i++)
        {
            if (chars[i] != temp)
            {
                s.push_back(temp);
                temp = chars[i];
                if (i - index > 1)
                {
                    s.append(to_string(i - index));
                }
                index = i;
            }
        }
        s.push_back(chars[index]);
        if (chars.size() - index > 1)
        {
            s.append(to_string(chars.size() - index));
        }

        chars = vector(s.begin(), s.end());
        return s.length();
    }
};
// @lc code=end
