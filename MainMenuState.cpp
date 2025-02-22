#include "MainMenuState.h"


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(window, supportedKeys, states) {
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

MainMenuState::~MainMenuState() {
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

void MainMenuState::initBackground() {
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	if (!this->backgroundTexture.loadFromFile("assets/background.jpg")) {
		throw "ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initVariables() {
}

void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("Fonts/Daily Bubble.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initButtons() {
	/*
	I tried to render a random texture (Button_Play.png) as a button.
	this->playButton.setSize(sf::Vector2f(300, 100));
	this->playButton.setFillColor(sf::Color::White);
	this->playButton.setPosition(sf::Vector2f(800, 700));
	this->playButtonTexture.loadFromFile("assets/Button_Play.png");
	this->playButton.setTexture(&this->playButtonTexture);
	*/
	this->buttons["NEW_GAME_BTN"] = new Button(800, 500, 150, 50, &this->font, "New Game", sf::Color::Yellow, sf::Color::Red, sf::Color::Blue);
	this->buttons["EXIT_STATE_BTN"] = new Button(1000, 500, 150, 50, &this->font, "Exit", sf::Color::Red, sf::Color::Green, sf::Color::Blue);
}

void MainMenuState::updateButtons() {
	for (auto& it : this->buttons) {
		it.second->update(this->mousePosView);
	}
	if (this->buttons["NEW_GAME_BTN"]->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}
	if (this->buttons["EXIT_STATE_BTN"]->isPressed()) {
		this->endState();
	}
}

void MainMenuState::renderButtons(sf::RenderTarget* target) {
	for (auto& it : this->buttons) {
		it.second->render(target);
	}
}

void MainMenuState::update(const float& dt) {
	this->updateMousePositions();
	this->updateInput(dt);
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
	//system("cls");
	this->updateButtons();
}

void MainMenuState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->renderButtons(target);
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);
	// target->draw(this->playButton);
}

void MainMenuState::updateInput(const float& dt) {
	//this->checkForQuit();
}

void MainMenuState::initKeybinds() {
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
	if (ifs.is_open()) {
		std::string key = "", key2 = "";
		while (ifs >> key >> key2) {
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();

	/*this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	*/
}