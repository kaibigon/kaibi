#include <d3d12.h>
#include <Windows.h>
#include <winerror.h>
#include <winuser.h>
#include <wrl/client.h>

#include <combaseapi.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <cstdio>

#include "dxcontext.h"
#include "dxdebug_layer.h"
#include "dxwindow.h"

using Microsoft::WRL::ComPtr;

static void AttachDevConsole()
{
    if (!AllocConsole())
    {
        return;
    }
    FILE* dummy = nullptr;
    freopen_s(&dummy, "CONOUT$", "w", stdout);
    freopen_s(&dummy, "CONOUT$", "w", stderr);
    freopen_s(&dummy, "CONIN$", "r", stdin);
    SetConsoleTitleW(L"kaibi - log");
}

static void InitLogger()
{
    auto logger = spdlog::stdout_color_mt("kaibi");
    logger->set_level(spdlog::level::trace);
    logger->set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");
    spdlog::set_default_logger(logger);
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE, PWSTR, int showCmd)
{
    AttachDevConsole();
    InitLogger();

    DXDebugLayer::Get().Init();
    if (DXContext::Get().Init() && DXWindow::Get().Init())
    {
        while (!DXWindow::Get().ShouldClose())
        {
            DXWindow::Get().Update();
            // auto* cmdList = DXContext::Get().InitCommandList();

            // DXContext::Get().ExecuteCommandList();

            // Show me the stuff
        }

        DXWindow::Get().Shutdown();
        DXContext::Get().Shutdown();
    }
    return 0;
}
