#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <unordered_set>
#include <fstream>
#include "tries.h"

class Dictionary
{

public:
	Dictionary();
	bool find(std::string);
	
	bool findPrefix(std::string s)
	{
		return allWords.findPrefix(s) == true;
	}

private:
	//std::unordered_set<std::string, std::hash<std::string> > allWords;
	Trie allWords;
};

#endif