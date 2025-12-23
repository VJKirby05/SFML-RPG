#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class WorldManager
{
private:
	// Properties for each world
	Vector2i m_WorldSize;
	Vector2i m_WorldSpawningPointsSize;
	Vector2f m_PlayerStartPosition;
	int m_CurrentWorld = 0;
	const int NUM_WORLDS = 8;

public:
	// World dimensions
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	static const int TILE_WALL = 0;

	// Position of marine
	Vector2f getPlayerStartPosition();

	// A pointer to a pointer
	int** nextWorld(VertexArray& rVaLevel);
	int** nextWorldSpawningPoints();

	// World size 
	Vector2i getWorldSize();
	Vector2i getWorldSpawningPointsSize();

	// World arena functions
	FloatRect getArenaBounds();
	float getTileSize();

	// Functions for specific world
	int getCurrentWorld();
	void setCurrentWorld(int worldNum);
};
