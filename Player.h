#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
class Player : public Entity
{
private:
	// Variables
	// Initializer functions
	void initVariables();
	void initComponents();
	// Accessors
	// Modifiers
	// Functions
public:
	Player(float x, float y, sf::Texture* texture);
	virtual ~Player();

	// Functions
};

#endif

