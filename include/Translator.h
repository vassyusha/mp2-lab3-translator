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
private:
	void destr(std::vector<Term*>&);
public:
	double translate(const std::string&, std::map<std::string, double>&);

	
};

