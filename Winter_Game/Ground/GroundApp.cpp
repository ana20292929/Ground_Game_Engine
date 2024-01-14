#include "pch.h"
#include "GroundApp.h"
#include "GroundUtil.h"
#include "GroundWindow.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Picture.h"
#include "Renderer.h"
#include "Keys.h"
#include "Event.h"
#include "Unit.h"

namespace Ground {
	GroundApp::GroundApp()
	{
		GroundWindow::Init();
		GroundWindow::GetWindow()->Create(1000, 800, "Playground");

		Renderer::Init();
	}

	void GroundApp::OnUpdate() {

	}

	void GroundApp::Run() {
		GROUND_LOG("Ground Running!!");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		//Picture pic{ "Assets/Textures/test.png" };

		while (true) //application loop
		{
			//Renderer::Clear();

			OnUpdate(); //OnUpdate() should happen before swapping buffers

			//Ground::Renderer::Draw(pic, 200, 200, 1); //currently the picture isn't showing up properly (NOT WORKING)

			std::this_thread::sleep_until(mNextFrameTime);

			GroundWindow::GetWindow()->SwapBuffers();
			
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}
}