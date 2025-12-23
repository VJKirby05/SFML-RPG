#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>
#include "WorldManager.h"
#include <iostream>

using namespace sf;
using namespace std;

int** WorldManager::nextWorld(VertexArray& rVaLevel)
{
	// World dimensions
	m_WorldSize.x = 0;
	m_WorldSize.y = 0;

	// Get the next World
	m_CurrentWorld++;

	// Prevent non-existent Worlds from loading
	if (m_CurrentWorld > NUM_WORLDS)
	{
		m_CurrentWorld = 1;
	}

	// Load the appropriate World from a text file
	string worldToLoad;
	switch (m_CurrentWorld)
	{
		// Set player position for each World
		// Set text file to load for each World
	case 1:
		worldToLoad = "worlds/level0-tutorial.txt";
		m_PlayerStartPosition.x = 100;
		m_PlayerStartPosition.y = 900;
		break;

	case 2:
		worldToLoad = "worlds/level1-archaic-anarchy.txt";
		m_PlayerStartPosition.x = 400;
		m_PlayerStartPosition.y = 1200;
		break;

	case 3:
		worldToLoad = "worlds/level2-wild-west.txt";
		m_PlayerStartPosition.x = 1150;
		m_PlayerStartPosition.y = 380;
		break;

	case 4:
		worldToLoad = "worlds/level3-fracture-future.txt";
		m_PlayerStartPosition.x = 250;
		m_PlayerStartPosition.y = 650;
		break;

	case 5:
		worldToLoad = "worlds/level0-tutorial.txt";
		m_PlayerStartPosition.x = 100;
		m_PlayerStartPosition.y = 900;
		break;

	case 6:
		worldToLoad = "worlds/level1-archaic-anarchy.txt";
		m_PlayerStartPosition.x = 400;
		m_PlayerStartPosition.y = 1200;
		break;

	case 7:
		worldToLoad = "worlds/level2-wild-west.txt";
		m_PlayerStartPosition.x = 1150;
		m_PlayerStartPosition.y = 380;
		break;

	case 8:
		worldToLoad = "worlds/level3-fracture-future.txt";
		m_PlayerStartPosition.x = 250;
		m_PlayerStartPosition.y = 650;
		break;
	}

	// File stream
	ifstream inputFile(worldToLoad);
	string s;

	// Count the number of rows in the file
	while (getline(inputFile, s))
	{
		++m_WorldSize.y;
	}

	// Store the length of the rows
	m_WorldSize.x = s.length();

	// Go back to the start of the file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	// Prepare the 2d array to hold the int values from the file
	int** arrayWorld = new int* [m_WorldSize.y];
	for (int i = 0; i < m_WorldSize.y; ++i)
	{
		// Add a new array into each array element
		arrayWorld[i] = new int[m_WorldSize.x];
	}

	// Loop through the file and store all the values in the 2d array
	string row;
	int i = 0;
	while (inputFile >> row)
	{
		for (int j = 0; j < row.length(); j++) {

			const char val = row[j];
			arrayWorld[i][j] = atoi(&val);
		}

		i++;
	}

	// Close the file
	inputFile.close();

	// What type of primitive are we using?
	rVaLevel.setPrimitiveType(Quads);

	// Set the size of the vertex array
	rVaLevel.resize(m_WorldSize.x * m_WorldSize.y * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex = 0;

	for (int x = 0; x < m_WorldSize.x; x++)
	{
		for (int y = 0; y < m_WorldSize.y; y++)
		{
			// Position each vertex in the current quad
			rVaLevel[currentVertex + 0].position =
				Vector2f(x * TILE_SIZE, y * TILE_SIZE);

			rVaLevel[currentVertex + 1].position =
				Vector2f((x * TILE_SIZE) + TILE_SIZE, y * TILE_SIZE);

			rVaLevel[currentVertex + 2].position =
				Vector2f((x * TILE_SIZE) + TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);

			rVaLevel[currentVertex + 3].position =
				Vector2f((x * TILE_SIZE), (y * TILE_SIZE) + TILE_SIZE);

			// Which tile from the sprite sheet should we use
			int verticalOffset = arrayWorld[y][x] * TILE_SIZE;

			rVaLevel[currentVertex + 0].texCoords =
				Vector2f(0, 0 + verticalOffset);

			rVaLevel[currentVertex + 1].texCoords =
				Vector2f(TILE_SIZE, 0 + verticalOffset);

			rVaLevel[currentVertex + 2].texCoords =
				Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);

			rVaLevel[currentVertex + 3].texCoords =
				Vector2f(0, TILE_SIZE + verticalOffset);

			// Position ready for the next four vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}

	return arrayWorld;
}

// Get dimensions of level arena
FloatRect WorldManager::getArenaBounds()
{
	// TILE_SIZE is the constant used to build the map
	return sf::FloatRect(
		0,
		0,
		m_WorldSize.x * TILE_SIZE,
		m_WorldSize.y * TILE_SIZE
	);
}

// Find tile size
float WorldManager::getTileSize()
{
	return TILE_SIZE;
}

// Find world size
Vector2i WorldManager::getWorldSize()
{
	return m_WorldSize;
}

// Get world points
Vector2i WorldManager::getWorldSpawningPointsSize()
{
	return m_WorldSpawningPointsSize;
}

// Which world is it?
int WorldManager::getCurrentWorld()
{
	return m_CurrentWorld;
}

// Change world
void WorldManager::setCurrentWorld(int worldNum)
{
	m_CurrentWorld = worldNum;
}

// Get player spawn position
Vector2f WorldManager::getPlayerStartPosition()
{
	return m_PlayerStartPosition;
}

// Define world spawning points
int** WorldManager::nextWorldSpawningPoints()
{
	m_WorldSpawningPointsSize.x = 0;
	m_WorldSpawningPointsSize.y = 0;

	// Load the appropriate world from a text file
	string worldToLoad;
	switch (m_CurrentWorld)
	{

	case 1:
		worldToLoad = "worlds/level0-tutorial.txt";
		break;

	case 2:
		worldToLoad = "worlds/level1-archaic-anarchy.txt";
		break;

	case 3:
		worldToLoad = "worlds/level2-wild-west.txt";
		break;

	case 4:
		worldToLoad = "worlds/level3-fracture-future.txt";
		break;

	case 5:
		worldToLoad = "worlds/level0-tutorial.txt";
		break;

	case 6:
		worldToLoad = "worlds/level1-archaic-anarchy.txt";
		break;

	case 7:
		worldToLoad = "worlds/level2-wild-west.txt";
		break;

	case 8:
		worldToLoad = "worlds/level3-fracture-future.txt";
		break;
	}

	ifstream inputFile(worldToLoad);
	string s;

	// Count the number of rows in the file
	while (getline(inputFile, s))
	{
		++m_WorldSpawningPointsSize.y;
	}

	// Store the length of the rows
	m_WorldSpawningPointsSize.x = s.length();

	// Go back to the start of the file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	// Prepare the 2d array to hold the int values from the file
	int** arrayWorld = new int* [m_WorldSpawningPointsSize.y];
	for (int i = 0; i < m_WorldSpawningPointsSize.y; ++i)
	{
		// Add a new array into each array element
		arrayWorld[i] = new int[m_WorldSpawningPointsSize.x];
	}

	// Loop through the file and store all the values in the 2d array
	string row;
	int i = 0;
	while (inputFile >> row)
	{
		for (int j = 0; j < row.length(); j++) {

			const char val = row[j];
			arrayWorld[i][j] = atoi(&val);
		}
		i++;
	}

	// close the file
	inputFile.close();

	return arrayWorld;
}
