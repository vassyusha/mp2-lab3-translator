#pragma once
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>

#include "Term.h"
/// <summary>
/// �����, ���������� �� ����������� ����������� 
/// ����� ����� ������ ��������� �� ������ ������
/// ���� ���� �������� ��� ��������� �����, ���������� �� ���������� �����, �� ��� ��� ��� ���������� ��� �����
/// </summary>
class LexicalAnalyzer
{
public:
	double readNum(const std::string& s, int& pos);
	std::string readVar(const std::string& s, int& pos);
	std::vector<Term*> analysis(const std::string& s, std::map<std::string, double>&);
};

