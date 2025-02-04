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

	private:
		float mX;
		float mY;
	};
}


