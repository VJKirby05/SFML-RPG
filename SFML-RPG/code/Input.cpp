#include "RPEngine.h"
#include <iostream>

using namespace std;

void RPEngine::input()
{
	Event event;

	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_Window.close(); // Allows the window's X button to work
		}

		if (state == State::TITLE_SCREEN)
		{
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				state = State::PLAYING;
				cout << "STATE CHANGED TO PLAYING!!!";
			}
		}

		// Allow player to move in this state
		if (state == State::PLAYING)
		{
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
			{
				m_Window.close();
			}

			// Handle the pressing and releasing of the WASD keys
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				pl.moveUp();
			}
			else
			{
				pl.stopUpMovement();
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				pl.moveDown();
			}
			else
			{
				pl.stopDownMovement();
			}

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				pl.moveLeft();
			}
			else
			{
				pl.stopLeftMovement();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				pl.moveRight();
			}
			else
			{
				pl.stopRightMovement();
			}

			// Handle the player quitting
			if (event.key.code == (Keyboard::Escape))
			{
				m_Window.close();
			}
		}
	}
}