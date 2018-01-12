#include "StdAfx.h"
#include "Block.h"

Block::Block(void)
{
	_canPass = true;
	_canReach = false;
	_nextJump = -1;
	_isWay = false;
	_jumpCount = 100;
}

Block::~Block(void)
{
}

