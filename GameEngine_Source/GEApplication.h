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
		void AdjustWindow(HWND hwnd, UINT width, UINT height);
		void ClearRenderTarget();
		void CopyRenderTarget(HDC source, HDC dest);
		void CreateBuffer(UINT width, UINT height);

	private:
		HWND mHwnd;
		HDC mHdc;
		HDC mBackHdc;

		HBITMAP mBackBuffer;


		UINT mWidth;
		UINT mHeight;
	};
}