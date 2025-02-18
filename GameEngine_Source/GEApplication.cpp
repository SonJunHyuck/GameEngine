#include "geApplication.h"
#include "geInput.h"
#include "geTime.h"

namespace ge
{
    Application::Application() : mHwnd(nullptr), mHdc(nullptr), mSpeed(.0f)
    {

    }
    Application::~Application()
    {
        delete(mHwnd);
        delete(mHdc);
    }

	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);
		Time::Initialize();
		Input::Initialize();

        mSpeed = 0;
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
		mPlayer2.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
		mPlayer2.Render(mHdc);
	}
}