// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.

// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

// Constraints:
// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.

typedef int bool;
bool true = 1, false = 0;
// I had to add this because C does not have a native boolean type, and the
// leetcode problem assumes some standard C libraries to be automatically
// called.

bool canConstruct(char* ransomNote, char* magazine) {
    int map[26] = {0}; // this is to keep track of all the letters in the alphabet.
    for (int i = 0; magazine[i] != '\0'; i++) { // considering char* is a string, and that all strings end with '\0', I can check the end of the char*.
        map[magazine[i] - 'a']++;
        // goes to the ith element of magazine and subtracts 'a' from it.
        // This works fine because C assumes char as their ASCII values
        // specially in the context of arithmetic operations.
    }
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (map[ransomNote[i] - 'a'] == 0) return false;
        map[ransomNote[i] - 'a']--;
    }
    return true;
}

// I wish I could check if ransomNote is bigger than magazine after iteratin over them,
// but the very act of checking would be iterative, so it would reduce performance and
// increase time complexity...
//
// This was a hard one for me, because I had to study what really is a hash table.
// I have taken some notes, here saved as in 383.pdf.
//
// Not all of that note relate to this problem, but it was fun to learn, so be it.
