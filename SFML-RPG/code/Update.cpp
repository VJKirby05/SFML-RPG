#include "RPEngine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

using namespace std;

void RPEngine::update(float dtAsSeconds)
{
	if (state == State::PLAYING)
	{
		// Make a note of the players new position
		Vector2f playerPosition(pl.getCenter());

		// Update the player
		pl.update(dtAsSeconds);

		// Make a rect for all his parts
		FloatRect detectionZone = pl.getPosition();

		// Make a FloatRect to test each block
		FloatRect block;

		// Allign block dimensions with dimensions of map tiles
		block.width = TILE_SIZE;
		block.height = TILE_SIZE;

		m_MainView.setCenter(pl.getCenter());
		m_Window.setView(m_MainView);

		if (m_NewWorldRequired)
		{
			reloadWorld();
		}

		if (pl.getPosition().intersects(en.getPosition()))
		{
			state = State::BATTLE_SCREEN;
		}

		/*

		// Build a zone around player to detect collisions
		int startX = (int)(round(detectionZone.left) / TILE_SIZE) - 1;
		int startY = (int)(round(detectionZone.top) / TILE_SIZE) - 1;
		int endX = (int)(round(detectionZone.left) / TILE_SIZE) + 2;
		int endY = (int)round((detectionZone.top) / TILE_SIZE) + 2;

		// Make sure we don't test positions lower than zero
		// Or higher than the end of the array
		if (startX < 0)startX = 0;
		if (startY < 0)startY = 0;
		if (endX >= lm.getLevelSize().x)
			endX = lm.getLevelSize().x;
		if (endY >= lm.getLevelSize().y)
			endY = lm.getLevelSize().y;

		// Collision detection
		for (int x = startX; x < endX; x++)
		{
			for (int y = startY; y < endY; y++)
			{
				block.left = x * TILE_SIZE;
				block.top = y * TILE_SIZE;

				// Is player colliding with a wall?
				if (m_ArrayLevel[y][x] == 0)
				{
					// Check if player collides with wall on left or right sides
					if (marine.getRight().intersects(block))
					{
						marine.stopRight(block.left);
					}
					else if (marine.getLeft().intersects(block))
					{
						marine.stopLeft(block.left);
					}

					// Check if player collides with wall on top or bottom sides
					if (marine.getBottom().intersects(block))
					{
						marine.stopDown(block.top);
					}
					else if (marine.getTop().intersects(block))
					{
						marine.stopUp((block.top));
					}
				}

			}

		}

		// Apply the centered view immediately
		m_MainView.setCenter(marine.getCenter());
		m_Window.setView(m_MainView);

		// Check for collision
		//detectCollision();

		// Start of a new level
		
		*/
	}

	if (state == State::BATTLE_SCREEN)
	{
		m_Window.setView(m_BattleView);
	}
}