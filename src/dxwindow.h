#pragma once

#include <d3d12.h>
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
    void SetFullScreen(bool enabled);

    void BeginFrame(ID3D12GraphicsCommandList7* cmdList);
    void EndFrame(ID3D12GraphicsCommandList7* cmdList);

    inline bool ShouldClose() const { return m_shouldClose; }
    inline bool ShouldResize() const { return m_shouldResize; }
    inline bool IsFullScreen() const { return m_isFullScreen; }

    static constexpr size_t FrameCount = 2;
    static constexpr size_t GetFrameCount() { return FrameCount; }

private:
    bool GetBuffers();
    void ReleaseBuffers();
    static LRESULT CALLBACK OnWindowMessage(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    ATOM m_wndClass             = 0;
    HWND m_window               = nullptr;
    bool m_shouldClose          = false;
    bool m_shouldResize         = false;
    bool m_isFullScreen         = false;
    UINT m_width                = 1920;
    UINT m_height               = 1080;
    size_t m_currentBufferIndex = 0;

    Microsoft::WRL::ComPtr<IDXGISwapChain3> m_swapChain;
    Microsoft::WRL::ComPtr<ID3D12Resource2> m_buffers[FrameCount];
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_rtvDescHeap;
    D3D12_CPU_DESCRIPTOR_HANDLE m_rtvHandles[FrameCount];

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