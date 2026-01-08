#include "RPEngine.h"

void RPEngine::reloadWorld()
{
	// Arena dimensions
	arena.width = 500;
	arena.height = 500;

	int world = wm.getCurrentWorld();
	setTileSheets(world);
	m_Playing = false;

	// Delete the previously allocated memory
	for (int i = 0; i < wm.getWorldSize().y; ++i)
	{
		delete[] m_ArrayWorld[i];

	}
	delete[] m_ArrayWorld;

	// Load the next 2d array with the map for the world
	// And repopulate the vertex array as well
	m_ArrayWorld = wm.nextWorld(vaWorld);

	// Get world's pixel bounds from WorldManager. 
	FloatRect arenaBounds = wm.getArenaBounds();

	// Get tile size
	float tileSize = wm.getTileSize();

	// Pass the arena data to player
	pl.setArena(arenaBounds, tileSize);

	// Delete previously allocated memory
	for (int i = 0; i < wm.getWorldSpawningPointsSize().y; ++i)
	{
		delete[] m_ArraySpawningPointsWorld[i];

	}
	delete[] m_ArraySpawningPointsWorld;

	// Load spawning points data
	m_ArraySpawningPointsWorld = wm.nextWorldSpawningPoints();

	// Spawn Player
	pl.spawn(wm.getPlayerStartPosition());

	// Spawn Enemy
	en.spawn(wm.getEnemyStartPosition());

	// Make sure this code isn't run again
	m_NewWorldRequired = false;
}