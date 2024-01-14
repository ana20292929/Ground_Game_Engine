#pragma once

#include "pch.h"
#include "GroundUtil.h"
#include "WindowImplementation.h"
#include "Event.h"

namespace Ground {
	class GROUND_API GroundWindow {
	public:
		static void Init();
		static GroundWindow* GetWindow();

		virtual void Create(int width, int height, const std::string& windowName);
		virtual void SwapBuffers();

		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);

	private:
		GroundWindow(){};

		inline static GroundWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}