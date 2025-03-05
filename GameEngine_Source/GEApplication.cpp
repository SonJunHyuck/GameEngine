#include "geApplication.h"
#include "geInput.h"
#include "geTime.h"

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
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);

		mWidth = width;
		mHeight = height;

		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd, nullptr, 0, 0,
			rect.right - rect.left, 
			rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);

		// ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		// ������ �ػ󵵿� �´� ���� ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);

		Time::Initialize();
		Input::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		mPlayer.Update();
		//mPlayer2.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		// ��� ��� ���
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);

		// ������Ʈ �׸���
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		//mPlayer2.Render(mBackHdc);

		// frontDC�� �ҽ� ����
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}