#include "geApplication.h"
#include "geInput.h"
#include "geTime.h"
#include "geSceneManager.h"

namespace ge
{
	Application::Application() :
		mHwnd(nullptr),
		mHdc(nullptr),
		mWidth(0),
		mHeight(0),
		mBackHdc(nullptr),
		mBackBuffer(nullptr)
    {

    }
    Application::~Application()
    {
        delete(mHwnd);
        delete(mHdc);
    }

	void Application::Initialize(HWND hWnd, UINT width, UINT height)
	{
		AdjustWindow(hWnd, width, height);
		CreateBuffer(width, height);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::AdjustWindow(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mWidth = width;
		mHeight = height;

		RECT rect = { 0, 0, width, height };

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd, nullptr, 0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::ClearRenderTarget()
	{
		// 흰색 배경 깔기
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);
	}

	void Application::CopyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void Application::CreateBuffer(UINT width, UINT height)
	{
		// 백버퍼를 가리킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		// 윈도우 해상도에 맞는 버퍼 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		SceneManager::Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		ClearRenderTarget();

		// 오브젝트 그리기
		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		CopyRenderTarget(mBackHdc, mHdc);
	}
}