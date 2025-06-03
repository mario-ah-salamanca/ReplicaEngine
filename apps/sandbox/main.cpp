#include <GLFW/glfw3.h>
#include "core/Log.hpp"
#include "core/config.hpp"

static void glfwError(int code, const char* msg)
{
    LOGE("GLFW error ({}): {}", code, msg);
}

int main()
{
    core::Log::init();
    glfwSetErrorCallback(glfwError);

    // 💡 Force Wayland if available (GLFW 3.4 feature)
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);

    if (!glfwInit())
    {
        LOGF("GLFW init failed");
        return -1;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);   // we'll add Vulkan later
    GLFWwindow* win = glfwCreateWindow(1280, 720, "Sandbox", nullptr, nullptr); 
    if (!win)
    {
        LOGF("Window creation failed – see previous GLFW error");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(win);

    if(config::vsync_active){
        glfwSwapInterval(1);
    }else{
        glfwSwapInterval(0);
    }

    glClearColor(0.2f, 0.2f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(win);


    LOGI("Window created (Wayland backend)");

    while (!glfwWindowShouldClose(win)){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(win);
    glfwTerminate();
    LOGI("Good-bye!");
}
