#pragma once

class UnitIsDeadException {};
class Unit;

class Attack
{
public:
	Attack();
	~Attack();

	virtual void attack(Unit& attacker, Unit& attacked) = 0;
	virtual void counterAttack(Unit& attacker, Unit& attacked) = 0;
	virtual void takeDamage(Unit& attacked, int damage) = 0;
};

