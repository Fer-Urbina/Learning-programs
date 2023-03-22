/*
For example, 2 is written as II in Roman numeral, just two ones added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999]. In C++
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    // Create a map that maps Roman numerals to integer values
    unordered_map<char, int> roman_to_int = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    // Initialize result to 0
    int result = 0;

    // Iterate through the characters in the string
    for (int i = 0; i < s.length(); i++) {
        // If the current character is greater than or equal to the next character,
        // add its integer value to result
        if (i == s.length() - 1 || roman_to_int[s[i]] >= roman_to_int[s[i + 1]]) {
            result += roman_to_int[s[i]];
        }
        // If the current character is less than the next character,
        // subtract its integer value from result
        else {
            result -= roman_to_int[s[i]];
        }
    }

    return result;
}

int main() {
    cout << romanToInt("III") << endl;       // Outputs: 3
    cout << romanToInt("LVIII") << endl;     // Outputs: 58
    cout << romanToInt("MCMXCIV") << endl;   // Outputs: 1994
    return 0;
}