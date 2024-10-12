#include "core/base/core.h"
#include <GLFW/glfw3.h>

namespace KAIBI
{
    class KAPI OpenGLContext
    {
    public:
        OpenGLContext();
        void initialize(GLFWwindow* window);
        void swapBuffers();

    private:
        GLFWwindow* m_window;
    };
}