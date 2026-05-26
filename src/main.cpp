#include <d3d12.h>
#include <Windows.h>
#include <winerror.h>
#include <winuser.h>
#include <wrl/client.h>

#include <combaseapi.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <cstdio>

#include "DXDebugLayer.h"

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

    spdlog::info("kaibi starting");
    DXDebugLayer::Get().Init();

    ComPtr<ID3D12Device10> device;
    D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));

    DXDebugLayer::Get().Shutdown();
    POINT p;
    bool running = true;
    while (running)
    {
        GetCursorPos(&p);
        // spdlog::info("x: {}, y: {}", p.x, p.y);
    }
    return 0;
}
