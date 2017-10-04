#ifndef TRIES_H
#define TRIES_H

#include <string>

struct TrieNode
{
	bool isTerminal;
	TrieNode* children[26];

public:
	TrieNode();
	~TrieNode();
};

class Trie
{
	TrieNode* head;
public:
	Trie();
	~Trie();
	void insert(std::string);
	void remove(std::string); //implement later - not required for now
	bool find(std::string);
	bool findPrefix(std::string); //Checks if the word is a prefix in the tree

};

#endif