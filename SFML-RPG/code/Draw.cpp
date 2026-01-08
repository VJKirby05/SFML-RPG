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
		pl.setScale(1.0f);
		m_Window.draw(pl.getSprite());

		// Draw the enemy
		m_Window.draw(en.getSprite());

		// Draw UI
		//m_Window.setView(m_UIView);
		//m_UI.draw(m_Window);
	}

	if (state == State::BATTLE_SCREEN)
	{
		m_Window.clear();

		// Set the mainView to be displayed in the window
		m_Window.setView(m_BattleView);
		
		pl.setScale(5.0f);
		pl.setPosition(0, 600);
		m_Window.draw(pl.getSprite());
		en.setScale(5.0f);
		en.setPosition(800, 470);
		m_Window.draw(en.getSprite());
	}

	// Show window
	m_Window.display();
}

