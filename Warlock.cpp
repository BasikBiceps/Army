#include "stdafx.h"
#include "Warlock.h"
#include "AttackSpell.h"
#include "RegenerateHpSpell.h"
#include "RegenerateManaSpell.h"
#include "Vampire.h"
#include "Necromancer.h"

Warlock::Warlock() : SpellCaster(*(new State("Warlock", HEALTH_POINTS_WARLOCK, PHYS_DAMAGE_WARLOCK, MANA_WARLOCK, 0.5)), *(new MagicAttack()), *(new Spellbook())) {}

Warlock::Warlock(State & state, MagicAttack & magAttack, Spellbook & book) : SpellCaster(state, magAttack, book) {}

Warlock::~Warlock()
{
	demons.clear();
}

void Warlock::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
	attacked.getAttack().counterAttack(*this, attacked);
}

void Warlock::magicAttack(Unit & attacked, Spells spellNumber)
{
	Spell& spell = readBook()->getSpell(spellNumber);

	MagicAttack& magAttack = dynamic_cast<MagicAttack&>(getAttack());

	if (typeid(spell) == typeid(AttackSpell)) {
		magAttack.attack(*this, attacked, spell);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}

	if (typeid(attacked) == typeid(Vampire) || typeid(attacked) == typeid(Necromancer)) {
		magAttack.attack(*this, attacked, spell);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}

	magAttack.attack(*this, attacked, spell);
}

void Warlock::addDemon(Demon & demon)
{
	demons.push_back(&demon);
}

void Warlock::removeDemon(Demon & demon)
{
	demons.remove(&demon);
}

void Warlock::attackWithDemons(Unit & attacked)
{
	for (auto it : demons) {
		it->physicAttack(attacked);
		attacked.getAttack().counterAttack(*it, attacked);
	}
}

