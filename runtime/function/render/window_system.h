#pragma once

#include "pch.h"
#include "core/base/core.h"
#include "core/log/log_system.h"
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
        // typedef std::function<void(Event&)> EventCallbackFn;

        WindowSystem();
        ~WindowSystem();

        void            initialize(const WindowCreateInfo& info);
        void            pollEvents() const;
        bool            shouldClose() const; 
        GLFWwindow*     getWindow() const;        
        std::array<int, 2> getWindowSize() const;

        typedef std::function<void()>                   onResetFunc;
        typedef std::function<void(int, int, int, int)> onKeyFunc;
        typedef std::function<void(unsigned int)>       onCharFunc;
        typedef std::function<void(int, unsigned int)>  onCharModsFunc;
        typedef std::function<void(int, int, int)>      onMouseButtonFunc;
        typedef std::function<void(double, double)>     onCursorPosFunc;
        typedef std::function<void(int)>                onCursorEnterFunc;
        typedef std::function<void(double, double)>     onScrollFunc;
        typedef std::function<void(int, const char**)>  onDropFunc;
        typedef std::function<void(int, int)>           onWindowSizeFunc;
        typedef std::function<void()>                   onWindowCloseFunc;

        void registerOnResetFunc(onResetFunc func)              { m_onResetFunc.push_back(func); }
        void registerOnKeyFunc(onKeyFunc func)                  { m_onKeyFunc.push_back(func); }
        void registerOnCharFunc(onCharFunc func)                { m_onCharFunc.push_back(func); }
        void registerOnCharModsFunc(onCharModsFunc func)        { m_onCharModsFunc.push_back(func); }
        void registerOnMouseButtonFunc(onMouseButtonFunc func)  { m_onMouseButtonFunc.push_back(func); }
        void registerOnCursorPosFunc(onCursorPosFunc func)      { m_onCursorPosFunc.push_back(func); }
        void registerOnCursorEnterFunc(onCursorEnterFunc func)  { m_onCursorEnterFunc.push_back(func); }
        void registerOnScrollFunc(onScrollFunc func)            { m_onScrollFunc.push_back(func); }
        void registerOnDropFunc(onDropFunc func)                { m_onDropFunc.push_back(func); }
        void registerOnWindowSizeFunc(onWindowSizeFunc func)    { m_onWindowSizeFunc.push_back(func); }
        void registerOnWindowCloseFunc(onWindowCloseFunc func)  { m_onWindowCloseFunc.push_back(func); }

        bool isMouseButtonDown(int button) const
        {
            if (button < GLFW_MOUSE_BUTTON_1 || button > GLFW_MOUSE_BUTTON_LAST)
            {
                return false;
            }
            return glfwGetMouseButton(m_window, button) == GLFW_PRESS;
        }

    protected:
        // window event callbacks
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void charCallback(GLFWwindow* window, unsigned int codepoint);
        static void charModsCallback(GLFWwindow* window, unsigned int codepoint, int mods);
        static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
        static void cursorEnterCallback(GLFWwindow* window, int entered);
        static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
        static void dropCallback(GLFWwindow* window, int count, const char** paths);
        static void windowSizeCallback(GLFWwindow* window, int width, int height);
        static void windowCloseCallback(GLFWwindow* window);

        void onReset();

        void onKey(int key, int scancode, int action, int mods);

        void onChar(unsigned int codepoint);

        void onCharMods(int codepoint, unsigned int mods);

        void onMouseButton(int button, int action, int mods);

        void onCursorPos(double xpos, double ypos);

        void onCursorEnter(int entered);

        void onScroll(double xoffset, double yoffset);

        void onDrop(int count, const char** paths);

        void onWindowSize(int width, int height);

    private:
        GLFWwindow* m_window;
        int         m_width {0};
        int         m_height {0};

        std::vector<onResetFunc>       m_onResetFunc;
        std::vector<onKeyFunc>         m_onKeyFunc;
        std::vector<onCharFunc>        m_onCharFunc;
        std::vector<onCharModsFunc>    m_onCharModsFunc;
        std::vector<onMouseButtonFunc> m_onMouseButtonFunc;
        std::vector<onCursorPosFunc>   m_onCursorPosFunc;
        std::vector<onCursorEnterFunc> m_onCursorEnterFunc;
        std::vector<onScrollFunc>      m_onScrollFunc;
        std::vector<onDropFunc>        m_onDropFunc;
        std::vector<onWindowSizeFunc>  m_onWindowSizeFunc;
        std::vector<onWindowCloseFunc> m_onWindowCloseFunc;
    };
}