#pragma once
#include "GameCharacter.h"

class Enemy : public GameCharacter	// Enemy is a child of parent GameCharacter
{
public:
	// A constructor specific to Enemy
	Enemy();

	// Set sprite scale
	void setScale(float value);

	// Set position
	void setPosition(float x, float y);
};
