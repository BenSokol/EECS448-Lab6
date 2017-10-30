/*
 * @Filename: LinkedListTests.hpp
 * @Author:   Ben Sokol <Ben>
 * @Email:    bensokol@ku.edu
 * @Created:  October 28th, 2017 [2:21pm]
 * @Modified: November 1st, 2017 [11:19am]
 *
 * Copyright (C) 2017 by Ben Sokol. All Rights Reserved.
 */


#pragma once

//#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unistd.h>
#include <vector>

#include "LinkedListOfInts.h"


#ifndef _UINT
	#define _UINT
	typedef unsigned int uint;
#endif


class LinkedListTests {
  public:
    LinkedListTests();
    LinkedListTests(int value);

    void printErrors();
    void runTests();

  private:
    void initalizeTests();

    void printVector(std::vector<int> vec);
    std::vector<int> createVector();

    void printResult(bool pass, std::string testName);

    bool testExpectedSize(bool passed, int linkedList, int expected);
    bool testExpectedVectors(bool passed, std::vector<int> linkedList, std::vector<int> expected);

    bool test01();
    bool test02();
    bool test03();
    bool test04();
    bool test05();
    bool test06();
    bool test07();
    bool test08();
    bool test09();
    bool test10();
    bool test11();
    bool test12();
    bool test13();
    bool test14();
		bool test15();
		bool test16();

    uint testSize;
    std::map<std::string, bool (LinkedListTests::*)()> tests;
};
