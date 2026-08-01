#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Flappy
{
	class Bird
	{
	public:
		Bird(GameDataRef data);
		~Bird();

		void Draw();

	private:
		GameDataRef _data;

		sf::Sprite _birdSprite;

	};
}