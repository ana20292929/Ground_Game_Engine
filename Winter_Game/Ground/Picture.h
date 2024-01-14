#pragma once

#include "pch.h"
#include "GroundUtil.h"
#include "PictureImplementation.h"

namespace Ground
{
	class GROUND_API Picture
	{
	public:
		Picture(const std::string& sourceFile);
		Picture(std::string&& sourceFile);

		int GetHeight() const;
		int GetWidth() const;

		void Activate();


	private:
		PictureImplementation* mImplementation{ nullptr };
	};
}