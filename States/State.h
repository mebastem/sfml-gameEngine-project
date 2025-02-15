#ifndef STATE_H
#define STATE_H

#include "../Entity.h"

class State {
private:

protected:
	sf::RenderTarget* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	std::vector<sf::Texture> textures;
	bool wantToQuit;

	virtual void initKeybinds() = 0;

public:
	State(sf::RenderTarget* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	const bool& getWantToQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif