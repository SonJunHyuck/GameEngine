#include "geGameObject.h"
#include "geInput.h"
#include "geTime.h"

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
		const int speed = 100;

		if (Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{

		// DC : 화면 출력에 필요한 모든 정보를 가지는 데이터 구조체
		// GDI 모듈에 의해 관리
		// 폰트, 선 종류, 면 생상 등
		// 화면 출력에 필요한 모든 경우는 WINAPI에서는 DC를 통해서 작업한다.

		// 파란색 사각형 + 검은 테두리
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);  // 파란색 면 지정, 흰색 면 저장

		HPEN bluePen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));  // 빨간 펜 생성
		HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);  // 빨간 테두리 지정
		
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		DeleteObject(brush);  // 파란색 면 삭제 (brush는 주소일 뿐, 메모리에는 계속 있으니까 지워주어야 함)
		SelectObject(hdc, oldBrush);  // 흰색 면 지정

		DeleteObject(bluePen);  // 빨간 펜 메모리 삭제
		SelectObject(hdc, oldPen);  // 검은섹 테두리 지정
	}
}