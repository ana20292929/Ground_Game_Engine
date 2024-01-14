#include "pch.h"
#include "Renderer.h"
#include "OpenGLcode/OpenGLRenderer.h"

namespace Ground
{
	void Renderer::Init()
	{
		if (mInstance == nullptr)
			mInstance = new Renderer;
	}

	Renderer* Renderer::GetRenderer()
	{
		return mInstance;
	}

	void Renderer::Draw(Picture& picture, int x, int y, int z)
	{
		GetRenderer()->mImplementation->Draw(picture, x, y, z, GetRenderer()->mDefaultShader);
	}

	void Renderer::Draw(Picture& picture, int x, int y, int z, Shader& shader)
	{
		GetRenderer()->mImplementation->Draw(picture, x, y, z, shader);
	}

	void Renderer::Draw(Unit& picture)
	{
		GetRenderer()->mImplementation->Draw(picture.mPicture, picture.GetX(), picture.GetY(), picture.GetZ(), GetRenderer()->mDefaultShader);
	}

	void Renderer::Clear()
	{
		GetRenderer()->mImplementation->Clear();
	}

	Renderer::Renderer()
	{
#ifdef GROUND_OPENGL
		mImplementation = new OpenGLRenderer{};
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}
}