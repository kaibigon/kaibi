#pragma once

#include <dxgi1_6.h>
#include <Windows.h>
#include <wrl/client.h>

#include <ratio>

#include "dxcontext.h"

class DXWindow
{
public:
    bool Init();
    void Update();
    void Present();
    void Resize();
    void Shutdown();

    inline bool ShouldClose() const { return m_shouldClose; }
    inline bool ShouldResize() const { return m_shouldResize; }

    static constexpr size_t GetFrameCount() { return 2; }

private:
    static LRESULT CALLBACK OnWindowMessage(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    ATOM m_wndClass     = 0;
    HWND m_window       = nullptr;
    bool m_shouldClose  = false;
    bool m_shouldResize = false;
    UINT m_width        = 1920;
    UINT m_height       = 1080;

    Microsoft::WRL::ComPtr<IDXGISwapChain3> m_swapChain;
    // singleton
public:
    DXWindow(const DXWindow&)            = delete;
    DXWindow& operator=(const DXWindow&) = delete;

    inline static DXWindow& Get()
    {
        static DXWindow instance;
        return instance;
    }

private:
    DXWindow() = default;
};