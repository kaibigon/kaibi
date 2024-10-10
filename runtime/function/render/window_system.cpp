#include "pch.h"
#include "window_system.h"

#include "core/event/event.h"
#include "GLFW/glfw3.h"

namespace KAIBI
{
    WindowSystem::WindowSystem()
        : m_Window(nullptr)
    {
    }

    WindowSystem::~WindowSystem()
    {
    }

    void WindowSystem::initialize(const WindowCreateInfo& info)
    {
        m_Width = info.width;
        m_Height = info.height;

        if (!glfwInit())
        {
            return;
        }

        m_Window = glfwCreateWindow(m_Width, m_Height, info.title.c_str(), nullptr, nullptr);

        if (!m_Window)
        {
            glfwTerminate();
            return;
        }

        // set up event call back here
    }

    void WindowSystem::pollEvents() const
    {
        glfwPollEvents();
    }

    bool WindowSystem::shouldClose() const
    {
        return glfwWindowShouldClose(m_Window);
    }

    GLFWwindow* WindowSystem::getWindow() const
    {
        return m_Window;
    }

}