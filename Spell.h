#pragma once

#include <string>

class Unit;

class Spell
{
public:
	Spell();
	Spell(int needMana, int power);
	~Spell();

	int getPower();
	int getNeedMana();
	std::string getName();

	void setPower(int power);
	void setNeedMana(int needMana);
	void setName(const std::string& name);

	virtual void cast(Unit& unit) = 0;

private:
	std::string name;
	int needMana;
	int power;
};

