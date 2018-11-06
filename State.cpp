#include "State.h"

State::State()
{
	name = "noname";
	 healthPoint = 0;
	 healthPointLimit = 0;
	 physDamage = 0;
	 physDamageLimit = 0;
	 mana = 0;
	 manaLimit = 0;
	 magicResist = 0;
	 transformed = false;
}

State::State(std::string name, int healthPoint, int physDamage, int mana, float magicResist)
{
	this->name = name;
	this->healthPoint = healthPoint;
	this->healthPointLimit = healthPoint;
	this->physDamage = physDamage;
	this->physDamageLimit = physDamage;
	this->mana = mana;
	this->manaLimit = mana;
	this->magicResist = magicResist;
	transformed = false;
}

State::~State() {}

std::string State::getName() const
{
	return name;
}

int State::getHealthPoint() const
{
	return healthPoint;
}

int State::getHealthPointLimit() const
{
	return healthPointLimit;
}

int State::getPhysDamage() const
{
	return physDamage;
}

int State::getPhysDamageLimit() const
{
	return physDamageLimit;
}

int State::getMana() const
{
	return mana;
}

int State::getManaLimit() const
{
	return manaLimit;
}

float State::getMagicResist() const
{
	return magicResist;
}

void State::setTransformed(bool transformed)
{
	this->transformed = transformed;
}

void State::setName(const std::string& name)
{
	this->name = name;
}

void State::setHealthPoint(int healthPoint)
{
	this->healthPoint = healthPoint;
}

void State::setHealthPointLimit(int healthPointLimit)
{
	this->healthPointLimit = healthPointLimit;
}

void State::setPhysDamage(int physDamage)
{
	this->physDamage = physDamage;
}

void State::setPhysDamageLimit(int physDamageLimit)
{
	this->physDamageLimit = physDamageLimit;
}

void State::setMana(int mana)
{
	this->mana = mana;
}

void State::setManaLimit(int manaLimit)
{
	this->manaLimit = manaLimit;
}

void State::setMagicResist(float magicResist)
{
	this->magicResist = magicResist;
}

bool State::isTransformed()
{
	return transformed;
}

bool State::ensureIsAlive()
{
	return healthPoint > 0;
}
