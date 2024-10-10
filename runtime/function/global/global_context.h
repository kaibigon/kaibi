#pragma once

#include "core/base/core.h"
#include <memory>
#include <string>

namespace KAIBI 
{
    class LogSystem;
    class WindowSystem;
    class ImguiSystem;

    class KAPI RuntimeGlobalContext
    {
    public:
        void startSystems();
        void shutdownSystems();

    public:
        std::shared_ptr<LogSystem> m_log_system;
        std::shared_ptr<WindowSystem> m_window_system;
        std::shared_ptr<ImguiSystem> m_imgui_system;
    };

    extern RuntimeGlobalContext g_runtime_global_context;

}