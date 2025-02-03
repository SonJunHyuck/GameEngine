// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 정적 라이브러리
// 프로그램 자체에 포함된 라이브러리
// 장점
// 시스템 환경이 변해도 어플리케이션에 영향이 없다.
// 컴파일 시 필요한 라이브러리를 적재하기 때문에, 이식성이 좋다.
// 런타임 시 외부를 참조할 필요가 없기 때문에 속도가 빠르다.
// 단점
// 같은 코드를 가진 프로그램을 실행한다면, 코드가 중복되어 메모리가 낭비된다.
// 라이브러리가 변경되면, 프로그램 자체를 다시 컴파일 하여 배포해야한다.