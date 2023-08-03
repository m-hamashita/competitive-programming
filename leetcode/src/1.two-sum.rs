/*
 * @lc app=leetcode id=1 lang=rust
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (50.25%)
 * Likes:    48928
 * Dislikes: 1596
 * Total Accepted:    10.2M
 * Total Submissions: 20.3M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 *
 *
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */
struct Solution;

// @lc code=start
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        // naive solution
        // for (i, &n) in nums.iter().enumerate() {
        //     for (j, &m) in nums.iter().enumerate() {
        //         if i != j && n + m == target {
        //             return vec![i as i32, j as i32];
        //         }
        //     }
        // }
        // // You may assume that each input would have exactly one solution
        // unreachable!()

        // using hashmap solution
        use std::collections::HashMap;
        // hashmap HashMap<i32, Vec<i32>>
        let mut map = HashMap::new();
        for (i, &n) in nums.iter().enumerate() {
            map.entry(n).or_insert(vec![]).push(i as i32);
        }
        for (i, &n) in nums.iter().enumerate() {
            let m = target - n;
            if let Some(v) = map.get(&m) {
                for &j in v.iter() {
                    if i != j as usize {
                        return vec![i as i32, j];
                    }
                }
            }
        }
        unreachable!()
    }
}
// @lc code=end
