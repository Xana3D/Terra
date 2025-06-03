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