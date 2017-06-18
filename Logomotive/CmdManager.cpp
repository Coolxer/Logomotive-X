#include "stdafx.h"
#include "CmdManager.h"

CmdManager::CmdManager()
{
	
}

void CmdManager::checkCommand()
{
	isGood = true;
	if (command == "exit")
		onExit();
	else if (command == "help")
		onHelp();
	else if (command == "a")
		std::cout<<"a";
	else if (command == "b")
		std::cout << "b";
	else if (command == "c")
		std::cout << "c";
	else if (command == "d")
		std::cout << "d";
	else if (command == "")
	{
		std::cout << "Write in any command!" << std::endl;
		isGood = false;
	}	
	else
	{
		onWrongCmd();
		isGood = false;
	}	
}

void CmdManager::onExit()
{
	exit(EXIT_SUCCESS);
}

void CmdManager::onWrongCmd()
{
	std::cout << "Command not found." << std::endl;
	std::cout << "To see available commands insert help." << std::endl;
}

void CmdManager::onHelp()
{
	std::cout << "Here are the commands you can use: " << std::endl;
	std::cout << "cls" << std::endl << "exit" << std::endl << "..." << std::endl << "help";
}

