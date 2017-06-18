#pragma once
#include<string>

class MemoryManager
{
public:
	MemoryManager();
	void writeInTable();
	std::string readFromTable();

private:
	std::string lastCmdTable[5];
	int tableCounter;
};

