#pragma once

#include <SFML/Graphics.hpp>

namespace Flappy
{
	class Collision
	{
	public:
		Collision();
		~Collision();

		bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);

	};
}