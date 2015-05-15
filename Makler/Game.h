#pragma once
class Game
{
private:

	int numOfPlayers;

public:
	Game(int numOfPlayers = 3);
	~Game();

	int GetNumOfPlayers() const;
	void SetNumOfPlayers(const int& numOfPlayers);
};

