#include "global_context.h"
#include "core/log/log_system.h"

#include "function/render/window_system.h"
#include "function/render/imgui_system.h"

namespace KAIBI
{
    RuntimeGlobalContext g_runtime_global_context;

    void RuntimeGlobalContext::startSystems()
    {
        m_log_system = std::make_shared<LogSystem>();

        m_window_system = std::make_shared<WindowSystem>();
        WindowCreateInfo window_create_info;
        m_window_system->initialize(window_create_info);

        m_imgui_system = std::make_shared<ImguiSystem>();
        m_imgui_system->initialize(m_window_system->getWindow());
    }

    void RuntimeGlobalContext::shutdownSystems()
    {
        m_log_system.reset();
        m_window_system.reset();
        m_imgui_system.reset();
    }
}