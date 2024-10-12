#pragma once

#ifdef KB_PLATFORM_WINDOWS
	#ifdef KB_BUILD_DLL
		// #define KAPI
		#define	KAPI __declspec(dllexport)
	#else
		// #define KAPI
		#define KAPI __declspec(dllimport)
	#endif
#else
 	#ifdef KB_BUILD_DLL
        #define KAPI __attribute__((visibility("default")))
    #else
        #define KAPI
    #endif
#endif

#ifdef KB_ENABLE_ASSERTS
#define KB_ASSERT(x, ...) { if(!(x)) { KB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define KB_CORE_ASSERT(x, ...) { if(!(x)) { KB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define KB_ASSERT(x, ...)
#define KB_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)
#define KB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)