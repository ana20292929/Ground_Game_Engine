#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../WindowImplementation.h"

namespace Ground {
	class GLFWwindowImplementation : public WindowImplementation {
	public:
		GLFWwindowImplementation();
		virtual void Create(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;

		~GLFWwindowImplementation();

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback) override;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback) override;

	private:
		GLFWwindow* mWindow{ nullptr };

		struct Callbacks
		{
			std::function<void(const KeyPressedEvent&)> keyPressedCallback{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> keyReleasedCallback{ [](const KeyReleasedEvent&) {} };
		} mCallbacks;
	};
}
