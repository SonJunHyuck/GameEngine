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

		void Initialize(HWND hWnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;
		HDC mBackHdc;

		HBITMAP mBackBuffer;


		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer;
		GameObject2 mPlayer2;
	};
}