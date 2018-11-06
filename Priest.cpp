#include "stdafx.h"
#include "Priest.h"
#include "AttackSpell.h"
#include "RegenerateHpSpell.h"
#include "RegenerateManaSpell.h"
#include "Vampire.h"
#include "Necromancer.h"

Priest::Priest() : SpellCaster(*(new State("Priest", HEALTH_POINTS_PRIEST, PHYS_DAMAGE_PRIEST, MANA_PRIEST, 0.5)), *(new MagicAttack()), *(new Spellbook())) {}

Priest::Priest(State & state, MagicAttack & magAttack, Spellbook & book) : SpellCaster(state, magAttack, book) {}

Priest::~Priest() {}

void Priest::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
	attacked.getAttack().counterAttack(*this, attacked);
}

void Priest::magicAttack(Unit & attacked, Spells spellNumber)
{
	Spell& spell = readBook()->getSpell(spellNumber);

	MagicAttack& magAttack = dynamic_cast<MagicAttack&>(getAttack());

	if (typeid(spell) == typeid(AttackSpell)) {
		spell.setPower(spell.getPower() / 2);

		magAttack.attack(*this, attacked, spell);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}

	if (typeid(attacked) == typeid(Vampire) || typeid(attacked) == typeid(Necromancer)) {
		spell.setPower(spell.getPower() * 2);
		magAttack.attack(*this, attacked, spell);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}

	magAttack.attack(*this, attacked, spell);
}

