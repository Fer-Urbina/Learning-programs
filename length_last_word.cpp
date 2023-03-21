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
    int space_pos = s.find_last_not_of(' ');
    if (space_pos == std::string::npos)
    {
        return s.length();
    }

    std::string last_word = s.substr(space_pos+1);
    return last_word.length();

    }

int main ()
{
    std::string s = "Hello World";
    int len = lengthOfLastWord(s);
    std::cout << "The last word in the string '" << s << "' has a length of: " << len << std::endl;
    return 0;
}