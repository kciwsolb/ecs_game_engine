#include "EntityManager.h"
#include <iostream>

EntityManager::EntityManager() {
	Init();
}

void EntityManager::Init() {

}

void EntityManager::Update() {
	for (unsigned int i = 0; i < entities.size(); i++) {
		entities[i]->Update();
	}
}

void EntityManager::LateUpdate() {
	for (unsigned int i = 0; i < entities.size(); i++) {
		entities[i]->LateUpdate();
	}
}

Entity* EntityManager::AddEntity(std::string tag) {
	entities.push_back(std::make_unique<Entity>(entityCount, tag));
	entityCount++;
	return entities.back().get();
};

void EntityManager::RemoveEntity(Entity* entity) {
	for (auto it = entities.begin(); it != entities.end();) {
		if (&*it->get() == entity) {
			it = entities.erase(it);
		}
		else {
			it++;
		}
	}
}

unsigned int EntityManager::GetEntityCount() {
	return entityCount;
}

Entity* EntityManager::GetEntity(unsigned int id) {
	for (auto& e : entities) {
		if (e->GetID() == id) {
			return e.get();
		}
	}
	return nullptr;
}