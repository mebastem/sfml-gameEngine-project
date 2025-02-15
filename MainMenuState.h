#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "States/GameState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
	sf::RectangleShape background;
	sf::Font font;
	Button* gameStateBtn;

	void initKeybinds();
	void initFonts();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();
	void endState();

	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

#endif