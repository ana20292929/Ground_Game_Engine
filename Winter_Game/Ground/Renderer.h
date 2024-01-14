#pragma once

#include "GroundUtil.h"
#include "Shader.h"
#include "Picture.h"
#include "Unit.h"
#include "RendererImplementation.h"

namespace Ground
{
	class GROUND_API Renderer
	{
	public:
		static void Init();
		static Renderer* GetRenderer();

		static void Draw(Picture& picture, int x, int y, int z);
		static void Draw(Picture& picture, int x, int y, int z, Shader& shader);

		static void Draw(Unit& picture);

		static void Clear();


	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplementation* mImplementation;

		Renderer();

		Shader mDefaultShader{ "Assets/Shaders/defaultGroundVertex.glsl", 
			"Assets/Shaders/defaultGroundFragment.glsl" };
	};
}