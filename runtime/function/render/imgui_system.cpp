#include "pch.h"
#include "imgui_system.h"
#include "function/global/global_context.h"
#include "function/render/window_system.h"

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

        ImGui::StyleColorsDark();
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        ImGui_ImplOpenGL3_Init("#version 410");

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
            LOG_INFO("Imgui Mouse Button: %d, Action: %d, Mods: %d", button, action, mods);
            ImGuiIO& io = ImGui::GetIO();
            switch(action)
            {
                case GLFW_PRESS:
                    io.MouseDown[button] = true;
                    break;
                case GLFW_RELEASE:
                    io.MouseDown[button] = false;
                    break;
            }
        });

        windowSystem->registerOnCursorPosFunc([window](double x, double y)
        {
            LOG_INFO("Imgui Cursor Pos: %f, %f", x, y);
            ImGuiIO& io = ImGui::GetIO();
            io.MousePos = ImVec2(x, y);
        });

        windowSystem->registerOnScrollFunc([window](double x, double y)
        {
            LOG_INFO("Imgui Scroll: %f, %f", x, y);
            ImGuiIO& io = ImGui::GetIO();
            io.MouseWheelH += x;
            io.MouseWheel += y;
        });

        windowSystem->registerOnCharFunc([window](unsigned int codepoint)
        {
            LOG_INFO("Imgui Char: %c", (char)codepoint);
            ImGuiIO& io = ImGui::GetIO();
            io.AddInputCharacter(codepoint);
        });

        windowSystem->registerOnWindowSizeFunc([window](int width, int height)
        {
            LOG_INFO("Imgui Window Size: %d, %d", width, height);
            ImGuiIO& io = ImGui::GetIO();
            io.DisplaySize = ImVec2(width, height);
            io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        });

        windowSystem->registerOnWindowCloseFunc([window]()
        {
            LOG_INFO("Imgui Window Close");
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        });

        windowSystem->registerOnResetFunc([window]()
        {
            LOG_INFO("Imgui Reset");
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        });

        windowSystem->registerOnCharModsFunc([window](int key, unsigned int mods)
        {
            LOG_INFO("Imgui Char Mods: %d, %d", key, mods);
            ImGuiIO& io = ImGui::GetIO();
            io.KeyCtrl = (mods & GLFW_MOD_CONTROL) != 0;
            io.KeyShift = (mods & GLFW_MOD_SHIFT) != 0;
            io.KeyAlt = (mods & GLFW_MOD_ALT) != 0;
            io.KeySuper = (mods & GLFW_MOD_SUPER) != 0;
        });

        windowSystem->registerOnCursorEnterFunc([window](int entered)
        {
            LOG_INFO("Imgui Cursor Enter: %d", entered);
            ImGuiIO& io = ImGui::GetIO();
            io.WantCaptureMouse = entered;
        });


        // Setup Platform/Renderer bindings // test
        // ImGui_ImplGlfw_InitForOpenGL(window, true);

        // binding event ... probably need to setup a proper way to propogate events
        
    }

    void ImguiSystem::shutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        // ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        LOG_INFO("Shutdown ImguiSystem");
    }

    void ImguiSystem::newFrame()
    {
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(1280.0f, 720.0f);
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();
    }

    void ImguiSystem::render()
    {
        ImGui::ShowDemoWindow();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}