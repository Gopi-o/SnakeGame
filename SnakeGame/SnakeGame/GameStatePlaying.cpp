#include "GameStatePlaying.h"
#include "Game.h"
#include "Text.h"
#include <assert.h>
#include <sstream>

namespace SnakeGame
{
	float wallVisibleDuration = 5.0f; 
	float wallHiddenDuration = 3.0f;   
	bool wallsVisible = true;          
	sf::Clock wallClock;                

	void InitGameStatePlaying(GameStatePlayingData& data, Game& game)
	{	
		// Init game resources (terminate if error)
		LoadSnakeTextures(data.snake);
		assert(data.appleTexture.loadFromFile(TEXTURES_PATH + "Apple.png"));
		assert(data.rockTexture.loadFromFile(TEXTURES_PATH + "Wall.png"));
		//assert(data.WallTexture.loadFromFile(TEXTURES_PATH + "Wall.png"));
		assert(data.font.loadFromFile(FONTS_PATH + "Roboto-Regular.ttf"));
		assert(data.eatAppleSoundBuffer.loadFromFile(SOUNDS_PATH + "AppleEat.wav"));
		assert(data.gameOverSoundBuffer.loadFromFile(SOUNDS_PATH + "Death.wav"));

		// Init background
		data.background.setSize(sf::Vector2f(SCREEN_WIDTH - 40, SCREEN_HEGHT - 65));
		data.background.setPosition(15.f, 45.f);
		data.background.setFillColor(sf::Color(51, 102, 0));

		// Init snake
		InitSnake(data.snake, game);

		// Init apple
		InitSprite(data.apple, APPLE_SIZE, APPLE_SIZE, data.appleTexture);
		SetSpriteRandomPosition(data.apple, data.background.getGlobalBounds(), data.snake.body);

		// Init rocks
		if ((std::uint8_t)game.options & (std::uint8_t)GameOptions::StaticWall)
		{
			data.rocks.clear(); 
			// Top Wall
			for (int i = 0; i < ROCKS_COUNT_X; ++i) {
				sf::Sprite topWall(data.rockTexture);
				topWall.setPosition(i * ROCK_SIZE + 26.f, 50.f); 
				InitSprite(topWall, ROCK_SIZE, ROCK_SIZE, data.rockTexture);
				data.rocks.push_back(topWall);
			}

			// Down Wall
			for (int i = 0; i < ROCKS_COUNT_X; ++i) {
				sf::Sprite bottomWall(data.rockTexture);
				bottomWall.setPosition(i * ROCK_SIZE + 26.f, SCREEN_HEGHT - ROCK_SIZE * 2.f);
				InitSprite(bottomWall, ROCK_SIZE, ROCK_SIZE, data.rockTexture); 
				data.rocks.push_back(bottomWall);
			}

			// Left Wall
			for (int i = 0; i < ROCKS_COUNT_Y; ++i) {
				sf::Sprite leftWall(data.rockTexture);
				leftWall.setRotation(90); 
				leftWall.setPosition(15.f, static_cast<float>(i) * ROCK_SIZE);
				InitSprite(leftWall, ROCK_SIZE, ROCK_SIZE, data.rockTexture); 
				data.rocks.push_back(leftWall);
			}

			// Right Wall
			for (int i = 0; i < ROCKS_COUNT_Y; ++i) {
				sf::Sprite rightWall(data.rockTexture);
				rightWall.setRotation(90); 
				rightWall.setPosition(SCREEN_WIDTH - ROCK_SIZE * 2.f, static_cast<float>(i) * ROCK_SIZE);
				InitSprite(rightWall, ROCK_SIZE, ROCK_SIZE, data.rockTexture); 
				data.rocks.push_back(rightWall);
			}
		}
		else
		{

			data.rocks.resize(ROCKS_COUNT);
			for (sf::Sprite& rock : data.rocks) {
				InitSprite(rock, ROCK_SIZE, ROCK_SIZE, data.rockTexture);
				SetSpriteRandomPosition(rock, data.background.getGlobalBounds(), data.snake.body);
			}
		}


		data.numEatenApples = 0;

		data.scoreText.setFont(data.font);
		data.scoreText.setCharacterSize(24);
		data.scoreText.setFillColor(sf::Color::Yellow);

		data.inputHintText.setFont(data.font);
		data.inputHintText.setCharacterSize(24);
		data.inputHintText.setFillColor(sf::Color::White);
		data.inputHintText.setString("Use arrow keys to move, P to pause");
		data.inputHintText.setOrigin(GetTextOrigin(data.inputHintText, { 1.1f, 0.f }));

		// Init sounds
		data.eatAppleSound.setBuffer(data.eatAppleSoundBuffer);
		data.gameOverSound.setBuffer(data.gameOverSoundBuffer);
	}

	void ShutdownGameStatePlaying(GameStatePlayingData& data, Game& game)
	{
		// We dont need to free resources here, because they will be freed automatically
	}

