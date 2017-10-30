/*
 * @Filename: main.cpp
 * @Author:   Ben Sokol <Ben>
 * @Email:    bensokol@ku.edu
 * @Created:  October 28th, 2017 [2:20pm]
 * @Modified: October 31st, 2017 [2:05pm]
 *
 * Copyright (C) 2017 by Ben Sokol. All Rights Reserved.
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
