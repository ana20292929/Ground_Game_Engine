#pragma once

#define START_GROUND_GAME_ENGINE(GameClass) \
	int main()\
	{ \
		GameClass ground_game;\
		ground_game.Run();\
		return 0;\
	}

#ifdef GROUND_WINDOWS
	#ifdef GROUND_LIB
		#define GROUND_API __declspec(dllexport)
	#else
		#define GROUND_API __declspec(dllimport)
	#endif
#else
	#define GROUND_API
#endif

#ifdef GROUND_DEBUG
	#define GROUND_LOG(x) std::cout<< x<<std::endl;
#else
	#define GROUND_LOG(x)
#endif