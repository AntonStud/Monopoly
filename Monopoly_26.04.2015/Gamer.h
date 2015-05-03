#pragma once
#include "Property.h"

class Gamer
{
private:

	std::string playerName;

	int playerCapital;

	int playerCurPositon;

	bool playerCanGo;

	vector<std::shared_ptr<Property>> playerProperty;

public:

	Gamer();

	~Gamer();

};

