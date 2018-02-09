#pragma once

#include "EntityManager.h"
#include <iostream>

class GameObject {
public:
	virtual void Update() {}
	virtual ~GameObject() { EntityManager::SharedInstance().RemoveEntity(entity); }
	void SetIsDead(bool isDead) { this->isDead = isDead; }
	bool GetIsDead() { return isDead;  }
protected:
	bool isDead = false;
	Entity* entity;
	virtual void Init() {}
};