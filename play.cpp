#include <iostream>
#include <fstream>
#include <sstream>
#include "puzzle.h"

using namespace std;

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		cout << "No file entered" << endl;
		return 1;
	}

	ifstream fin(argv[1]);
	if(fin.fail())
	{
		cout << "File not found" << endl;
		return 1;
	}

	//----play now
	
	//Get the grid from file
	vector<vector<char> > mygrid;
	stringstream ss;
	
	vector<char> v;
	string str;

	//fill first row of mygrid
	getline(fin, str);
	ss << str;
	char c;
	
	//filling first row
	while(ss >> c)
	{
		if(c == ' ')
			cout << "SPACE" <<endl;
		else
		{
			if(isalpha(c) == false)
			{
				cout << "Invalid grid" << endl;
				fin.close();
				return 1;
			}
			else
			{
				v.push_back(c);
			}
		}
	}
	mygrid.push_back(v);
	v.clear();
	str = "";

	//Rest of the rows
	while(getline(fin, str))
	{
		ss.clear();
		ss << str;
		while(ss >> c)
		{
			if(isalpha(c) == false)
			{
				cout << c << endl;
				cout << "Invalid grid" << endl;
				fin.close();
				return 1;
			}
			else
			{
				v.push_back(c);
			}
		
		}
		mygrid.push_back(v);
		if(v.size() != mygrid[0].size())
		{
			cout << v.size() << ' ' << mygrid[0].size() << endl;
			cout << "Invalid square grid" << endl;
			fin.close();
			return 1;
		}
		v.clear();
	}

	if(mygrid.size() != mygrid[0].size())
	{
		cout << "Invalid grid" << endl;
		return 1;
	}

	Puzzle myPuzzle(mygrid); //constructor that also gets
	                           //the solution to the puzzle

   //** Now print the solution
   myPuzzle.printSolution();  	
	return 0;
}
