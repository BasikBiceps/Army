#include "SpellCaster.h"
#include "PhysAttack.h"


SpellCaster::SpellCaster() {
	book = new Spellbook();
}

SpellCaster::SpellCaster(State & state, MagicAttack & magAttack, Spellbook & book) : Unit(state, magAttack) {
	this->book = &book;
}

SpellCaster::~SpellCaster()
{
	delete book;
}

Spellbook * SpellCaster::readBook()
{
	return book;
}


