#include "stdafx.h"
#include "Wizard.h"
#include <typeinfo>
#include "AttackSpell.h"
#include "RegenerateHpSpell.h"
#include "RegenerateManaSpell.h"
#include "Necromancer.h"
#include "Vampire.h"

Wizard::Wizard() : SpellCaster(*(new State("Wizard", HEALTH_POINTS_WIZARD, PHYS_DAMAGE_WIZARD, MANA_WIZARD, 0.5)), *(new MagicAttack()), *(new Spellbook())) {}

Wizard::Wizard(State & state, MagicAttack & magAttack, Spellbook& book) : SpellCaster(state, magAttack,book) {}

Wizard::~Wizard() {}

void Wizard::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
	attacked.getAttack().counterAttack(*this, attacked);
}

void Wizard::magicAttack(Unit & attacked, Spells spellNumber)
{
	Spell& spell = readBook()->getSpell(spellNumber);

	MagicAttack& magAttack = dynamic_cast<MagicAttack&>(getAttack());

	if (typeid(spell) == typeid(AttackSpell)) {
		magAttack.attack(*this, attacked, spell);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}

	spell.setPower(spell.getPower() / 2);

	if (typeid(attacked) == typeid(Vampire) || typeid(attacked) == typeid(Necromancer)) {
		magAttack.attack(*this, attacked, spell);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}

	magAttack.attack(*this, attacked, spell);

}
