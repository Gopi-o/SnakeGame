#include "MainMenu.h"
#include "Game.h"
#include <assert.h>

namespace SnakeGame
{
	void InitGameStateMainMenu(GameStateMainMenuData& data, Game& game)
	{
		assert(data.font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		data.menu.rootItem.hintText.setString("Snake Game");
		data.menu.rootItem.hintText.setFont(data.font);
		data.menu.rootItem.hintText.setCharacterSize(48);
		data.menu.rootItem.hintText.setFillColor(sf::Color::Red);
		data.menu.rootItem.childrenOrientation = Orientation::Vertical;
		data.menu.rootItem.childrenAlignment = Alignment::Middle;
		data.menu.rootItem.childrenSpacing = 10.f;
		data.menu.rootItem.children.push_back(&data.startGameItem);
		data.menu.rootItem.children.push_back(&data.difficultyLevelItem);
		data.menu.rootItem.children.push_back(&data.optionsItem);
		data.menu.rootItem.children.push_back(&data.recordsItem);
		data.menu.rootItem.children.push_back(&data.exitGameItem);

		data.startGameItem.text.setString("Start Game");
		data.startGameItem.text.setFont(data.font);
		data.startGameItem.text.setCharacterSize(24);

		data.difficultyLevelItem.text.setString("Difficulty level");
		data.difficultyLevelItem.text.setFont(data.font);
		data.difficultyLevelItem.text.setCharacterSize(24);
		data.difficultyLevelItem.hintText.setString("Difficulty level");
		data.difficultyLevelItem.hintText.setFont(data.font);
		data.difficultyLevelItem.hintText.setCharacterSize(48);
		data.difficultyLevelItem.hintText.setFillColor(sf::Color::Red);
		data.difficultyLevelItem.childrenOrientation = Orientation::Vertical;
		data.difficultyLevelItem.childrenAlignment = Alignment::Middle;
		data.difficultyLevelItem.childrenSpacing = 10.f;
		data.difficultyLevelItem.children.push_back(&data.LowDifficultyItem);
		data.difficultyLevelItem.children.push_back(&data.LowUpDifficultyItem);
		data.difficultyLevelItem.children.push_back(&data.MediumDifficultyItem);
		data.difficultyLevelItem.children.push_back(&data.HardDouwnDifficultyItem);
		data.difficultyLevelItem.children.push_back(&data.HardDifficultyItem);
		
		data.LowDifficultyItem.text.setString("LowDifficult On/Off");
		data.LowDifficultyItem.text.setFont(data.font);
		data.LowDifficultyItem.text.setCharacterSize(24);

		data.LowUpDifficultyItem.text.setString("Low Upper Difficult On/Off");
		data.LowUpDifficultyItem.text.setFont(data.font);
		data.LowUpDifficultyItem.text.setCharacterSize(24);

		data.MediumDifficultyItem.text.setString("Medium Difficult On/Off");
		data.MediumDifficultyItem.text.setFont(data.font);
		data.MediumDifficultyItem.text.setCharacterSize(24);

		data.HardDouwnDifficultyItem.text.setString("Low hard Difficult On/Off");
		data.HardDouwnDifficultyItem.text.setFont(data.font);
		data.HardDouwnDifficultyItem.text.setCharacterSize(24);

		data.HardDifficultyItem.text.setString("Low hard Difficult On/Off");
		data.HardDifficultyItem.text.setFont(data.font);
		data.HardDifficultyItem.text.setCharacterSize(24);


		data.optionsItem.text.setString("Options");
		data.optionsItem.text.setFont(data.font);
		data.optionsItem.text.setCharacterSize(24);
		data.optionsItem.hintText.setString("Options");
		data.optionsItem.hintText.setFont(data.font);
		data.optionsItem.hintText.setCharacterSize(48);
		data.optionsItem.hintText.setFillColor(sf::Color::Red);
		data.optionsItem.childrenOrientation = Orientation::Vertical;
		data.optionsItem.childrenAlignment = Alignment::Middle;
		data.optionsItem.childrenSpacing = 10.f;
		data.optionsItem.children.push_back(&data.optionsInfiniteApplesItem);
		data.optionsItem.children.push_back(&data.optionsWithAccelerationItem);
		data.optionsItem.children.push_back(&data.optionsWithStaticWallItem);
		data.optionsItem.children.push_back(&data.optionsWithSoundItem);
		data.optionsItem.children.push_back(&data.optionsWithMusicItem);

		data.optionsInfiniteApplesItem.text.setString("Infinite Apples: On/Off");
		data.optionsInfiniteApplesItem.text.setFont(data.font);
		data.optionsInfiniteApplesItem.text.setCharacterSize(24);

		data.optionsWithAccelerationItem.text.setString("With Acceleration: On/Off");
		data.optionsWithAccelerationItem.text.setFont(data.font);
		data.optionsWithAccelerationItem.text.setCharacterSize(24);

		data.optionsWithStaticWallItem.text.setString("With Static Wall: On/Off");
		data.optionsWithStaticWallItem.text.setFont(data.font);
		data.optionsWithStaticWallItem.text.setCharacterSize(24);

		data.optionsWithSoundItem.text.setString("Sound: On/Off");
		data.optionsWithSoundItem.text.setFont(data.font);
		data.optionsWithSoundItem.text.setCharacterSize(24);

		data.optionsWithMusicItem.text.setString("Music: On/Off");
		data.optionsWithMusicItem.text.setFont(data.font);
		data.optionsWithMusicItem.text.setCharacterSize(24);


		data.recordsItem.text.setString("Records");
		data.recordsItem.text.setFont(data.font);
		data.recordsItem.text.setCharacterSize(24);

		data.exitGameItem.text.setString("Exit Game");
		data.exitGameItem.text.setFont(data.font);
		data.exitGameItem.text.setCharacterSize(24);
		data.exitGameItem.hintText.setString("Are you sure?");
		data.exitGameItem.hintText.setFont(data.font);
		data.exitGameItem.hintText.setCharacterSize(48);
		data.exitGameItem.hintText.setFillColor(sf::Color::Red);
		data.exitGameItem.childrenOrientation = Orientation::Horizontal;
		data.exitGameItem.childrenAlignment = Alignment::Middle;
		data.exitGameItem.childrenSpacing = 10.f;
		data.exitGameItem.children.push_back(&data.yesItem);
		data.exitGameItem.children.push_back(&data.noItem);

		data.yesItem.text.setString("Yes");
		data.yesItem.text.setFont(data.font);
		data.yesItem.text.setCharacterSize(24);

		data.noItem.text.setString("No");
		data.noItem.text.setFont(data.font);
		data.noItem.text.setCharacterSize(24);

		InitMenuItem(data.menu.rootItem);
		SelectMenuItem(data.menu, &data.startGameItem);
	}

	void ShutdownGameStateMainMenu(GameStateMainMenuData& data, Game& game)
	{
		// No need to do anything here
	}

	void HandleGameStateMainMenuWindowEvent(GameStateMainMenuData& data, Game& game, const sf::Event& event)
	{
		if (!data.menu.selectedItem)
		{
			return;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::B)
			{
				CollapseSelectedItem(data.menu);
				if (game.bIsSoundOn)
					game.EscButtonSound.play();
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				if (game.bIsSoundOn)
					game.TouchButtonSound.play();
				if (data.menu.selectedItem == &data.startGameItem)
				{
					SwitchGameState(game, GameStateType::Playing);
				}
				else if (data.menu.selectedItem == &data.difficultyLevelItem)
				{
					ExpandSelectedItem(data.menu);
				}
				else if (data.menu.selectedItem == &data.LowDifficultyItem)
				{
					game.CurrentDifficult = Difficulty::Low;
				}
				else if (data.menu.selectedItem == &data.LowUpDifficultyItem)
				{
					game.CurrentDifficult = Difficulty::LowUp;
				}
				else if (data.menu.selectedItem == &data.MediumDifficultyItem)
				{
					game.CurrentDifficult = Difficulty::Medium;
				}
				else if (data.menu.selectedItem == &data.HardDouwnDifficultyItem)
				{
					game.CurrentDifficult = Difficulty::HardLow;
				}
				else if (data.menu.selectedItem == &data.HardDifficultyItem)
				{
					game.CurrentDifficult = Difficulty::Hard;
				}
				else if (data.menu.selectedItem == &data.optionsItem)
				{
					ExpandSelectedItem(data.menu);
				}
				else if (data.menu.selectedItem == &data.optionsInfiniteApplesItem)
				{
					game.options = (GameOptions)((std::uint8_t)game.options ^ (std::uint8_t)GameOptions::InfiniteApples);
				}
				else if (data.menu.selectedItem == &data.optionsWithAccelerationItem)
				{
					game.options = (GameOptions)((std::uint8_t)game.options ^ (std::uint8_t)GameOptions::WithAcceleration);
				}
				else if (data.menu.selectedItem == &data.optionsWithStaticWallItem)
				{
					game.options = (GameOptions)((std::uint8_t)game.options ^ (std::uint8_t)GameOptions::StaticWall);
				}
				else if (data.menu.selectedItem == &data.optionsWithSoundItem)
				{
					game.options = (GameOptions)((std::uint8_t)game.options ^ (std::uint8_t)GameOptions::Sound);
				}
				else if (data.menu.selectedItem == &data.optionsWithMusicItem)
				{
					game.options = (GameOptions)((std::uint8_t)game.options ^ (std::uint8_t)GameOptions::Music);
					if (game.bisMusicOn)
					{
						game.MenuBackground.setLoop(false);
						game.MenuBackground.stop();
					}
					else if (!game.bisMusicOn)
					{
						game.GameBackground.setLoop(false);
						game.MenuBackground.setLoop(true);
						game.GameBackground.stop();
						game.MenuBackground.play();
					}
				}
				else if (data.menu.selectedItem == &data.recordsItem)
				{
					PushGameState(game, GameStateType::Records, true);
				}
				else if (data.menu.selectedItem == &data.exitGameItem)
				{
					ExpandSelectedItem(data.menu);
				}
				else if (data.menu.selectedItem == &data.yesItem)
				{
					SwitchGameState(game, GameStateType::None);
				}
				else if (data.menu.selectedItem == &data.noItem)
				{
					CollapseSelectedItem(data.menu);
				}
				else
				{
					ExpandSelectedItem(data.menu);
				}
			}
			
			Orientation orientation = data.menu.selectedItem->parent->childrenOrientation;
			if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::W ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::A)
			{
				SelectPreviousMenuItem(data.menu);	
				if (game.bIsSoundOn)
					game.GuidButtonSound.play();
			}
			else if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::S ||
						orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::D)
			{
				SelectNextMenuItem(data.menu);
				if (game.bIsSoundOn)
					game.GuidButtonSound.play();
			}
		}
	}

	void UpdateGameStateMainMenu(GameStateMainMenuData& data, Game& game, float timeDelta)
	{
		bool isInfiniteApples = ((std::uint8_t)game.options & (std::uint8_t)GameOptions::InfiniteApples) != (std::uint8_t)GameOptions::Empty;
		data.optionsInfiniteApplesItem.text.setString("Infinite Apples: " + std::string(isInfiniteApples ? "On" : "Off"));

		bool isWithAcceleration = ((std::uint8_t)game.options & (std::uint8_t)GameOptions::WithAcceleration) != (std::uint8_t)GameOptions::Empty;
		data.optionsWithAccelerationItem.text.setString("With Acceleration: " + std::string(isWithAcceleration ? "On" : "Off"));

		bool isWithStaticWall = ((std::uint8_t)game.options & (std::uint8_t)GameOptions::StaticWall) != (std::uint8_t)GameOptions::Empty;
		data.optionsWithStaticWallItem.text.setString("With Static Wall: " + std::string(isWithStaticWall ? "On" : "Off"));

		bool isWithSound = ((std::uint8_t)game.options & (std::uint8_t)GameOptions::Sound) != (std::uint8_t)GameOptions::Empty;
		data.optionsWithSoundItem.text.setString("Sound: " + std::string(isWithSound ? "On" : "Off"));

		bool isWithMusic = ((std::uint8_t)game.options & (std::uint8_t)GameOptions::Music) != (std::uint8_t)GameOptions::Empty;
		data.optionsWithMusicItem.text.setString("Music: " + std::string(isWithMusic ? "On" : "Off"));

		switch (game.CurrentDifficult)
		{
			case Difficulty::Low:
				data.LowDifficultyItem.text.setString("LowDifficult: " + std::string( "On" ));
				data.LowUpDifficultyItem.text.setString("Low Upper Difficult: " + std::string( "Off" ));
				data.MediumDifficultyItem.text.setString("Medium Difficult: " + std::string( "Off" ));
				data.HardDouwnDifficultyItem.text.setString("Low hard Difficult: " + std::string( "Off" ));
				data.HardDifficultyItem.text.setString("Low hard Difficult: " + std::string( "Off" ));

				break;
			case Difficulty::LowUp:
				data.LowDifficultyItem.text.setString("LowDifficult: " + std::string("Off"));
				data.LowUpDifficultyItem.text.setString("Low Upper Difficult: " + std::string("On"));
				data.MediumDifficultyItem.text.setString("Medium Difficult: " + std::string("Off"));
				data.HardDouwnDifficultyItem.text.setString("Low hard Difficult: " + std::string("Off"));
				data.HardDifficultyItem.text.setString("Low hard Difficult: " + std::string("Off"));

				break;
			case Difficulty::Medium:
				data.LowDifficultyItem.text.setString("LowDifficult: " + std::string("Off"));
				data.LowUpDifficultyItem.text.setString("Low Upper Difficult: " + std::string("Off"));
				data.MediumDifficultyItem.text.setString("Medium Difficult: " + std::string("On"));
				data.HardDouwnDifficultyItem.text.setString("Low hard Difficult: " + std::string("Off"));
				data.HardDifficultyItem.text.setString("Low hard Difficult: " + std::string("Off"));

				break;
			case Difficulty::HardLow:
				data.LowDifficultyItem.text.setString("LowDifficult: " + std::string("Off"));
				data.LowUpDifficultyItem.text.setString("Low Upper Difficult: " + std::string("Off"));
				data.MediumDifficultyItem.text.setString("Medium Difficult: " + std::string("Off"));
				data.HardDouwnDifficultyItem.text.setString("Low hard Difficult: " + std::string("On"));
				data.HardDifficultyItem.text.setString("Low hard Difficult: " + std::string("Off"));

				break;
			case Difficulty::Hard:
				data.LowDifficultyItem.text.setString("LowDifficult: " + std::string("Off"));
				data.LowUpDifficultyItem.text.setString("Low Upper Difficult: " + std::string("Off"));
				data.MediumDifficultyItem.text.setString("Medium Difficult: " + std::string("Off"));
				data.HardDouwnDifficultyItem.text.setString("Low hard Difficult: " + std::string("Off"));
				data.HardDifficultyItem.text.setString("Low hard Difficult: " + std::string("On"));

				break;
			default:
				break;
		}
	}

	void DrawGameStateMainMenu(GameStateMainMenuData& data, Game& game, sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = (sf::Vector2f)window.getView().getSize();

		sf::Text* hintText = &GetCurrentMenuContext(data.menu)->hintText;
		hintText->setOrigin(GetTextOrigin(*hintText, { 0.5f, 0.f }));
		hintText->setPosition(viewSize.x / 2.f, 150.f);
		window.draw(*hintText);

		DrawMenu(data.menu, window, viewSize / 2.f, { 0.5f, 0.f });
	}

}
