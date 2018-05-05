/* Highlights reserved keywords*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

/* Color codes */
#define COLOR_GREEN "\e[1;32m"
#define COLOR_RESET "\x1b[0m"
/* *********** */

bool is_keyword(std::string&);

int main(int argc, char *argv[])
{	
	if (argc < 2) {
		std::cout << "Usage: ./" << argv[0] << " <file>\n";
		exit(EXIT_FAILURE);
	}
	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cout << "Error opening file.\n";
		exit(EXIT_FAILURE);
	}
	
	std::string word; char c;
	while (file.get(c)) 
	{
		if (isalpha(c))
			word += c;
		else {
			if (is_keyword(word))
				std::cout << COLOR_GREEN << word << COLOR_RESET;
			else
				std::cout << word;
			std::cout << c;
			word="";
		}
	}
	
	return 0;
}

bool is_keyword(std::string &word)
{
	static const char *keywords[] =
	{
	"auto","break","case","char",
	"const","continue","default","do",
	"double","else","enum","extern",
	"float","for", "goto", "if",
	"int","long","register","return",
	"short","signed","sizeof","static",
	"struct","switch","typedef","union",
	"unsigned","void","volatile","while",
	"bool"
	};
	for (auto &w : keywords)
		if (w==word) return true;
	return false;
}
