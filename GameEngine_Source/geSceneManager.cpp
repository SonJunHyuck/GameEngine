#include "geSceneManager.h"

namespace ge
{
	std::map<const std::wstring, Scene*> SceneManager::mScenes = std::map<const std::wstring, Scene*>();
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		/*for (Scene* scene : mScenes)
		{
			scene->Initialize();
		}*/
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}
