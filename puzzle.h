#ifndef PUZZLE_H
#define PUZZLE_H

#include "dictionary.h"
#include <iostream>
#include <vector>
#include <set>

class Puzzle
{
public:
	Puzzle(std::vector<std::vector<char> >);
	void printGrid() const;
	void getSolution(int, int, int, std::vector<char>); //startRow, startCol, gridSize, word
	void printSolution() const;
private:
	std::vector<std::vector<std::pair<char, bool> > > grid; //square grid
	std::set<std::string> solution;
	Dictionary dic;
};

#endif