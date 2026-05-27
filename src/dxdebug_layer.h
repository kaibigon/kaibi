#pragma once

#include <d3d12.h>
#include <wrl/client.h>

#ifdef _DEBUG
    #include <d3d12sdklayers.h>
    #include <dxgi1_3.h>
    #include <dxgidebug.h>
#endif

class DXDebugLayer
{
public:
    bool Init();
    void Shutdown();

private:
#ifdef _DEBUG
    Microsoft::WRL::ComPtr<ID3D12Debug6> m_d3d12Debug;
    Microsoft::WRL::ComPtr<IDXGIDebug1> m_dxgiDebug;
#endif

public:
    DXDebugLayer(const DXDebugLayer&)            = delete;
    DXDebugLayer& operator=(const DXDebugLayer&) = delete;

    inline static DXDebugLayer& Get()
    {
        static DXDebugLayer instance;
        return instance;
    }

private:
    DXDebugLayer() = default;
};