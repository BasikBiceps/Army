#pragma once
#include "Attack.h"

class VampireAttack : public Attack
{
public:
	VampireAttack();
	~VampireAttack();

	void attack(Unit& attacker, Unit& attacked) override;
	void counterAttack(Unit& attacker, Unit& attacked) override;
	void takeDamage(Unit& attacker, int damage) override;
};

