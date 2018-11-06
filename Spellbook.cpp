#include "stdafx.h"
#include "Spellbook.h"
#include "SpellEnum.h"
#include "AttackSpell.h"
#include "RegenerateHpSpell.h"
#include "RegenerateManaSpell.h"

Spellbook::Spellbook()
{
	list.emplace(ATTACK_SPELL_METEOR, *(new AttackSpell(30, 60)));
	list.emplace(ATTACK_SPELL_FREEZ, *(new AttackSpell(40, 80)));
	list.emplace(ATTACK_SPELL_DRAKONIFORSL, *(new AttackSpell(50, 100)));
	list.emplace(MANA_REGENERATE_SPELL_SOUL_HEAL, *(new RegenerateManaSpell(30, 45)));
	list.emplace(MANA_REGENERATE_SPELL_MIND_HEAL, *(new RegenerateManaSpell(40, 60)));
	list.emplace(MANA_REGENERATE_SPELL_FEITH_HEAL, *(new RegenerateManaSpell(50, 75)));
	list.emplace(HP_REGENERATE_SPELL_HEAL_WOUNDS, *(new RegenerateHpSpell(30, 45)));
	list.emplace(HP_REGENERATE_SPELL_ARMOR_HEAL, *(new RegenerateHpSpell(40, 60)));
	list.emplace(HP_REGENERATE_SPELL_HEAL_RECUPERATION, *(new RegenerateHpSpell(50, 75)));
}

Spellbook::~Spellbook()
{
	list.clear();
}

Spell & Spellbook::addSpell(Spell & spell, Spells key)
{
	list.emplace(key, spell);
	return spell;
}

void Spellbook::removeSpell(Spells key)
{
	list.erase(key);
}

Spell & Spellbook::getSpell(Spells key)
{
	return list.find(key)->second;
}
