#pragma once
#include <map>
#include <string>
#include <iostream>
#include "Translator.h"
class SolutionManager
{
private:
	std::map<std::string, double> data;

	std::string inform = "";

public:
	void manage();
};

