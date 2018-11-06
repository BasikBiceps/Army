// ArmyV3.0.cpp : Defines the entry point for the console application.
//

#include "Unit.h"
#include "Vampire.h"
#include "Soldier.h"
#include "Werewolf.h"
#include <typeinfo>
#include "Wizard.h"
#include "Necromancer.h"
#include "Priest.h"
#include "Warlock.h"

int main()
{
	Warlock w;
	Soldier a, c;
	Vampire b;
	Priest p;
	
	try {
		p.magicAttack(a, ATTACK_SPELL_METEOR);
		/*w.addDemon(*(new Demon()));
		w.addDemon(*(new Demon()));
		w.addDemon(*(new Demon()));*/
		w.attackWithDemons(b);
	}
	catch (NotEnoughManaException ex) {
		std::cout << "Something don't have mana" << std::endl;
	}
	catch (UnitIsDeadException ex) {
		std::cout << "Something die" << std::endl;
	}
	std::cout << w;
	std::cout << b;

    return 0;
}

