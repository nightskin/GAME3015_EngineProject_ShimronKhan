#include "Input.h"
#include "Game.hpp"

ListenerManager::ListenerManager()
{
	
}

ListenerManager::~ListenerManager()
{

}

bool ListenerManager::CheckListener(Listener ev)
{
	if (GetAsyncKeyState(ev.bindChar) & 0x8000 || GetAsyncKeyState(ev.bindInt) & 0x8000)
	{
		eventList.push_back(ev);
		return true;
	}
	return false;
}

Listener ListenerManager::PrevEvent()
{
	if (eventList.size() > 1)
	{
		return eventList[eventList.size() - 2];
	}
	return none;
}

Listener ListenerManager::CurrentEvent()
{
	if (eventList.size() > 0)
	{
		return eventList[eventList.size() - 1];
	}
	return none;
}

void ListenerManager::AddListener(Listener ev)
{
	listeners.push_back(ev);
}




