/*
 * @lc app=leetcode id=217 lang=rust
 *
 * [217] Contains Duplicate
 */

struct Solution;
// @lc code=start
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        use std::collections::HashSet;
        let mut set = HashSet::new();
        for n in nums {
            if set.contains(&n) {
                return true;
            }
            set.insert(n);
        }
        false
    }
}
// @lc code=end

// test
#[cfg(test)]
mod tests {}
