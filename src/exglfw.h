#ifndef EXGLFW_H
#define EXGLFW_H


// Function specifiers in case library is build/used as a shared library (Windows)
// NOTE: Microsoft specifiers to tell compiler that symbols are imported/exported from a .dll
#if defined(_WIN32)
    #if defined(BUILD_LIBTYPE_SHARED)
        #define RLAPI __declspec(dllexport)     // We are building the library as a Win32 shared library (.dll)
    #elif defined(USE_LIBTYPE_SHARED)
        #define RLAPI __declspec(dllimport)     // We are using the library as a Win32 shared library (.dll)
    #endif
#endif

#ifndef RLAPI
    #define RLAPI       // Functions defined as 'extern' by default (implicit specifiers)
#endif

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

RLAPI const char* glfwExGetJoystickName(int gamepad);
RLAPI int glfwExJoystickPresent(int gamepad);
RLAPI const unsigned char* glfwExGetJoystickButtons(int gamepad, int* count);
RLAPI const unsigned char* glfwExGetJoystickAxes(int gamepad, int* count);

#if defined(__cplusplus)
}
#endif

#endif // EXGLFW_H
