#pragma once
#include "core/base/core.h"
#include <string>

namespace KAIBI
{
    class OpenGLShader
    {
    public:
        OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~OpenGLShader();

        void bind() const;
        void unbind() const;

    private:
        uint32_t m_rendererID;

    };
}

