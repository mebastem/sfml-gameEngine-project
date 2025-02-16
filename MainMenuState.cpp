#include "MainMenuState.h"


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(window, supportedKeys, states) {
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Black);
}

MainMenuState::~MainMenuState() {
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("Fonts/Daily Bubble.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initButtons() {
	this->buttons["NEW_GAME_BTN"] = new Button(100, 100, 150, 50, &this->font, "New Game", sf::Color::Yellow, sf::Color::Red, sf::Color::Blue);
	this->buttons["EXIT_STATE_BTN"] = new Button(400, 100, 150, 50, &this->font, "Exit", sf::Color::Red, sf::Color::Green, sf::Color::Blue);
}

void MainMenuState::updateButtons() {
	for (auto& it : this->buttons) {
		it.second->update(this->mousePosView);
	}
	if (this->buttons["NEW_GAME_BTN"]->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}
	if (this->buttons["EXIT_STATE_BTN"]->isPressed()) {
		this->wantToQuit = true;
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
}

void MainMenuState::endState() {
	std::cout << "Ending MainMenuState!" << "\n";
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();
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