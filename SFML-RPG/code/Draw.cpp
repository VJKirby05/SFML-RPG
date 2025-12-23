#pragma once
#include "RPEngine.h"
using namespace sf;

void RPEngine::draw()
{
	// Draw player and stuff
	if (state == State::PLAYING)
	{
		m_Window.clear();

		// Set the mainView to be displayed in the window
		m_Window.setView(m_MainView);

		// Draw the World
		m_Window.draw(vaWorld, &m_TextureTiles);

		// Draw the player
		m_Window.draw(marine.getSprite());

		// Draw UI
		//m_Window.setView(m_UIView);
		//m_UI.draw(m_Window);
	}

	// Show window
	m_Window.display();
}

