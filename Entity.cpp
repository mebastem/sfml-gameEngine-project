#include "Entity.h"

Entity::Entity() {
	this->initVariables();
}

Entity::~Entity() {
	delete this->sprite;
}

void Entity::initVariables() {
	this->texture = nullptr;
	this->sprite = nullptr;
	this->movementSpeed = 100.f;
}

void Entity::createSprite(sf::Texture* texture) {
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

void Entity::update(const float& dt) {

}

void Entity::render(sf::RenderTarget* target) {
	if (this->sprite)
		target->draw(*this->sprite);
}

void Entity::move(const float& dt, const float dirX, const float dirY) {
	if(this->sprite)
		this->sprite->move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
}