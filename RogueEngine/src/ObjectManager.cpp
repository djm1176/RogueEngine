#pragma once

#include "GameObject.h"
#include "ObjectManager.h"


ObjectManager& ObjectManager::instance() {
	static ObjectManager instance;
	return instance;
}

void ObjectManager::update() {
	for (auto& go : gameObjects) go->update();
}

void ObjectManager::refresh() {
	gameObjects.erase(std::remove_if(std::begin(gameObjects), std::end(gameObjects),
		[](const std::unique_ptr<GameObject>& mGameObject) {
		return !mGameObject->isActive();
	}), std::end(gameObjects));
}

GameObject& ObjectManager::addGameObject() {
	GameObject* mGameObject = new GameObject();

	std::unique_ptr<GameObject> uPtr{ mGameObject };
	gameObjects.emplace_back(std::move(uPtr));
	return *mGameObject;
}