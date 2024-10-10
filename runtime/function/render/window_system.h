#pragma once

#include "pch.h"
#include "core/base/core.h"
#include "core/event/event.h"
#include <GLFW/glfw3.h>

namespace KAIBI
{
    struct WindowCreateInfo
    {
        int width{1280};
        int height{720};
        std::string title{"Kaibi Engine"};
        bool isFullScreen{false};
    };

    class KAPI WindowSystem
    {
    public:
        WindowSystem();
        ~WindowSystem();

        void            initialize(const WindowCreateInfo& info);
        void            pollEvents() const;
        bool            shouldClose() const; 
        GLFWwindow*     getWindow() const;


    private:
        GLFWwindow* m_Window;
        int         m_Width {0};
        int         m_Height {0};
    };
}