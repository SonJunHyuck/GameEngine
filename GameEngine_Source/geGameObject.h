#pragma once
#include "CommonInclude.h"
#include "geGameObject2.h"

namespace ge
{	
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);
	
	private:
		float mX;
		float mY;

		std::vector<GameObject2> bullets;
	};
}

