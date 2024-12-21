#pragma once
#include <string>
#include <map>
#include "LexicalAnalyzer.h"
#include "SintaxisAnalyzer.h"
#include "Solver.h"
/// <summary>
/// ����������� �����, ������� �� ���� �������� ������ - ���������, �������� �������� ���������� ���������
/// ���������� - ������� �������� (�� ��� ������ �� ����������, ���� ��������� �� ������)
/// </summary>
class Translator
{
public:
	double translate(const std::string&, std::map<std::string, double>&);

	void destr(std::vector<Term*>&);
};

