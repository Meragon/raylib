#include "exglfw.h"                 // Declares module functions
#include "raylib.h"                 // Declares module functions
#include <stdio.h>

#if defined(PLATFORM_DESKTOP)
    #define GLFW_INCLUDE_NONE       // Disable the standard OpenGL header inclusion on GLFW3
                                    // NOTE: Already provided by rlgl implementation (on glad.h)
    #include "GLFW/glfw3.h"         // GLFW3 library: Windows, OpenGL context and Input management
                                    // NOTE: GLFW3 already includes gl.h (OpenGL) headers

    // Support retrieving native window handlers
    #if defined(_WIN32)
        #define GLFW_EXPOSE_NATIVE_WIN32
        #include "GLFW/glfw3native.h"       // WARNING: It requires customization to avoid windows.h inclusion!

        #if defined(SUPPORT_WINMM_HIGHRES_TIMER) && !defined(SUPPORT_BUSY_WAIT_LOOP)
            // NOTE: Those functions require linking with winmm library
            unsigned int __stdcall timeBeginPeriod(unsigned int uPeriod);
            unsigned int __stdcall timeEndPeriod(unsigned int uPeriod);
        #endif
    #endif
    #if defined(__linux__) || defined(__FreeBSD__)
        #include <sys/time.h>               // Required for: timespec, nanosleep(), select() - POSIX

        //#define GLFW_EXPOSE_NATIVE_X11      // WARNING: Exposing Xlib.h > X.h results in dup symbols for Font type
        //#define GLFW_EXPOSE_NATIVE_WAYLAND
        //#define GLFW_EXPOSE_NATIVE_MIR
        #include "GLFW/glfw3native.h"       // Required for: glfwGetX11Window()
    #endif
    #if defined(__APPLE__)
        #include <unistd.h>                 // Required for: usleep()

        //#define GLFW_EXPOSE_NATIVE_COCOA    // WARNING: Fails due to type redefinition
        #include "GLFW/glfw3native.h"       // Required for: glfwGetCocoaWindow()
    #endif
#endif

#if defined(PLATFORM_WEB)
    #define GLFW_INCLUDE_ES2            // GLFW3: Enable OpenGL ES 2.0 (translated to WebGL)
    #include "GLFW/glfw3.h"             // GLFW3: Windows, OpenGL context and Input management
    #include <sys/time.h>               // Required for: timespec, nanosleep(), select() - POSIX

    #include <emscripten/emscripten.h>  // Emscripten functionality for C
    #include <emscripten/html5.h>       // Emscripten HTML5 library
#endif


const char* glfwExGetJoystickName(int gamepad)
{
#if defined(PLATFORM_DESKTOP)
	return glfwGetJoystickName(gamepad);
#endif
}

int glfwExJoystickPresent(int gamepad)
{
#if defined(PLATFORM_DESKTOP)
	return glfwJoystickPresent(gamepad);
#else
    return 0;
#endif
}

const unsigned char* glfwExGetJoystickButtons(int gamepad, int* count)
{
#if defined(PLATFORM_DESKTOP)
	return glfwGetJoystickButtons(gamepad, count);
#else
    return NULL;
#endif
}

const unsigned char* glfwExGetJoystickAxes(int gamepad, int* count)
{
#if defined(PLATFORM_DESKTOP)
	return glfwGetJoystickAxes(gamepad, count);
#else 
    return NULL;
#endif
}