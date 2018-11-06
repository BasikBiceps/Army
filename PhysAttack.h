#pragma once
#include "Attack.h"

class PhysAttack : public Attack
{
public:
	PhysAttack();
	~PhysAttack();

	void attack(Unit& attacker, Unit& attacked) override;
	void counterAttack(Unit& attacker, Unit& attacked) override;
	void takeDamage(Unit& attacker, int damage) override;
};