	void HandleGameStatePlayingWindowEvent(GameStatePlayingData& data, Game& game, const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::P)
			{
				PushGameState(game, GameStateType::ExitDialog, false);
				game.EscButtonSound.play();
			}
		}
	}

	void UpdateGameStatePlaying(GameStatePlayingData& data, Game& game, float timeDelta)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && data.snake.direction != SnakeDirection::Down)
		{
			data.snake.direction = SnakeDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && data.snake.direction != SnakeDirection::Left)
		{
			data.snake.direction = SnakeDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && data.snake.direction != SnakeDirection::Up)
		{
			data.snake.direction = SnakeDirection::Down;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && data.snake.direction != SnakeDirection::Right)
		{
			data.snake.direction = SnakeDirection::Left;
		}

		// Update snake
		MoveSnake(data.snake, timeDelta);

		if (CheckSpriteIntersection(*data.snake.head, data.apple)) {
			data.eatAppleSound.play();

			GrowSnake(data.snake);

			
			// Move apple to a new random position
			SetSpriteRandomPosition(data.apple, data.background.getGlobalBounds(), data.snake.body);

			// Increase snake speed
			if ((std::uint8_t)game.options & (std::uint8_t)GameOptions::WithAcceleration) {
				switch (game.CurrentDifficult)
				{
				case Difficulty::Low:
					data.snake.speed += ACCELERATION * LOW_DIFFICULT_MULTIPLAYER;
					// Increase eaten apples counter
					data.numEatenApples += (int)(SCORE_COUNT * LOW_DIFFICULT_MULTIPLAYER);

					break;
				case Difficulty::LowUp:
					data.snake.speed += ACCELERATION * LOWUP_DIFFICULT_MULTIPLAYER;
					// Increase eaten apples counter
					data.numEatenApples += (int)(SCORE_COUNT * LOWUP_DIFFICULT_MULTIPLAYER);

					break;
				case Difficulty::Medium:
					data.snake.speed += ACCELERATION * MEDIUM_DIFFICULT_MULTIPLAYER;
					// Increase eaten apples counter
					data.numEatenApples += (int)(SCORE_COUNT * MEDIUM_DIFFICULT_MULTIPLAYER);

					break;
				case Difficulty::HardLow:
					data.snake.speed += ACCELERATION * HARDLOW_DIFFICULT_MULTIPLAYER;
					// Increase eaten apples counter
					data.numEatenApples += (int)(SCORE_COUNT * HARDLOW_DIFFICULT_MULTIPLAYER);

					break;
				case Difficulty::Hard:
					data.snake.speed += ACCELERATION * HARD_DIFFICULT_MULTIPLAYER;
					// Increase eaten apples counter
					data.numEatenApples += (int)(SCORE_COUNT * HARD_DIFFICULT_MULTIPLAYER);

					break;
				default:
					break;
				}

			}
		}

		if (!HasSnakeCollisionWithRect(data.snake, data.background.getGlobalBounds()))
		{
			sf::Vector2f headPosition = data.snake.head->getPosition();
			float headWidth = data.snake.head->getGlobalBounds().width;
			float headHeight = data.snake.head->getGlobalBounds().height;


			if (headPosition.x - headHeight < 0) {
				headPosition.x = SCREEN_WIDTH - headWidth;
			}
			else if (headPosition.x + headWidth > SCREEN_WIDTH) {
				headPosition.x = 0;
			}

			
			if (headPosition.y - headHeight < 0) {
				headPosition.y = SCREEN_HEGHT;
			}
			else if (headPosition.y + headHeight > SCREEN_HEGHT) {
				headPosition.y = 0;
			}

			data.snake.head->setPosition(headPosition);

			// Перемещение тела змейки за головой
			sf::Vector2f previousPosition = headPosition;

			// Обновляем позицию частей тела
			for (auto it = data.snake.body.begin(); it != data.snake.body.end(); ++it) {
				sf::Vector2f currentPosition = it->getPosition();
				it->setPosition(previousPosition); // Позиция текущего сегмента - это предыдущая позиция
				previousPosition = currentPosition; // Обновляем предыдущую позицию для следующего сегмента
			}


		}

		bool isGameFinished = !((std::uint8_t)game.options & (std::uint8_t)GameOptions::InfiniteApples);
		
		if (isGameFinished
			|| CheckSnakeCollisionWithHimself(data.snake)		// Check collision with screen border
			|| FullCheckCollisions(data.rocks.begin(), data.rocks.end(), *data.snake.head)) // Check collision with rocks
		{
			data.gameOverSound.play();

			// Find snake in records table and update his score
			game.recordsTable[PLAYER_NAME] = std::max(game.recordsTable[PLAYER_NAME], data.numEatenApples);


			PushGameState(game, GameStateType::GameOver, false);

		}

		data.scoreText.setString("Score: " + std::to_string(data.numEatenApples));
	}

	void DrawGameStatePlaying(GameStatePlayingData& data, Game& game, sf::RenderWindow& window)
	{
		// Draw background
		window.draw(data.background);

		// Draw snake
		DrawSnake(data.snake, window);
		// Draw apples
		DrawSprite(data.apple, window);
		// Draw rocks
		DrawSprites(data.rocks.begin(), data.rocks.end(), window);

		data.scoreText.setOrigin(GetTextOrigin(data.scoreText, { 0.f, 0.f }));
		data.scoreText.setPosition(20.f, 10.f);
		window.draw(data.scoreText);

		sf::Vector2f viewSize = window.getView().getSize();
		data.inputHintText.setPosition(viewSize.x - 10.f, 10.f);
		window.draw(data.inputHintText);
	}
}
