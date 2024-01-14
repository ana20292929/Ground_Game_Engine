#pragma once

#include "pch.h"
#include "GroundUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace Ground 
{
	class GROUND_API GroundApp 
	{
	public:
		GroundApp();
		virtual void OnUpdate();
		void Run();
	
	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}

