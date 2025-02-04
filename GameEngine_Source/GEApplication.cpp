#include "GEApplication.h"

namespace GE
{
    Application::Application() : mHwnd(nullptr), mHdc(nullptr), mSpeed(.0f), mX(.0f), mY(.0f)
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
        mSpeed += 0.001f;
        
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            mX -= 0.1f;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            mX += 0.1f;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            mY -= 0.1f;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            mY += 0.1f;
        }
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
        // DC : 화면 출력에 필요한 모든 정보를 가지는 데이터 구조체
        // GDI 모듈에 의해 관리
        // 폰트, 선 종류, 면 생상 등
        // 화면 출력에 필요한 모든 경우는 WINAPI에서는 DC를 통해서 작업한다.

        // 파란색 사각형 + 검은 테두리
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
        HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);  // 파란색 면 지정, 흰색 면 저장

        HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));  // 빨간 펜 생성
        HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);  // 빨간 테두리 지정

        Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
        DeleteObject(brush);  // 파란색 면 삭제 (brush는 주소일 뿐, 메모리에는 계속 있으니까 지워주어야 함)
        SelectObject(mHdc, oldBrush);  // 흰색 면 지정

        DeleteObject(redPen);  // 빨간 펜 메모리 삭제
        SelectObject(mHdc, oldPen);  // 검은섹 테두리 지정
	}
}