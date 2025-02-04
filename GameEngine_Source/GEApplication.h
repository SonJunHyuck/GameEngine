#pragma once
#include "CommonInclude.h"
#include "geGameObject.h"
#include "geGameObject2.h"

namespace ge
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hWnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;

		// 플레이어
		/*float mX;
		float mY;*/

		GameObject mPlayer;
		GameObject2 mPlayer2;
	};
}