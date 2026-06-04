#include "dxcontext.h"

#include <d3d12.h>
#include <winbase.h>
#include <winerror.h>

#include <combaseapi.h>
#include <handleapi.h>
#include <processthreadsapi.h>
#include <spdlog/spdlog.h>
#include <synchapi.h>

#include <cstddef>
#include <cstdlib>

bool DXContext::Init()
{
    if (FAILED(CreateDXGIFactory2(0, IID_PPV_ARGS(&m_dxgiFactory))))
    {
        return false;
    }

    if (FAILED(D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device))))
    {
        return false;
    }

    D3D12_COMMAND_QUEUE_DESC commandQueueDesc{};
    commandQueueDesc.Type     = D3D12_COMMAND_LIST_TYPE_DIRECT;
    commandQueueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_HIGH;
    commandQueueDesc.NodeMask = 0;
    commandQueueDesc.Flags    = D3D12_COMMAND_QUEUE_FLAG_NONE;

    if (FAILED(m_device->CreateCommandQueue(&commandQueueDesc, IID_PPV_ARGS(&m_cmdQueue))))
    {
        return false;
    }

    if (FAILED(m_device->CreateFence(m_fenceValue, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence))))
    {
        // m_fenceEvent = CreateEvent(NULL, false, false, nullptr);
        // return m_fenceEvent != nullptr;
        return false;
    }

    m_fenceEvent = CreateEvent(NULL, false, false, nullptr);
    if (!m_fenceEvent)
    {
        return false;
    }

    if (FAILED(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_cmdAllocator))))
    {
        return false;
    }

    if (FAILED(m_device->CreateCommandList1(
            0,
            D3D12_COMMAND_LIST_TYPE_DIRECT,
            D3D12_COMMAND_LIST_FLAG_NONE,
            IID_PPV_ARGS(&m_cmdlist)
        )))
    {
        return false;
    }

    return true;
}

void DXContext::Shutdown()
{
    if (m_cmdAllocator != nullptr)
    {
        m_cmdAllocator = nullptr;
    }
    if (m_cmdlist != nullptr)
    {
        m_cmdlist = nullptr;
    }
    if (m_fenceEvent)
    {
        CloseHandle(m_fenceEvent);
    }

    if (m_cmdQueue != nullptr)
    {
        m_cmdQueue = nullptr;
    }

    if (m_device != nullptr)
    {
        m_device = nullptr;
    }
}

void DXContext::SignalAndWait()
{
    m_cmdQueue->Signal(m_fence.Get(), ++m_fenceValue);
    if (SUCCEEDED(m_fence->SetEventOnCompletion(m_fenceValue, m_fenceEvent)))
    {
        if (WaitForSingleObject(m_fenceEvent, 20000) != WAIT_OBJECT_0)
        {
            spdlog::info("error");
            std::exit(-1);
        }
    }
    else
    {
        spdlog::info("error");
        std::exit(-1);
    }
}

ID3D12GraphicsCommandList7* DXContext::InitCommandList()
{
    spdlog::info("init cmdlist");
    m_cmdAllocator.Get()->Reset();
    m_cmdlist.Get()->Reset(m_cmdAllocator.Get(), nullptr);
    return m_cmdlist.Get();
}

void DXContext::ExecuteCommandList()
{
    if (SUCCEEDED(m_cmdlist->Close()))
    {
        spdlog::info("executing cmdlist");
        ID3D12CommandList* lists[] = {m_cmdlist.Get()};
        m_cmdQueue->ExecuteCommandLists(1, lists);
        SignalAndWait();
    }
}