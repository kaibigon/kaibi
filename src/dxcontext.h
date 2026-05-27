#pragma once

#include <d3d12.h>
#include <winnt.h>
#include <wrl/client.h>

#include <basetsd.h>

#ifdef _DEBUG
    #include <d3d12sdklayers.h>
    #include <dxgi1_6.h>
    #include <dxgidebug.h>
#endif

class DXContext
{
public:
    bool Init();
    void Shutdown();
    void SignalAndWait();
    ID3D12GraphicsCommandList7* InitCommandList();
    void ExecuteCommandList();

    inline Microsoft::WRL::ComPtr<ID3D12Device10>& GetDevice() { return m_device; }
    inline Microsoft::WRL::ComPtr<ID3D12CommandQueue>& GetCommandQueue() { return m_cmdQueue; }

private:
    Microsoft::WRL::ComPtr<IDXGIFactory7> m_dxgiFactory;
    Microsoft::WRL::ComPtr<ID3D12Device10> m_device;
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_cmdQueue;
    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_cmdAllocator;
    Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList7> m_cmdlist;

    Microsoft::WRL::ComPtr<ID3D12Fence> m_fence;
    UINT64 m_fenceValue = 0;
    HANDLE m_fenceEvent = nullptr;

public:
    DXContext(const DXContext&)            = delete;
    DXContext& operator=(const DXContext&) = delete;

    inline static DXContext& Get()
    {
        static DXContext instance;
        return instance;
    }

private:
    DXContext() = default;
};