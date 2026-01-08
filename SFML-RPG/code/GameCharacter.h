#pragma once
#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameCharacter
{
protected:
	// Of course we will need a sprite
	Sprite m_Sprite;

	// How fast is the character
	float m_Speed;

	// Where is the player
	Vector2f m_Position;

	// And a texture
	Texture m_Texture;

	// All our public functions will come next
public:

	// Spawn each npc
	void spawn(Vector2f startPosition);

	// Where is the player
	FloatRect getPosition();

	// Send a copy of the sprite to main
	Sprite getSprite();

};
