#include "geTime.h"

namespace ge
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;
	float Time::NaturalFrequency = 0.0f;

	void Time::Initialize()
	{
		// Cpu 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 현재 진동 수 (프로그램 실행 시)
		QueryPerformanceCounter(&PrevFrequency);

		Time::NaturalFrequency = 1.0f / static_cast<float>(CpuFrequency.QuadPart);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);
		
		float differenceFrequency 
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = differenceFrequency * Time::NaturalFrequency;
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time: %d", (int)fps);
		int str_len = wcsnlen_s(str, 50);

		TextOut(hdc, 10, 10, str, str_len);
	}
}