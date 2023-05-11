/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3.
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s
*/

#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) {
    int end = s.length() - 1;
    while (end >= 0 && s[end] == ' ') end--;
    if(end < 0) return 0;
    int start = end;
    while (start >= 0 && s[start] != ' ') start--;
    return end - start;
}

int main ()
{
    std::string str1 = "Hello World";
    std::string str2 = "Fly me to the moon";
    std::string str3 = "luffy is still joyboy";
 
    std::cout << "Length of last word in \"" << str1 << "\": " << lengthOfLastWord(str1) << std::endl;
    std::cout << "Length of last word in \"" << str2 << "\": " << lengthOfLastWord(str2) << std::endl;
    std::cout << "Length of last word in \"" << str3 << "\": " << lengthOfLastWord(str3) << std::endl;

    return 0;
}