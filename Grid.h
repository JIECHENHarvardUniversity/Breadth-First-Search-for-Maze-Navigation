#pragma once
#include <vector>
#include "Block.h"


using namespace std;

class Grid
{
private:
	int _width;
	int _height;

	vector<Block *> _blocks;

public:
	Grid(int h,int w);
	~Grid(void);

	int Width() const { return _width; }
	int Height() const { return _height; }
	
	vector<Block *> Blocks() const { return _blocks; }

	int InitMap();
	void InitGrid();
	bool FindWay();

	Block * Get(int i,int j);

};

