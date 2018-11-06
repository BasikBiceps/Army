#pragma once

class Observable;

class Observer
{
public:
	Observer();
	~Observer();

	virtual void handleEvent(Observable & obsble ) = 0;
};

