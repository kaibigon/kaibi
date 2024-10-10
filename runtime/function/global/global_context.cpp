#include "global_context.h"
#include "core/log/logger.h"

namespace KAIBI
{
    RuntimeGlobalContext g_runtime_global_context;

    void RuntimeGlobalContext::startSystems()
    {
        m_log_system = std::make_shared<LogSystem>();
    }

    void RuntimeGlobalContext::shutdownSystems()
    {
        m_log_system.reset();
    }
}