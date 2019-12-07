#pragma once

#include <list>
#include "GameObject.h"

class SceneManager {
private:
	/// <summary>
	/// A collection of GameObjects actively in the scene.
	/// </summary>
	static std::list<GameObject> mSceneGameObjects;

	/// <summary>
	/// Update the manager with a GameObject that was created.
	/// </summary>
	/// <param name="gameObject">The GameObject to notify with.</param>
	/// <returns>True if the GameObject was successfully appended.</returns>
	static bool insertSceneGameObject(GameObject gameObject);

	friend class GameObject;
};

