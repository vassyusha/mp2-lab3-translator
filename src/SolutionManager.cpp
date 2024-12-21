#include "SolutionManager.h"

void SolutionManager::manage() {
	std::string s;
	Translator tr;

	while (true) {
		std::getline(std::cin, s);
		try {
			std::cout << tr.translate(s, this->data) << "\n";
		}
		catch (const char* s) { std::cout << s << "\n"; }
	}
}