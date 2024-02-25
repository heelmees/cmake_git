﻿#include <iostream>
#include <fstream>
#include <func.hpp>

int main()
{
	std::string fileName = "input.txt";
	auto runNum = Func::getLastRunNumber(fileName);
	if (runNum == -1) {
		//Начать заново
		runNum = 0;
	}
	runNum++;
	auto newLine = Func::getDebugLine(runNum);
	Func::appendStringToFile(fileName, newLine);
}