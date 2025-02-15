#include "Game.h"

Game::Game() {
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Game::~Game() {
	delete this->window;
	
	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

void Game::updateDeltaTime() {
	this->deltaTime = this->dtClock.restart().asSeconds();
	//system("cls");
	//std::cout << this->deltaTime << std::endl;
}

void Game::initWindow() {
	std::ifstream file("Config/window.ini");
	sf::VideoMode window_bounds(800, 600);
	std::string title = "";
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (file.is_open()) {
		std::getline(file, title);
		file >> window_bounds.width >> window_bounds.height;
		file >> framerate_limit;
		file >> vertical_sync_enabled;
	}
	
	file.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates() {
	this->states.push(new MainMenuState(this->window, &this->supportedKeys));
	this->states.push(new GameState(this->window, &this->supportedKeys));
}

void Game::update() {
	this->updateSFMLEvents();
	if (!this->states.empty()) {
		this->states.top()->update(this->deltaTime);
		if (this->states.top()->getWantToQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		this->endApplication();
		this->window->close();
	}
}

void Game::render() {
	this->window->clear();
	if (!this->states.empty())
		this->states.top()->render();
	this->window->display();
}

void Game::run() {
	while (this->window->isOpen()) {
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}

void Game::updateSFMLEvents() {
	while (this->window->pollEvent(sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed)
				this->window->close();
	}
}

void Game::endApplication() {
	std::cout << "Ending Application!" << std::endl;
}

void Game::initKeys() {
	std::ifstream file("Config/supported_keys.ini");
	if (file.is_open()) {
		std::string key = "";
		int key_value = 0;
		while (file >> key >> key_value) {
			this->supportedKeys[key] = key_value;
		}
	}
	file.close();

	//this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
	//this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
	//this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
	//this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
	//this->supportedKeys.emplace("S", sf::Keyboard::Key::S);

	for (auto& i : this->supportedKeys)
		std::cout << i.first << " " << i.second << std::endl;
}