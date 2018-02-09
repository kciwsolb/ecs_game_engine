#include "Entity.h"
#include "PositionComponent.h"
#include <iostream>

Entity::Entity(unsigned int id, std::string tag) {
	Init(id, tag);
}

Entity::~Entity() {
	for (auto& it = components.begin(); it != components.end();) {
		it = components.erase(it);
	}
}

void Entity::Init(unsigned int id, std::string tag) {
	this->id = id;
	this->tag = tag;
}

void Entity::Update() {
	for (auto& c : components) {
		c->Update();
	}
}

void Entity::LateUpdate() {
	for (auto& c : components) {
		if (dynamic_cast<PositionComponent*>(c.get()) != nullptr) {
			static_cast<PositionComponent*>(c.get())->LateUpdate();
		}
	}
}

unsigned int Entity::GetID() const{
	return id;
}

std::string Entity::GetTag() const {
	return tag;
}

