#pragma once
#include "CommonInclude.h"

namespace ge
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};
	
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};
		static void Initialize();
		static void Update();
		static void CreateKeys();

		static void UpdateKeys();
		static void UpdateKey(Input::Key& key);
		static bool IsKeyDown(eKeyCode code);
		static void UpdateKeyDown(Input::Key& key);
		static void UpdateKeyUp(Input::Key& key);

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }  // Pressed

	private:
		// eKeyState mState = eKeyState::None;  // down, up, stay, ...
		static std::vector<Key> mKeys;
	};
}

