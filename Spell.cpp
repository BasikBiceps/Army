#include "stdafx.h"
#include "Spell.h"


Spell::Spell() : power(0), needMana(0) {}

Spell::Spell(int needMana, int power) : needMana(needMana), power(power) {}

Spell::~Spell() = default;

int Spell::getPower()
{
	return power;
}

int Spell::getNeedMana()
{
	return needMana;
}

std::string Spell::getName()
{
	return name;
}

void Spell::setPower(int power)
{
	this->power = power;
}

void Spell::setNeedMana(int needMana)
{
	this->needMana = needMana;
}

void Spell::setName(const std::string & name)
{
	this->name = name;
}
