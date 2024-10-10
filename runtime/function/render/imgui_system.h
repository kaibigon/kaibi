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

	private:
		// bool OnMousePressedEvent(MouseButtonPressedEvent& e);	
		// bool OnMouseReleasedEvent(MouseButtonReleasedEvent& e);
		// bool OnMouseMovedEvent(MouseMovedEvent& e);
		// bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		// bool OnKeyPressedEvent(KeyPressedEvent& e);
		// bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		// bool OnKeyTypedEvent(KeyTypedEvent& e);
		// bool OnWindowResizeEvent(WindowResizeEvent& e);
    };
}