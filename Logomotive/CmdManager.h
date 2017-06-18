#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "CommandBox.h"

class CmdManager: public CommandBox
{
public:
	CmdManager();
	void checkCommand();
	std::string command;
	bool isGood;

private:
	void onExit();
	void onWrongCmd();
	void onHelp();
};

