#include "geInput.h"

namespace ge
{
	std::vector<Input::Key> Input::mKeys = {};
	
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void ge::Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;
			
			mKeys.push_back(key);
		}
	}

	void ge::Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// 키가 눌렸다.
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed)
				{
					mKeys[i].state = eKeyState::Pressed;  // 눌려있을 때, 또 누름
				}
				else
				{
					mKeys[i].state = eKeyState::Down;  // 안눌려있을 때, 누름
				}

				mKeys[i].bPressed = true;
			}
			else  // 키가 안눌렸다.
			{
				if (mKeys[i].bPressed)
				{
					mKeys[i].state = eKeyState::Up;  // 눌려있을 때, 땜
				}
				else
				{
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
}
