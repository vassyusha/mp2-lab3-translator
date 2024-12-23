#pragma once
/// ����� ����� �������������� ������, �.�. �������� �� ������, ����� �������� �� ������������ ���������
#include <stack>
#include <string>
#include <vector>
#include "Term.h"

class SintaxisAnalyzer
{
public:
	bool bracketCorrectness(const std::vector<Term*>&);

	bool analysis(const std::vector<Term*>&);

	std::vector<Term*> poland(std::vector<Term*>&);
};

