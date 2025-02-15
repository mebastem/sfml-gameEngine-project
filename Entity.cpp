#include "Entity.h"

Entity::Entity() {
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Red);
	this->movementSpeed = 100.f;
}

Entity::~Entity() {

}

void Entity::update(const float& dt) {

}

void Entity::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}

void Entity::move(const float& dt, const float dirX, const float dirY) {
	this->shape.move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
}