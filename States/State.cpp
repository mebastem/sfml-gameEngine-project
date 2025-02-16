#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) {
	this->states = states;
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

void State::updateMousePositions() {
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}