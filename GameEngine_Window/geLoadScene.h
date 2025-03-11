#pragma once
#include "..\\GameEngine_Source\\geSceneManager.h"
#include "gePlayScene.h"

namespace ge
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}