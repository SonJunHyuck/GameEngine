#include "geGameObject.h"

namespace ge
{
	GameObject::GameObject() : mX(0), mY(0)
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
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

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{

		// DC : ȭ�� ��¿� �ʿ��� ��� ������ ������ ������ ����ü
		// GDI ��⿡ ���� ����
		// ��Ʈ, �� ����, �� ���� ��
		// ȭ�� ��¿� �ʿ��� ��� ���� WINAPI������ DC�� ���ؼ� �۾��Ѵ�.

		// �Ķ��� �簢�� + ���� �׵θ�
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);  // �Ķ��� �� ����, ��� �� ����

		HPEN bluePen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));  // ���� �� ����
		HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);  // ���� �׵θ� ����
		
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		DeleteObject(brush);  // �Ķ��� �� ���� (brush�� �ּ��� ��, �޸𸮿��� ��� �����ϱ� �����־�� ��)
		SelectObject(hdc, oldBrush);  // ��� �� ����

		DeleteObject(bluePen);  // ���� �� �޸� ����
		SelectObject(hdc, oldPen);  // ������ �׵θ� ����
	}
}