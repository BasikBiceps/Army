#pragma once
#include "Attack.h"
class Unit;
class Spell;
class NotEnoughManaException {};

class MagicAttack : public Attack
{
public:
	MagicAttack();
	~MagicAttack();

	void attack(Unit& attacker, Unit& attacked) override;
	void counterAttack(Unit& attacker, Unit& attacked) override;
	void takeDamage(Unit& attacked, int damage) override;

	void attack(Unit& attacker, Unit& attacked, Spell& spell);
	void counterAttack(Unit& attacker, Unit& attacked, Spell& spell);
	void takeDamage(Unit& attacked, Spell& spell);
};
