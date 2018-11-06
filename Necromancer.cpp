#include "stdafx.h"
#include "Necromancer.h"
#include <typeinfo>
#include "AttackSpell.h"
#include "RegenerateHpSpell.h"
#include "RegenerateManaSpell.h"
#include "Necromancer.h"
#include "Vampire.h"

Necromancer::Necromancer() : SpellCaster(*(new State("Wizard", HEALTH_POINTS_NECROMANCER, PHYS_DAMAGE_NECROMANCER, MANA_NECROMANCER, 0.5)), *(new MagicAttack()), *(new Spellbook())) {}

Necromancer::Necromancer(State & state, MagicAttack & magAttack, Spellbook & book) : SpellCaster(state, magAttack, book) {}

Necromancer::~Necromancer() {}

void Necromancer::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
	attacked.AddObserver(*this);
	attacked.getAttack().counterAttack(*this, attacked);
}

void Necromancer::magicAttack(Unit & attacked, Spells spellNumber)
{
	Spell& spell = readBook()->getSpell(spellNumber);

	MagicAttack& magAttack = dynamic_cast<MagicAttack&>(getAttack());

	if (typeid(spell) == typeid(AttackSpell)) {
		magAttack.attack(*this, attacked, spell);
		attacked.AddObserver(*this);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}

	if (typeid(attacked) == typeid(Vampire)) {
		magAttack.attack(*this, attacked, spell);
		attacked.AddObserver(*this);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}

	magAttack.attack(*this, attacked, spell);
}

void Necromancer::handleEvent(Observable& obsble)
{
	Unit& unit = dynamic_cast<Unit&>(obsble);
	if (!getState().ensureIsAlive()) {
		throw UnitIsDeadException();
	}

	this->getState().setHealthPoint(this->getState().getHealthPoint() + unit.getState().getHealthPointLimit() / 4);

	if (this->getState().getHealthPoint() > this->getState().getHealthPointLimit()) {
		this->getState().setHealthPoint(this->getState().getHealthPointLimit());
	}	
}
