#include "core/base/core.h"
#include "core/log/log_system.h"
#include <memory>

#include <GLFW/glfw3.h>

namespace KAIBI
{
    class OpenGLContext;

    class KAPI RenderSystem
    {
    public:
        RenderSystem();
        ~RenderSystem();

        void initialize(GLFWwindow* window);
        void shutdown();

        void render();

    private:
        std::shared_ptr<OpenGLContext> m_opengl_context;
    };
}