#include "StateMachine.h"

StateMachine::StateMachine(Game* game)
{
	titleState = new TitleState(game);
	menuState = new MenuState(game);
	instructionState = new InstructionState(game);
	gameState = new GameState(game);
	
	states.push_back(titleState);
	states.push_back(menuState);
	states.push_back(instructionState);
	states.push_back(gameState);
}

void StateMachine::load()
{
	titleState->mActive = false;
	titleState->load();
	menuState->mActive = false;
	menuState->load();
	instructionState->load();
	instructionState->mActive = false;
	gameState->load();
	gameState->mActive = false;

	states[0]->load();
}

void StateMachine::draw()
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->mActive)
		{
			states[i]->draw();
		}
	}
}

void StateMachine::update(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->mActive)
		{
			states[i]->update(gt);
		}
	}
}

void StateMachine::setState(State* state)
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] == state)
		{
			states[i]->mActive = true;
		}
		else
		{
			states[i]->mActive = false;
		}
	}
}
