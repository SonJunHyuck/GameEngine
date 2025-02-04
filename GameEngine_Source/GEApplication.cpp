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
        // DC : ȭ�� ��¿� �ʿ��� ��� ������ ������ ������ ����ü
        // GDI ��⿡ ���� ����
        // ��Ʈ, �� ����, �� ���� ��
        // ȭ�� ��¿� �ʿ��� ��� ���� WINAPI������ DC�� ���ؼ� �۾��Ѵ�.

        // �Ķ��� �簢�� + ���� �׵θ�
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
        HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);  // �Ķ��� �� ����, ��� �� ����

        HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));  // ���� �� ����
        HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);  // ���� �׵θ� ����

        Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
        DeleteObject(brush);  // �Ķ��� �� ���� (brush�� �ּ��� ��, �޸𸮿��� ��� �����ϱ� �����־�� ��)
        SelectObject(mHdc, oldBrush);  // ��� �� ����

        DeleteObject(redPen);  // ���� �� �޸� ����
        SelectObject(mHdc, oldPen);  // ������ �׵θ� ����
	}
}