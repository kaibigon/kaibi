#include "pch.h"
#include "function/render/opengl_buffer.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace KAIBI
{

    OpenGLBuffer::OpenGLBuffer(const float* vertices, unsigned int vertexCount, const unsigned int* indices, unsigned int indexCount)
    {
        glGenVertexArrays(1, &m_VAO);        
        glBindVertexArray(m_VAO);

        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);

        glGenBuffers(1, &m_EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

        glBindVertexArray(0);
    }
    
    OpenGLBuffer::~OpenGLBuffer()
    {
        glDeleteVertexArrays(1, &m_VAO);
        glDeleteBuffers(1, &m_VBO);
        glDeleteBuffers(1, &m_EBO);
    }

    void OpenGLBuffer::bind()
    {
        glBindVertexArray(m_VAO);
    }

    void OpenGLBuffer::unbind()
    {
        glBindVertexArray(0);
    }   
    
    // testing code
    void OpenGLBuffer::draw()
    {
        glBindVertexArray(m_VAO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
}
