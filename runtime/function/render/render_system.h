#pragma once

#include "core/base/core.h"
#include "core/log/log_system.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class GLFWwindow;

// since this is purely for editor, maybe sometime in the future will move this to another place.
namespace KAIBI
{
    class GraphicsContext;
    class KAPI RenderSystem
    {
    public:
        RenderSystem();
        ~RenderSystem();

        void initialize(GLFWwindow* window);
        void shutdown();

        void newFrame();
        void render();

        void swapBuffers();
    private:
        std::shared_ptr<GraphicsContext> m_graphics_context;    
    };
}