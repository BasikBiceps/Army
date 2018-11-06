#pragma once
#include "Soldier.h"

class Demon :
	public Soldier
{
public:
	Demon();
	Demon(State& state, PhysAttack& physAttack);
	~Demon();
};