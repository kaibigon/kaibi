#include "pch.h"
#include "imgui_system.h"
#include "function/global/global_context.h"
#include "function/render/window_system.h"

#include <GLFW/glfw3.h>

namespace KAIBI
{
    ImguiSystem::ImguiSystem()
    {
    }

    ImguiSystem::~ImguiSystem()
    {
        shutdown();
    }

    void ImguiSystem::initialize(GLFWwindow* window)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;        // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");


        // put these to an event place 
        std::shared_ptr<WindowSystem> windowSystem = g_runtime_global_context.m_window_system;
        windowSystem->registerOnKeyFunc([window](int key, int scancode, int action, int mods)
        {
            ImGuiIO& io = ImGui::GetIO();
            switch(action)
            {
                case GLFW_PRESS:
                    io.KeysDown[key] = true;
                    break;
                case GLFW_RELEASE:
                    io.KeysDown[key] = false;
                    break;
            }
        });

        windowSystem->registerOnMouseButtonFunc([window](int button, int action, int mods)
        {
            ImGuiIO& io = ImGui::GetIO();
            switch(action)
            {
                case GLFW_PRESS:
                    io.MouseDown[button] = true;
                    // LOG_INFO("Imgui Mouse Button: %d, Action: %d, Mods: %d", button, action, mods);
                    break;
                case GLFW_RELEASE:
                    io.MouseDown[button] = false;
                    break;
            }
        });

        windowSystem->registerOnCursorPosFunc([window](double x, double y)
        {
            // LOG_INFO("Imgui Cursor Pos: %f, %f", x, y);
            ImGuiIO& io = ImGui::GetIO();
            io.MousePos = ImVec2(x, y);
        });

        windowSystem->registerOnScrollFunc([window](double x, double y)
        {
            // LOG_INFO("Imgui Scroll: %f, %f", x, y);
            ImGuiIO& io = ImGui::GetIO();
            io.MouseWheelH += x;
            io.MouseWheel += y;
        });

        windowSystem->registerOnCharFunc([window](unsigned int codepoint)
        {
            // LOG_INFO("Imgui Char: %c", (char)codepoint);
            ImGuiIO& io = ImGui::GetIO();
            io.AddInputCharacter(codepoint);
        });

        windowSystem->registerOnWindowSizeFunc([window](int width, int height)
        {
            // LOG_INFO("Imgui Window Size: %d, %d", width, height);
            ImGuiIO& io = ImGui::GetIO();
            io.DisplaySize = ImVec2(width, height);
            io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        });

        windowSystem->registerOnWindowCloseFunc([window]()
        {
            // LOG_INFO("Imgui Window Close");
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        });

        windowSystem->registerOnResetFunc([window]()
        {
            // LOG_INFO("Imgui Reset");
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        });

        windowSystem->registerOnCharModsFunc([window](int key, unsigned int mods)
        {
            // LOG_INFO("Imgui Char Mods: %d, %d", key, mods);
            ImGuiIO& io = ImGui::GetIO();
            io.KeyCtrl = (mods & GLFW_MOD_CONTROL) != 0;
            io.KeyShift = (mods & GLFW_MOD_SHIFT) != 0;
            io.KeyAlt = (mods & GLFW_MOD_ALT) != 0;
            io.KeySuper = (mods & GLFW_MOD_SUPER) != 0;
        });

        windowSystem->registerOnCursorEnterFunc([window](int entered)
        {
            ImGuiIO& io = ImGui::GetIO();
            io.WantCaptureMouse = entered;
        });

        // binding event ... probably need to setup a proper way to propogate events
        
    }

    void ImguiSystem::shutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImguiSystem::newFrame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImguiSystem::render()
    {
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(1280.0f, 720.0f);
        ImGui::ShowDemoWindow();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

    }
}