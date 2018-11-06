#pragma once
#include "Observer.h"
#include <list>
#include <iterator>

class Observable
{
public:
	Observable();
	virtual ~Observable() = 0;

	Observer& AddObserver(Observer& obs);
	void removeObserver(Observer& obs);

	void notifyObservers();

private:

	std::list<Observer*> obs;
};

