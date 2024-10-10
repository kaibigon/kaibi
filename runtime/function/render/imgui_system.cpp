#include "imgui_system.h"

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

        ImGui_ImplOpenGL3_Init("#version 410");

        // Setup Platform/Renderer bindings // test
        // ImGui_ImplGlfw_InitForOpenGL(window, true);
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
        ImGui::NewFrame();
    }

    void ImguiSystem::render()
    {
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(1280.0f, 720.0f);
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        ImGui::ShowDemoWindow();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}