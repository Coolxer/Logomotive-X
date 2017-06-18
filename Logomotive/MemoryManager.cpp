#include "stdafx.h"
#include "MemoryManager.h"

MemoryManager::MemoryManager()
{

}


void MemoryManager::writeInTable()
{
	lastCmdTable[0] = cmdM.command;
}

std::string MemoryManager::readFromTable()
{
	std::string x = lastCmdTable[0];

	return x;
}
