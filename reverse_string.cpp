//REVERSING A STRING
/* #include <iostream>
#include <algorithm>

int main ()
{
    std::string str = "James Louis";
    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;

    return 0;
} */

// FINDING THE LENGTH OF THE LAST WORD
#include <iostream>
#include <string>

std::string Capitalize_first_letter(std::string text) {

	for (int x = 0; x < text.length(); x++)
	{
		if (x == 0)
		{
			text[x] = toupper(text[x]);
		}
		else if (text[x - 1] == ' ')
		{
			text[x] = toupper(text[x]);
		}
	}

	return text;
}

int main() 
{
	std::cout << Capitalize_first_letter("Write a C++ program");
	std::cout << "\n" << Capitalize_first_letter("cpp string exercises");
	return 0;
}