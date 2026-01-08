#include "RPEngine.h"

using namespace sf;

RPEngine::RPEngine()
{
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	// Make game window
	m_Window.create(VideoMode(resolution.x, resolution.y), "The Great RPG", Style::Fullscreen);

	// Initialise the full screen view
	m_MainView.setSize(resolution);
	
	m_TitleView.setSize(resolution);

	m_BattleView.setSize(resolution);
	
	// Load background graphic for story menu
	/*
	m_BackgroundTexture = TextureHolder::GetTexture(
		"graphics/background22.jpg");

*/
	// Load the texture for the background vertex array
	m_TextureTiles = TextureHolder::GetTexture(
		"graphics/tile-sheet0.png");

	// Load suitable font
	font.loadFromFile("fonts/ByteBounce.ttf");

	// Game title text
	m_TitleText.setFont(font);
	m_TitleText.setCharacterSize(85);
	m_TitleText.setFillColor(Color::Red);
	m_TitleText.setPosition(80, 50);
	m_TitleText.setString("<+= ROLE PLAYING GAME =+>");

	// Game title prompt
	m_TitlePrompt.setFont(font);
	m_TitlePrompt.setCharacterSize(50);
	m_TitlePrompt.setFillColor(Color::White);
	m_TitlePrompt.setPosition(350, 500);
	m_TitlePrompt.setString("Press E to start");
}

// Function for each world's tiles
void RPEngine::setTileSheets(int world)
{
	// Change sheet for each world
	switch (world)
	{
	case 1:
		// Archaic Anarchy
		m_TextureTiles = TextureHolder::GetTexture("graphics/tile-sheet1.png");
		break;

	case 2:
		// Wild West
		m_TextureTiles = TextureHolder::GetTexture("graphics/tile-sheet2.png");
		break;

	case 3:
		// Fracture Future
		m_TextureTiles = TextureHolder::GetTexture("graphics/tile-sheet3.png");
		break;

	default:
		// Tutorial/Warehouse
		m_TextureTiles = TextureHolder::GetTexture("graphics/tile-sheet0.png");
		break;
	}
}

void RPEngine::run()
{
	// Timing 	
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		// Update the total game time
		//gameTimeTotal += dt;
		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Call input first
		input();

		// Update second
		update(dtAsSeconds);

		// Draw third
		draw();
	}
}

void RPEngine::resetGame()
{
	// Mark that we need a new level
	m_NewWorldRequired = true;

	// Load the world
	reloadWorld();
}