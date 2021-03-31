#pragma once
#include "TitleState.h"
#include "MenuState.h"
#include "GameState.h"
#include "InstructionState.h"
#include "StateList.h"

class StateMachine
{
public:
	StateMachine(Game* game);
	void load();
	void draw();
	void update(const GameTimer& gt);
	void setState(State* state);
public:
	std::vector<State*> states;
	GameState* gameState;
	TitleState* titleState;
	MenuState* menuState;
	InstructionState* instructionState;
};