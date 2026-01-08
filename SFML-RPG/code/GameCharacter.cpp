#include "GameCharacter.h"

void GameCharacter::spawn(Vector2f startPosition)
{
	// Place the player at the starting p
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	// Move the sprite in to position
	m_Sprite.setPosition(m_Position);
}

// Find position for each npc
FloatRect GameCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

// Find the graphic for each npc
Sprite GameCharacter::getSprite()
{
	return m_Sprite;
}