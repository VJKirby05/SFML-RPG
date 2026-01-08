#include "Enemy.h"
#include "TextureHolder.h"

Enemy::Enemy()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/enemy.png"));

	// Adjust speed for Enemy
	m_Speed = 70.f;
}

void Enemy::setScale(float value)
{
	// Adjust enemy sprite dimensions
	m_Sprite.setScale(value, value);
}

void Enemy::setPosition(float x, float y)
{
	// Set sprite position
	m_Sprite.setPosition(x, y);
}
