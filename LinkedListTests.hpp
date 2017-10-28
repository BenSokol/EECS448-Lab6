/*
 * @Filename: LinkedListTests.hpp
 * @Author:   Ben Sokol <Ben>
 * @Email:    bensokol@ku.edu
 * @Created:  October 28th, 2017 [2:21pm]
 * @Modified: October 29th, 2017 [2:43am]
 *
 * Copyright (C) 2017 by Ben Sokol. All Rights Reserved.
 */


#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>

#include "LinkedListOfInts.h"

#ifndef WIN32
  #include <unistd.h>
  #define sleep_ms(ms) usleep(ms * 1000)
#endif

#ifndef _UINT
	#define _UINT
	typedef unsigned int uint;
#endif

#define PRINT_VECTORS 1


class LinkedListTests {
  public:
    LinkedListTests();
    LinkedListTests(int value);
    void runTests();
    void printErrors();
  private:
    void printVector(std::vector<int> vec);
    std::vector<int> createVector();
    void printResult(bool pass, std::string testName);
    void initalizeTests();
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
    uint testSize;
    std::map<std::string, bool (LinkedListTests::*)()> tests;
};
