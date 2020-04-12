#pragma once

#include <memory>
#include <vector>

//Forward declaration
class GameObject;

class ObjectManager {
	friend class Game;

	//Singleton Design Pattern
	//Search this project for 'SINGLETON_LINK' comment
public:

	static ObjectManager& instance();

private:

	ObjectManager() {}

public:

	ObjectManager(ObjectManager const&) = delete;
	void operator=(ObjectManager const&) = delete;


private:

	void update();
	void refresh();

public:

	GameObject& addGameObject();

private:
	std::vector<std::unique_ptr<GameObject>> gameObjects;

};
