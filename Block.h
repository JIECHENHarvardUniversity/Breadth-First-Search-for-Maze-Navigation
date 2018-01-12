#pragma once

class Block
{
private:
	bool _canPass;
	bool _canReach;
	bool _isWay;
	int _jumpCount;
	int _nextJump;

public:
	Block(void);
	~Block(void);

	bool CanPass() const { return _canPass; }
	void CanPass(bool val) { _canPass = val; }

	bool CanReach() const { return _canReach; }
	void CanReach(bool val) { _canReach = val; }

	int JumpCount() const { return _jumpCount; }
	void JumpCount(int val) { _jumpCount = val; }

	int NextJump() const { return _nextJump; }
	void NextJump(int val) { _nextJump = val; }

	bool IsWay() const { return _isWay; }
	void IsWay(bool val) { _isWay = val; }

};

