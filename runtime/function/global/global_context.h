#pragma once

#include "core/base/core.h"
#include <memory>
#include <string>

// #include "imgui.h"
// #include "imgui_impl_glfw.h"
// #include "imgui_impl_opengl3.h"

namespace KAIBI 
{
    class LogSystem;
    class WindowSystem;
    class ImguiSystem;
    class RenderSystem;

    class KAPI RuntimeGlobalContext
    {
    public:
        void startSystems();
        void shutdownSystems();

    public:
        std::shared_ptr<LogSystem> m_log_system;
        std::shared_ptr<WindowSystem> m_window_system;
        std::shared_ptr<ImguiSystem> m_imgui_system;
        std::shared_ptr<RenderSystem> m_render_system;
    };

    extern RuntimeGlobalContext g_runtime_global_context;

}