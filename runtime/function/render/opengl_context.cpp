// #include "pch.h"
// #include "opengl_context.h"
// // #include "function/render/window_system.h"

// #include <GLFW/glfw3.h>
// #include <glad/glad.h>

// namespace KAIBI
// {
//     OpenGLContext::OpenGLContext()
//     {
//     }

//     void OpenGLContext::initialize(GLFWwindow* window)
//     {
//         m_window = window;
//         glfwMakeContextCurrent(m_window);
//         int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
//         LOG_INFO("Glad load opengl Info: %d", status);
//     }

//     void OpenGLContext::swapBuffers() 
//     {
//         glfwSwapBuffers(m_window);
//     }
// }