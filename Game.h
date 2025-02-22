#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game
{
private:
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings window_settings;
	sf::RenderWindow* window;
	sf::Event sfEvent;
	float deltaTime = 0.0f;
	bool fullScreen;
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
	void initVariables();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
	void updateDeltaTime();
};

#endif