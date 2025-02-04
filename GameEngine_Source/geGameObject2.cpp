#include "geGameObject2.h"

namespace ge
{
	GameObject2::GameObject2() : mX(0), mY(0)
	{

	}

	GameObject2::~GameObject2()
	{

	}

	void GameObject2::Update()
	{
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.1f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.1f;
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.1f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.1f;
		}
	}

	void GameObject2::LateUpdate()
	{

	}

	void GameObject2::Render(HDC hdc)
	{

		// DC : ȭ�� ��¿� �ʿ��� ��� ������ ������ ������ ����ü
		// GDI ��⿡ ���� ����
		// ��Ʈ, �� ����, �� ���� ��
		// ȭ�� ��¿� �ʿ��� ��� ���� WINAPI������ DC�� ���ؼ� �۾��Ѵ�.

		// �Ķ��� �簢�� + ���� �׵θ�
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);  // �Ķ��� �� ����, ��� �� ����

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));  // ���� �� ����
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);  // ���� �׵θ� ����

		Ellipse(hdc, 1000 + mX, 500 + mY, 1100 + mX, 600 + mY);
		DeleteObject(brush);  // �Ķ��� �� ���� (brush�� �ּ��� ��, �޸𸮿��� ��� �����ϱ� �����־�� ��)
		SelectObject(hdc, oldBrush);  // ��� �� ����

		DeleteObject(redPen);  // ���� �� �޸� ����
		SelectObject(hdc, oldPen);  // ������ �׵θ� ����
	}
}