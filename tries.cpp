#include "tries.h"

TrieNode::TrieNode()
:isTerminal(false)
{
	for(int i = 0; i < 26; i++)
	{
		children[i] = NULL;
	}
}

TrieNode::~TrieNode()
{
	for(int i = 0; i < 26; i++)
	{
		if(children[i])
			delete children[i];
	}
}


Trie::Trie()
: head(new TrieNode)
{ }

Trie::~Trie()
{
	delete head;
}

void Trie::insert(std::string str)
{
	if(head == NULL)
	{
		head = new TrieNode;
	}

	TrieNode* temp = head;
	unsigned int i = 0;

	while(i != str.size())
	{
		if(temp->children[str[i] - 'a'] == NULL)
			temp->children[str[i] - 'a'] = new TrieNode;
		temp = temp->children[str[i] - 'a'];
		i++;

		if(i == str.size())
		{
			temp->isTerminal = true;
		}
	}
}

void Trie::remove(std::string str)
{
	/* Implement later */
}


/*Note:
If you want to go to 'i'th child
You need this->children[ 'i' - 'a']
Example, if you want to go to child p,
you need child location 16 - 1 = 15,
which is 'p' - 'a' 
*/
bool Trie::find(std::string str)
{
	TrieNode* temp = head;

	unsigned int i = 0;
	while(temp != NULL)
	{
		TrieNode* loc = temp->children[str[i] - 'a']; //required location 
		if( loc ) //letter exists
		{
			if(i != str.size() - 1) //not the last letter
			{
				i++;
				temp = loc;
			}
			else //last letter - i == str.size() - 1
			{
				if(loc->isTerminal) //==true
					return true;
				return false;
			}
		}
		else //loc == NULL
		{
			return false;
		}
	}
	return false; //empty tries
}

/* Checks if str exists as a prefix in the trie */
bool Trie::findPrefix(std::string str)
{
	TrieNode* temp = head;

	unsigned int i = 0;
	while(temp != NULL)
	{
		TrieNode* loc = temp->children[str[i] - 'a']; //required location 
		if( loc ) //letter exists
		{
			if(i != str.size() - 1) //not the last letter
			{
				i++;
				temp = loc;
			}
			else //last letter - i == str.size() - 1
			{
				return true; //no need to check for terminal
			}
		}
		else //loc == NULL
		{
			return false;
		}
	}
	return false; //empty tries
}