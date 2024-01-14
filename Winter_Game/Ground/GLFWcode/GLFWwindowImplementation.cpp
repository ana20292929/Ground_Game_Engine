#include "pch.h"

#include "GLFWwindowImplementation.h"
#include "GroundUtil.h"

namespace Ground {
	GLFWwindowImplementation::GLFWwindowImplementation() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	}
	void GLFWwindowImplementation::Create(int width, int height, const std::string& windowName) {
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		glfwMakeContextCurrent(mWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			GROUND_LOG("Failed to initialize GLAD");
		}

		glfwSetWindowUserPointer(mWindow, &mCallbacks);

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyPressedEvent event{ key };
					userPointer->keyPressedCallback(event);
				}
				else if (action == GLFW_RELEASE)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };
					
					KeyReleasedEvent event{ key };
					userPointer->keyReleasedCallback(event);
				}
			}
		);
	}

	void GLFWwindowImplementation::SwapBuffers() {
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}
	GLFWwindowImplementation::~GLFWwindowImplementation() {
		glfwTerminate();
	}
	void GLFWwindowImplementation::SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback)
	{
		mCallbacks.keyPressedCallback = keyPressedCallback;
	}
	void GLFWwindowImplementation::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback)
	{
		mCallbacks.keyReleasedCallback = keyReleasedCallback;
	}
}