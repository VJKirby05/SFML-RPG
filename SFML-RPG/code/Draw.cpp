#pragma once
#include "RPEngine.h"
using namespace sf;

void RPEngine::draw()
{
	if (state == State::TITLE_SCREEN)
	{
		m_Window.setView(m_TitleView);

		// Draw the title
		m_Window.draw(m_TitleText);

		// Draw the debug prompt
		m_Window.draw(m_TitlePrompt);
	}

	// Draw player and stuff
	if (state == State::PLAYING)
	{
		m_Window.clear();

		// Set the mainView to be displayed in the window
		m_Window.setView(m_MainView);

		// Draw the World
		m_Window.draw(vaWorld, &m_TextureTiles);

		// Draw the player
		m_Window.draw(pl.getSprite());

		// Draw UI
		//m_Window.setView(m_UIView);
		//m_UI.draw(m_Window);
	}

	// Show window
	m_Window.display();
}

