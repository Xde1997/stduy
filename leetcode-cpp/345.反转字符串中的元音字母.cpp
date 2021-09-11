/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include <set>
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
    const set<char> arr = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

public:
    string
    reverseVowels(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i <= j)
        {
            if (arr.count(s[i]))
            {
                while (!arr.count(s[j]))
                {
                    j--;
                }
                auto temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                j--;
            }
            ++i;
        }
        return s;
    }
};
// @lc code=end

// int main()
// {
//     auto s = "hello";
//     Solution solution;
//     cout << solution.reverseVowels(s);
//     system("pause");
// }