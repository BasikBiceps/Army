#pragma once

#include "Attack.h"

class WerewolfAttack : public Attack
{
public:
	WerewolfAttack();
	~WerewolfAttack();

	void attack(Unit& attacker, Unit& attacked) override;
	void counterAttack(Unit& attacker, Unit& attacked) override;
	void takeDamage(Unit& attacker, int damage) override;
};
