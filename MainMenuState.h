#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "States/GameState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
	sf::Texture backgroundTexture;
	sf::Texture playButtonTexture;
	sf::RectangleShape playButton;
	sf::RectangleShape background;
	sf::Font font;
	std::map<std::string, Button*> buttons;

	void initBackground();
	void initVariables();
	void initKeybinds();
	void initFonts();
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	void updateButtons();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
	void renderButtons(sf::RenderTarget* target = nullptr);
};

#endif