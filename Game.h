#ifndef GAME_H
#define GAME_H

#include "States\GameState.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event sfEvent;
	float deltaTime = 0.0f;
	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;
	sf::Clock dtClock;
	void initWindow();
	void initKeys();
	void initStates();
	

public:
	Game();
	virtual ~Game();

	void endApplication();

	void updateSFMLEvents();
	void update();
	void render();
	void run();
	void updateDeltaTime();
};

#endif