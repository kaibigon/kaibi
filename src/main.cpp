#include <d3d12.h>
#include <Windows.h>
#include <winerror.h>
#include <winuser.h>
#include <wrl/client.h>

#include <combaseapi.h>
#include <spdlog/sinks/null_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <cstdio>
#include <memory>

#include "dxcontext.h"
#include "dxdebug_layer.h"
#include "dxwindow.h"

using Microsoft::WRL::ComPtr;

// Set to 0 to re-enable the spdlog console window.
#define KAIBI_DISABLE_CONSOLE 1

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
#if KAIBI_DISABLE_CONSOLE
    auto nullSink = std::make_shared<spdlog::sinks::null_sink_mt>();
    spdlog::set_default_logger(std::make_shared<spdlog::logger>("kaibi", nullSink));
#else
    auto logger = spdlog::stdout_color_mt("kaibi");
    logger->set_level(spdlog::level::trace);
    logger->set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");
    spdlog::set_default_logger(logger);
#endif
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE, PWSTR, int showCmd)
{
#if !KAIBI_DISABLE_CONSOLE
    AttachDevConsole();
#endif
    InitLogger();

    DXDebugLayer::Get().Init();
    if (DXContext::Get().Init() && DXWindow::Get().Init())
    {
        while (!DXWindow::Get().ShouldClose())
        {
            // Process pending window message
            DXWindow::Get().Update();

            // Handling resizing
            if (DXWindow::Get().ShouldResize())
            {
                DXContext::Get().Flush(DXWindow::GetFrameCount());
                DXWindow::Get().Resize();
            }

            // TODO: draw

            // auto* cmdList = DXContext::Get().InitCommandList();
            // DXContext::Get().ExecuteCommandList();

            // Show me the stuff
            DXWindow::Get().Present();
        }
        // Flushing
        DXContext::Get().Flush(DXWindow::GetFrameCount());

        DXWindow::Get().Shutdown();
        DXContext::Get().Shutdown();
    }
    return 0;
}
