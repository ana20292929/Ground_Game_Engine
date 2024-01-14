#pragma once

#include "GroundUtil.h"
#include "Picture.h"

namespace Ground
{
	class GROUND_API Unit
	{
	public:
		Unit(const std::string& picFile, int hp);
		Unit(std::string&& picFile, int hp);

		void SetCoord(int x, int y, int z);

		int ChangeX(int xDiff); //adds xDiff to the current X and returns the new X value
		int ChanceY(int yDiff);
		int ChangeZ(int zDiff);

		int GetX() const;
		int GetY() const;
		int GetZ() const;

		int ChangeHP(int hpDiff); //adds hpDiff to the current HP and returns new HP
		int GetHP() const;

		bool OverlapsWith(const Unit& other) const; //collision detection

	private:
		Picture mPicture; //picture of the unit
		int mXcoord{ 0 };
		int mYcoord{ 0 };
		int mZcoord{ 0 };
		int mHP{ 0 };

		friend class Renderer;
	};
}