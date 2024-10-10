#pragma once

#include "pch.h"
#include "core/base/core.h"
#include "core/log/log_system.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

namespace KAIBI
{
    class KAPI ImguiSystem
    {
    public:
        ImguiSystem();
        ~ImguiSystem();

        void initialize(GLFWwindow* window);
        void shutdown();

        void newFrame();
        void render();
    };
}