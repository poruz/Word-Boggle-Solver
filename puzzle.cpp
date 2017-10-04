#include "puzzle.h"

Puzzle::Puzzle(std::vector<std::vector<char> > g)
{
	//make grid
	for(unsigned int i = 0; i < g.size(); i++)
	{
		std::vector<std::pair<char, bool> > tempr;
		for(unsigned int j = 0; j < g[0].size(); j++)
		{
			tempr.push_back(std::make_pair(g[i][j], false));
		}
		grid.push_back(tempr);
		tempr.clear();
	}

	//get solution
	std::vector<char> temp;
	getSolution(0,0, grid.size(), temp);
}

void Puzzle::printGrid() const
{
	for(unsigned int i = 0; i < grid.size(); i++)
	{
		for (unsigned int j = 0; j < grid[0].size(); j++)
		{
			std::cout << grid[i][j].first << ' ';
		}
		std::cout << std::endl;
	}
}

void Puzzle::getSolution(int r, int c, int gridSize, std::vector<char> temp)
{
	//Base cases
	if(r < 0 || c < 0)
		return;
	if(r > gridSize-1 || c > gridSize - 1)
		return;
	if(grid[r][c].second == true) //already visited
	{
		return;
	}

	temp.push_back(grid[r][c].first);
	std::string currStr(temp.begin(), temp.end());
	if(dic.findPrefix(currStr) == false)
		return;

	//Recursive cases
	grid[r][c].second = true;
	if(dic.find(currStr) && 
	   solution.find(currStr) == solution.end()) //if the word is in dictionary
	{	
		solution.insert(currStr);
	}

	//Now recurse
	getSolution(r-1, c, gridSize, temp); //North
	getSolution(r-1, c+1, gridSize, temp); //North-east
	getSolution(r, c+1, gridSize, temp); //East
	getSolution(r+1, c+1, gridSize, temp); //South-east
	getSolution(r+1, c, gridSize, temp); //South
	getSolution(r+1, c-1, gridSize, temp); //South-west	
	getSolution(r, c-1, gridSize, temp); //West
	getSolution(r-1, c-1, gridSize, temp); //North-west

	//Undo
	grid[r][c].second = false;
	
	if(temp.size() == 1) //go to next entry in the grid
	{
		//Go to next tile in the grid
		temp.clear();
		if(r == gridSize-1) //start from first tile in the next column
			getSolution(0,c+1, gridSize, temp);
		else
			getSolution(r+1, c, gridSize, temp);
		return;
	}
	
}

void Puzzle::printSolution() const
{
   for(std::set<std::string>::iterator it = solution.begin(); 
            it != solution.end(); ++it)
   {
      std::cout << *it << std::endl;         
   }
}
