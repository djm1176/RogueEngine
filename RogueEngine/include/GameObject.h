#pragma once

#include <vector>
#include <array>
#include <string>
#include <bitset>

#include "ObjectManager.h"

//Forward declarations
class SDL_Rect;
class Component;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID() {
	static ComponentID lastId = 0;
	return lastId++;
}

template<typename T> ComponentID getComponentTypeID() noexcept {
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

static constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
public:
	GameObject* gameObject;

	virtual ~Component() {}

	virtual void init() {}
	virtual void update() {}
};

class GameObject {
public:

	bool isActive() const { return m_active; }
	
	void update() { for (auto& component : m_components) component->update(); }
	
	void destroy() { m_active = false; }

	static GameObject& instantiate() {
		return ObjectManager::instance().addGameObject();
	}

	template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs) {
		T* component(new T(std::forward<TArgs>(mArgs)...));
		component->gameObject = this;
		std::unique_ptr<Component> uPtr{ component };
		m_components.emplace_back(std::move(uPtr));

		m_componentArray[getComponentTypeID<T>()] = component;
		m_componentBitSet[getComponentTypeID<T>()] = true;

		component->init();
		return *component;
	}

	template <typename T> T& getComponent() const {
		auto ptr(m_componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

	std::string toString() const;

private:
	bool m_active = true;
	std::vector<std::unique_ptr<Component>> m_components;

	ComponentArray m_componentArray;
	ComponentBitSet m_componentBitSet;

};

class Sprite : Component {
public:
	Sprite(std::string name, SDL_Rect position);
private:
	void init() override;
	void update() override;


};