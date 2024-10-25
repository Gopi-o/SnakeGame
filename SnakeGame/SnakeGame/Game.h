#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"

#include "Snake.h"
#include "Sprite.h"
#include "Constans.h"
#include <unordered_map>

namespace SnakeGame
{
	enum class GameOptions : std::uint8_t
	{
		InfiniteApples = 1 << 0,
		WithAcceleration = 1 << 1,
		StaticWall = 1 << 2,
		Sound = 1 << 3, 
		Music = 1 << 4,


		Default = InfiniteApples | WithAcceleration | StaticWall | Sound | Music,
		Empty = 0
	};

	enum class Difficulty : std::uint8_t
	{
		Low = 0,
		LowUp = 1,
		Medium = 2,
		HardLow = 3,
		Hard = 4
	};

	enum class GameStateType
	{
		None = 0,
		MainMenu,
		Playing,
		GameOver,
		ExitDialog,
		Records,
	};

	struct GameState
	{
		GameStateType type = GameStateType::None;
		void* data = nullptr;
		bool isExclusivelyVisible = false;
	};


	enum class GameStateChangeType
	{
		None,
		Push,
		Pop,
		Switch
	};

	struct Game
	{
		std::vector<GameState> gameStateStack;
		GameStateChangeType gameStateChangeType = GameStateChangeType::None;
		GameStateType pendingGameStateType = GameStateType::None;
		bool pendingGameStateIsExclusivelyVisible = false;

		GameOptions options = GameOptions::Default;
		Difficulty CurrentDifficult = Difficulty::Low;
		std::unordered_map<std::string, int> recordsTable;

		//Buffers
		sf::SoundBuffer TouchButtonSoundBuffer;
		sf::SoundBuffer EscButtonSoundBuffer;
		sf::SoundBuffer GuidButtonSoundBuffer;

		// Sounds
		sf::Sound TouchButtonSound;
		sf::Sound EscButtonSound;
		sf::Sound GuidButtonSound;

		//Musics
		sf::Music MenuBackground;
		sf::Music GameBackground;

		bool bIsSoundOn = true;
		bool bisMusicOn = true;
	};

	
	void InitGame(Game& game);
	void HandleWindowEvents(Game& game, sf::RenderWindow& window);
	bool UpdateGame(Game& game, float timeDelta); // Return false if game should be closed
	void DrawGame(Game& game, sf::RenderWindow& window);
	void ShutdownGame(Game& game);

	// Add new game state on top of the stack
	void PushGameState(Game& game, GameStateType stateType, bool isExclusivelyVisible);

	// Remove current game state from the stack
	void PopGameState(Game& game);

	// Remove all game states from the stack and add new one
	void SwitchGameState(Game& game, GameStateType newState);

	void InitGameState(Game& game, GameState& state);
	void ShutdownGameState(Game& game, GameState& state);
	void HandleWindowEventGameState(Game& game, GameState& state, sf::Event& event);
	void UpdateGameState(Game& game, GameState& state, float timeDelta);
	void DrawGameState(Game& game, GameState& state, sf::RenderWindow& window);
}
