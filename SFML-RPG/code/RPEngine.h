#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"
#include "WorldManager.h"
#include <fstream>
#include <sstream>

using namespace sf;

class RPEngine
{
private:

	// Variable for arena bounds
	IntRect arena;

	// The texture holder
	TextureHolder th;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// A regular RenderWindow
	RenderWindow m_Window;

	WorldManager wm;

	// View title screen
	View m_TitleView;

	// The game view
	View m_MainView;

	// Setup the UI
	View m_UIView;

	// The player
	Player marine;

	// Declare a sprite and a Texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	Sprite spriteMainMenu;
	Texture textureMainMenu;

	// A suitable font
	Font font;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is it time for a new/first world?
	bool m_NewWorldRequired = true;

	// The vertex array for the world design
	VertexArray vaWorld;

	// The 2d array with the map for the world
	// A pointer to a pointer
	int** m_ArrayWorld = NULL;
	int** m_ArraySpawningPointsWorld = NULL;

	// Texture for the background and the world tiles
	Texture m_TextureTiles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

	// Load a world
	void reloadWorld();

	// Game title graphic
	Text m_TitleText;
	Text m_TitlePrompt;

public:
	// The RPEngine constructor
	RPEngine();

	// Change tilesheet
	void setTileSheets(int world);

	// Run will call all the private functions
	void run();

	// Game states
	enum class State { TITLE_SCREEN, PAUSED, PLAYING, BATTLE_SCREEN };
	State state = State::TITLE_SCREEN;

	// Reset game
	void resetGame();
};


