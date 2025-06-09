#pragma once
#include "pch.h"

namespace KAIBI
{
    class Timer
    {
    public:
        Timer()
        {
            Reset();
        }

        void Reset()
        {
            m_StartTime = std::chrono::high_resolution_clock::now();
            m_LastFrameTime = m_StartTime;
            m_FrameCount = 0;
            m_FPS = 0;
            m_DeltaTime = 0.0f;
        }

        void Update()
        {
            auto currentTime = std::chrono::high_resolution_clock::now();
            m_DeltaTime = std::chrono::duration<float>(currentTime - m_LastFrameTime).count();
            m_LastFrameTime = currentTime;

            m_FrameCount++;
            float time = std::chrono::duration<float>(currentTime - m_StartTime).count();
            if (time >= 1.0f)
            {
                m_FPS = m_FrameCount;
                m_FrameCount = 0;
                m_StartTime = currentTime;
            }
        }

        float GetDeltaTime() const { return m_DeltaTime; }
        uint32_t GetFPS() const { return m_FPS; }
        float GetTime() const 
        { 
            return std::chrono::duration<float>(
                std::chrono::high_resolution_clock::now() - m_StartTime
            ).count();
        }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_LastFrameTime;
        uint32_t m_FrameCount;
        uint32_t m_FPS;
        float m_DeltaTime;
    };
} 