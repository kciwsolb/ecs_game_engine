#pragma once
#include <vector>
#include <memory>
#include <typeinfo>
#include "Component.h"

class Entity {
public:	
	Entity(unsigned int id, std::string tag);
	~Entity();
	void Update();
	void LateUpdate();
	unsigned int GetID() const;
	std::string GetTag() const;
	
	/*GetComponent returns a pointers of the specified Component Type from the entities list of components. Returns nullptr if it fails to find a match.*/
	template<typename T> T* GetComponent() const {
		for (auto& c : components) {
			if (typeid(*c).name() == typeid(T).name()) {
				return static_cast<T*>(c.get());
			}
		}
		return nullptr;
	}

	/*AddComponent pushes a Component of the specified type to the components vector on the Entity. Returns pointer upon success and nullptr upon failure.*/
	template<typename T, typename... Args> T* AddComponent(Args &&... args) {
		if (std::is_base_of<Component, T>()) {
			std::unique_ptr<T> t = std::make_unique<T>(args...);
			components.push_back(std::move(t));
			T* tPtr = static_cast<T*>(components.back().get());
			return tPtr;
		}
		else {
			return nullptr;
		}
	}

private:
	unsigned int id;
	std::string tag;
	std::vector<std::unique_ptr<Component>> components;

	void Init(unsigned int id, std::string tag);
};
