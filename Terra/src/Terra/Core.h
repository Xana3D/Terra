#pragma once

#ifdef TA_PLATFORM_WINDOWS
	#ifdef TA_BUILD_DLL
		#define TERRA_API __declspec(dllexport)
	#else
		#define TERRA_API __declspec(dllimport)
	#endif
#else
	#error Terra only supports Windows!
#endif

#ifdef TA_ENABLE_ASSERTS
	#define TA_ASSERT(x, ...) { if(!(x)) { TA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TA_CORE_ASSERT(x, ...) { if(!(x)) { TA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TA_ASSERT(x, ...)
	#define TA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)