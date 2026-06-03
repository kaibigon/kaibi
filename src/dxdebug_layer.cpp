#include "dxdebug_layer.h"

#include <spdlog/spdlog.h>

#include <cstddef>

bool DXDebugLayer::Init()
{
#ifdef _DEBUG
    // Init D3D12 Debug Layer
    if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&m_d3d12Debug))))
    {
        m_d3d12Debug->EnableDebugLayer();

        // Init DXGI Debug (detect leak)
        if (SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&m_dxgiDebug))))
        {
            m_dxgiDebug->EnableLeakTrackingForThread();
            return true;
        }
    }
#endif
    return false;
}

void DXDebugLayer::Shutdown()
{
#ifdef _DEBUG
    if (m_dxgiDebug)
    {
        spdlog::info("report live objects");
        m_dxgiDebug->ReportLiveObjects(
            DXGI_DEBUG_ALL,
            DXGI_DEBUG_RLO_FLAGS(DXGI_DEBUG_RLO_DETAIL | DXGI_DEBUG_RLO_IGNORE_INTERNAL)
        );
    }
    if (m_dxgiDebug != nullptr)
    {
        // m_dxgiDebug->Release();
        m_dxgiDebug = nullptr;
    }

    if (m_d3d12Debug != nullptr)
    {
        // m_d3d12Debug->Release();
        m_d3d12Debug = nullptr;
    }
#endif
}