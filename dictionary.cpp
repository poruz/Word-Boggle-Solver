#include "dictionary.h"

Dictionary::Dictionary()
{
	std::ifstream fin("dictionary.txt");
	if(fin.fail())
	{
		std::cout << "Dictionary not found" << std::endl;
	}
	else
	{
		std::string word;
		while(fin >> word)
		{
			allWords.insert(word);
		}
	}
}

bool Dictionary::find(std::string str)
{
	return allWords.find(str) == true;
	//return allWords.find(str) != allWords.end();
}