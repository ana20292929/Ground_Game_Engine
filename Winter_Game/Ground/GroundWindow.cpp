#include "pch.h"
#include "GroundWindow.h"
#include "GLFWcode/GLFWwindowImplementation.h"

namespace Ground {
	void GroundWindow::Init() {
		if (mInstance == nullptr) {
			mInstance = new GroundWindow;
#ifdef GROUND_WINDOWS
			mInstance->mImplementation = new GLFWwindowImplementation;
#elif defined GROUND_MAC
			mInstance->mImplementation = new GLFWwindowImplementation;
#else
			mInstance->mImplementation = new GLFWwindowImplementation;
#endif
		}
	}

	GroundWindow* GroundWindow::GetWindow() {
		return mInstance;
	}

	void GroundWindow::Create(int width, int height, const std::string& windowName) {
		mImplementation->Create(width, height, windowName);

		mWidth = width;
		mHeight = height;
	}

	void GroundWindow::SwapBuffers() {
		mImplementation->SwapBuffers();
	}

	int GroundWindow::GetWidth() const
	{
		return mWidth;
	}

	int GroundWindow::GetHeight() const
	{
		return mHeight;
	}

	void GroundWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback)
	{
		mImplementation->SetKeyPressedCallback(keyPressedCallback);
	}

	void GroundWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
	{
		mImplementation->SetKeyReleasedCallback(keyReleasedCallback);
	}

	
}