#pragma once

#include <list>
#include <string>
#include "Transform.h"
#include "Component.h"

class GameObject {
public:
	GameObject& instantiate();
	GameObject& instantiate(const std::string& name);
	GameObject& instantiate(const std::string& name, const Transform& transform);

private:
	GameObject();
	~GameObject();

	Transform transform;
	std::list<Component> components;
};

