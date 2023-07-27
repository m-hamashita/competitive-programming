/*
 * @lc app=leetcode id=4 lang=rust
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let len1 = nums1.len();
        let len2 = nums2.len();
        let mut index1 = 0;
        let mut index2 = 0;
        let mut index = 0;
        let mut is_even = false;
        let mut num = 0;
        let mut sum = 0;
        let mut target_index = Vec::new();

        is_even = (len1 + len2) % 2 == 0;
        if is_even {
            target_index.push((len1 + len2) / 2 - 1);
            target_index.push((len1 + len2) / 2);
        } else {
            target_index.push((len1 + len2) / 2);
        }

        while index1 < len1 || index2 < len2 {
            if index1 == len1 {
                num = nums2[index2];
                index2 += 1;
            } else if index2 == len2 {
                num = nums1[index1];
                index1 += 1;
            } else if nums1[index1] < nums2[index2] {
                num = nums1[index1];
                index1 += 1;
            } else {
                num = nums2[index2];
                index2 += 1;
            }
            if target_index.contains(&index) {
                sum += num;
            }
            index += 1;
        }
        if is_even {
            sum as f64 / 2.0
        } else {
            sum as f64
        }
    }
}
// @lc code=end
