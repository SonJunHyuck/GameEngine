#include "geScene.h"

namespace ge
{
	Scene::Scene() : mGameObjects{}
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Render(hdc);
		}
	}


	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}