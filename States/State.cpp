#include "State.h"

State::State(sf::RenderTarget* window, std::map<std::string, int>* supportedKeys) {
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->wantToQuit = false;
}

State::~State() {

}

void State::checkForQuit() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["CLOSE"]))) {
		this->wantToQuit = true;
	}
}

const bool& State::getWantToQuit() const {
	return this->wantToQuit;
}