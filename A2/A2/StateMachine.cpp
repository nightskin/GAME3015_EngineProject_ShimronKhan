#include "StateMachine.h"
#include <iostream>

StateMachine::StateMachine(Game* game)
{
	mGame = game;
	titleState = new TitleState(game);
	menuState = new MenuState(game);
	instructionState = new InstructionState(game);
	gameState = new GameState(game);

	states.push_back(titleState);
	states.push_back(menuState);
	states.push_back(instructionState);
	states.push_back(gameState);

	gotToMenu.name = "menu";
	gotToMenu.bindInt = 0x20;
}

void StateMachine::load()
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->mOrder = i;
		states[i]->load();
	}
}

void StateMachine::update(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->update(gt);
	}
}

void StateMachine::draw(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->draw(gt);
	}
}

void StateMachine::input(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->mOrder == 0)
		{
			states[i]->getInputs(gt);
			if (states[i] == titleState)
			{
				if (listeners.CheckListener(gotToMenu))
				{
					SetState(menuState);
				}
			}

		}
	}
}

void StateMachine::SetState(State* s)
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] == s)
		{
			states[i]->mOrder = 0;
		}
		else
		{
			states[i]->mOrder = 10;
		}
		std::cout << states[i]->mOrder << std::endl;
	}
}
