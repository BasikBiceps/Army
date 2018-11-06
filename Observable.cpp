#include "stdafx.h"
#include "Observable.h"


Observable::Observable() {}

Observable::~Observable()
{
	obs.clear();
}

Observer & Observable::AddObserver(Observer & obs)
{
	this->obs.push_back(&obs);
	return obs;
}

void Observable::removeObserver(Observer & obs)
{
	this->obs.remove(&obs);
}

void Observable::notifyObservers()
{
	for (auto it : obs) {
		it->handleEvent(*this);
	}
}
