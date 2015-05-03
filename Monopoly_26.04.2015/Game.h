#pragma once


#include "Property.h"
#include "Gamer.h"

class Game
{
private:

	vector<Gamer*> gamers;
	vector<shared_ptr<Property>> allEntities;
	vector<Notice*> notices;
	vector<Surpise*> surprises;




public:
	Game();
	~Game();
};

