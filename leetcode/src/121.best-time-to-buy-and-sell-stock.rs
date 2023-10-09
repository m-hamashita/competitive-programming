/*
 * @lc app=leetcode id=121 lang=rust
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (53.49%)
 * Likes:    28621
 * Dislikes: 973
 * Total Accepted:    3.9M
 * Total Submissions: 7.2M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you
 * must buy before you sell.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit =
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 *
 *
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut minimum_price = prices[0];
        // その時点での最小値と見ている index の diff を ans と比較する
        prices.iter().skip(1).for_each(|&price| {
            ans = ans.max(price - minimum_price);
            minimum_price = minimum_price.min(price);
        });
        ans
    }
}
// @lc code=end

use rstest::rstest;
#[rstest]
// parameter test
#[case(vec![7, 1, 5, 3, 6, 4], 5)]
#[case(vec![7, 6, 4, 3, 1], 0)]
#[case(vec![1], 0)]
fn test(#[case] prices: Vec<i32>, #[case] expected: i32) {
    assert_eq!(Solution::max_profit(prices), expected);
}
