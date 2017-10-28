/**
*	@author
*	@date
*	@file main.cpp
*	@brief driver for LinkedList demo
*/

#include <locale>
#include "LinkedListTests.hpp"

bool isStringInt(std::string str) {
	for (unsigned int i = 0; i < str.size(); i++) {
		if(!isdigit(str[i])) { return false; }
	}
	return true;
}

int main(int argc, char** argv)
{
	LinkedListTests *tester = new LinkedListTests( ((argc > 1 && isStringInt(argv[1])) ? std::stoi((std::string)argv[1]) : 10) );
	tester->runTests();
	tester->printErrors();
	return 0;
}
