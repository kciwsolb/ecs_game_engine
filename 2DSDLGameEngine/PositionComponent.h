#pragma once

#include "Component.h"
#include "Entity.h"

struct PositionComponent : Component {
public:
	PositionComponent(Entity* entity);
	PositionComponent(Entity* entity, float x, float y);
	~PositionComponent();
	void Update();
	void LateUpdate();
	void Set(float x, float y);
	void SetX(float x);
	void SetY(float y);
	float GetX();
	float GetY();
	void Add(PositionComponent other);
	void Subtract(PositionComponent other);
	void Multiply(PositionComponent other);
	void Divide(PositionComponent other);
	bool Equals(PositionComponent other);


private:
	float previousX;
	float previousY;
	float currentX;
	float currentY;
	float targetX;
	float targetY;
	Entity* entity;

	void Init(Entity* entity, float x, float y);
};
