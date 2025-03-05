#pragma once
#include "CommonInclude.h"

namespace ge
{
	class GameObject2
	{
	public:
		GameObject2();
		~GameObject2();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		void Destroy();

		float GetX() { return mX; }
		float GetY() { return mY; }
		void SetPosition(float x, float y) { mX = x; mY = y; }

	private:
		float mX;
		float mY;
	};
}


