#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include <cmath>
#include <iostream>

namespace Flappy
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		_animationTime = 0.0f;

		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));


		// Set title position first
		_title.setPosition(
			(SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2),
			_title.getGlobalBounds().height / 2
		);

		// Save original position AFTER setting it
		_titleOriginalX = _title.getPosition().x;
		_titleOriginalY = _title.getPosition().y;


		_playButton.setPosition(
			(SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2)
		);
	}


	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}


			if (this->_data->input.IsSpriteClicked(
				this->_playButton,
				sf::Mouse::Left,
				this->_data->window))
			{
				this->_data->machine.AddState(
					StateRef(new GameState(_data)),
					true
				);
			}
		}
	}


	void MainMenuState::Update(float dt)
	{
		_animationTime += dt;


		// Floating animation
		float offset = std::sin(_animationTime * 5.0f) * 5.0f;


		_title.setPosition(
			_titleOriginalX,
			_titleOriginalY + offset
		);
	}


	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
}