#ifndef STATE_H
#define STATE_H

#include "../Entity.h"

class State {
private:

protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	std::vector<sf::Texture> textures;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool wantToQuit;

	virtual void initKeybinds() = 0;

public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	const bool& getWantToQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void updateMousePositions();
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif