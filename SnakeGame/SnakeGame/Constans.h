#pragma once
#include <string>

namespace SnakeGame
{
	// Resources path
	const std::string RESOURCES_PATH = "Resources/";
	const std::string TEXTURES_PATH = RESOURCES_PATH + "Textures/";
	const std::string FONTS_PATH = RESOURCES_PATH + "Fonts/";
	const std::string SOUNDS_PATH = RESOURCES_PATH + "Sounds/";
	const std::string MUSIC_PATH = RESOURCES_PATH + "Musics/";

	// Game settings constants
	const float SNAKE_SIZE = 20.f;
	const unsigned int INITIAL_SNAKE_SIZE = 3;
	const unsigned int APPLE_SIZE = 20;
	const unsigned int ROCK_SIZE = 15;
	const unsigned int WALL_SIZE = 40;
	const unsigned int RECT_INDENT = 80;
	const float INITIAL_SPEED = 200.f;	// 
	const float ACCELERATION = 10.f;	// For each eaten apple snake speed will be increased by this value
	const int MIN_APPLES = 40;
	const int MAX_APPLES = 80;
	const unsigned int SCREEN_WIDTH = 800;
	const unsigned int SCREEN_HEGHT = 600;
	const float TIME_PER_FRAME = 1.f / 60.f; // 60 fps
	const unsigned int ROCKS_COUNT = 20;
	const unsigned int ROCKS_COUNT_X = 50;
	const unsigned int ROCKS_COUNT_Y = 40;

	
	const float LOW_DIFFICULT_MULTIPLAYER = 0.5f;
	const float LOWUP_DIFFICULT_MULTIPLAYER = 0.75f;
	const float MEDIUM_DIFFICULT_MULTIPLAYER = 1.f;
	const float HARDLOW_DIFFICULT_MULTIPLAYER = 1.5f;
	const float HARD_DIFFICULT_MULTIPLAYER = 2.f;

	const int SCORE_COUNT = 50;
	const int MAX_RECORDS_TABLE_SIZE = 5;
	extern const char* PLAYER_NAME; // We need to define this constant in some SPP
}
