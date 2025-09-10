// Given an integer n, return a string array answer (1-indexed) where:

// answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
// answer[i] == "Fizz" if i is divisible by 3.
// answer[i] == "Buzz" if i is divisible by 5.
// answer[i] == i (as a string) if none of the above conditions are true.

// Example 1:
// Input: n = 3
// Output: ["1","2","Fizz"]

// Example 2:
// Input: n = 5
// Output: ["1","2","Fizz","4","Buzz"]

// Example 3:
// Input: n = 15
// Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

// Constraints:

// 1 <= n <= 104

#include <stdio.h>
#include <stdlib.h>
char** fizzBuzz(int n, int* returnSize) {
    char** out = malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++) {
        int curr = i + 1;
        if (curr % 3 == 0 && curr % 5 == 0) {
            out[i] = "FizzBuzz";
        } else if (curr % 3 == 0) {
            out[i] = "Fizz";
        } else if (curr % 5 == 0) {
            out[i] = "Buzz";
        } else {
            out[i] = malloc(8);
            sprintf(out[i], "%d", curr);
        }
    }
    *returnSize = n;
    return out;
}
