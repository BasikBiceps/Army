#pragma once
#include <iostream>


class State
{
public:

	State();
	State(std::string name, int healthPoint, int physDamage, int mana, float magicResist);

	~State();

	std::string getName() const;
	int getHealthPoint() const;
	int getHealthPointLimit() const;
	int getPhysDamage() const;
	int getPhysDamageLimit() const;
	int getMana() const;
	int getManaLimit() const;
	float getMagicResist() const;

	void setTransformed(bool transformed);
	void setName(const std::string& name);
	void setHealthPoint(int healthPoint);
	void setHealthPointLimit(int healthPointLimit);
	void setPhysDamage(int physDamage);
	void setPhysDamageLimit(int physDamageLimit);
	void setMana(int mana);
	void setManaLimit(int manaLimit);
	void setMagicResist(float magicResist);

	bool isTransformed();
	bool ensureIsAlive();

private:
	std::string name;
	int healthPoint;
	int healthPointLimit;
	int physDamage;
	int physDamageLimit;
	int mana;
	int manaLimit;
	float magicResist;
	bool transformed;
};
