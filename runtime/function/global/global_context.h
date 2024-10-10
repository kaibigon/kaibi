#pragma once

#include "core/base/core.h"
#include <memory>
#include <string>

namespace KAIBI 
{
    class LogSystem;

    class KAPI RuntimeGlobalContext
    {
    public:
        void startSystems();
        void shutdownSystems();

    public:
        std::shared_ptr<LogSystem> m_log_system;
    };

    extern RuntimeGlobalContext g_runtime_global_context;

}