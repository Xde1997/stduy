/*
 * @lc app=leetcode.cn id=658 lang=rust
 *
 * [658] 找到 K 个最接近的元素
 */

pub struct Solution {}

// @lc code=start
impl Solution {
    pub fn find_closest_elements(arr: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
        arr.sort_by(|a, b| {
            (a - x).abs().cmp((b - x).abs()) || ((a - x).abs() == (b - x).abs() && a < b);
        });
        arr[0..k as usize].to_vec()
    }
}
// @lc code=end
