// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

// Example 1:
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:
// Input: nums = [5], k = 1
// Output: 5.00000

// Constraints:
// n == nums.length
// 1 <= k <= n <= 105
// -104 <= nums[i] <= 104

double findMaxAverage(int* nums, int numsSize, int k) {
    // Some answers doesn't even use the traditional right/left approach,
    // but I found it hard to read. Also, it seems to be common to use
    // curr or ans as a variable's name. I don't see why writting like
    // that would help in any form.
    int sum = 0;
    int right = 0;
    int left = 0;

    // I removed the first for-loop expression willingly. This is also the
    // correct approach when an expression doesn't do anything meaningfull.
    for (; right < k; right++) {
        sum += nums[right];
    }

    int max_sum = sum;

    // Same here
    for(; right < numsSize; right++, left++) {

        sum = sum + nums[right] - nums[left];
        // It may seem contraditory, but I find ternary operators a very good
        // and concise approach in this particular situation.
        max_sum = sum > max_sum ? sum : max_sum;

    }
    return (double) max_sum / k;
}

// Notes:
// First, I tried to compute the average inside the loop. That didn't work at all.
// Some tests was passing, but there was too much "edge cases" that it suggested
// the approach just wasn't good enough.
// Then I reviewed the material and peeked the LeetCode's python solution, that
// suggested something very simple (but cryptic; they don't use meaningfull variable's
// names).
// I was stuck in this problem and the gave up (this is ok, it's 1:30AM), proceeding to
// check Gemini and the best solutions submitted to LeetCode.
// Maybe I just need practice... or sleep.
