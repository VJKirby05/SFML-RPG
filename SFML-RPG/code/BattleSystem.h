#pragma once
#include <string>
using namespace std;

class BattleSystem
{
private:
	string m_actorA;
	string m_actorB;

public:
	// A constructor 
	BattleSystem();

	bool checkActors();

	void startBattle();
};
