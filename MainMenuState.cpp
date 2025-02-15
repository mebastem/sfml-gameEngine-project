#include "MainMenuState.h"


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys) {
	this->initFonts();
	this->initKeybinds();
	this->gameStateBtn = new Button(100, 100, 150, 50, &this->font, "New Game", sf::Color::Yellow, sf::Color::Red, sf::Color::Blue);
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Black);
}

MainMenuState::~MainMenuState() {
	delete this->gameStateBtn;
}

void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("Fonts/Daily Bubble.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::update(const float& dt) {
	this->updateMousePositions();
	this->updateInput(dt);
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
	system("cls");

	this->gameStateBtn->update(this->mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->gameStateBtn->render(target);
}

void MainMenuState::endState() {
	std::cout << "Ending MainMenuState!" << "\n";
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();
}

void MainMenuState::initKeybinds() {
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}