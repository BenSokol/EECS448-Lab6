/*
* @Filename: LinkedListTests.cpp
* @Author:   Ben Sokol <Ben>
* @Email:    bensokol@ku.edu
* @Created:  October 28th, 2017 [2:21pm]
 * @Modified: October 29th, 2017 [2:37am]
*
* Copyright (C) 2017 by Ben Sokol. All Rights Reserved.
*/

#include "LinkedListTests.hpp"


LinkedListTests::LinkedListTests() {
  std::cout << "\nWelcome to LinkedList Tester!";
  testSize = 10;
  initalizeTests();
}


LinkedListTests::LinkedListTests(int value) {
  std::cout << "\nWelcome to LinkedList Tester!\n\n";
  testSize = value;
  initalizeTests();
}


void LinkedListTests::initalizeTests() {
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 01/13";
  tests["Test 01: Size of empty list is zero"] = &LinkedListTests::test01;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 02/13";
  tests["Test 02: Size and vector return correct value after 1 addFront"] = &LinkedListTests::test02;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 03/13";
  tests["Test 03: Size and vector return correct value after 1 addBack"] = &LinkedListTests::test03;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 04/13";
  tests["Test 04: Size and vector return correct value after " + std::to_string(testSize) + " addFront" + (testSize > 1 ? "'s" : "")] = &LinkedListTests::test04;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 05/13";
  tests["Test 05: Size and vector return correct value after " + std::to_string(testSize) + " addBack" + (testSize > 1 ? "'s" : "")] = &LinkedListTests::test05;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 06/13";
  tests["Test 06: Size and vector return correct value after " + std::to_string(testSize) + " adds and removeFront" + (testSize > 1 ? "'s" : "")] = &LinkedListTests::test06;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 07/13";
  tests["Test 07: Size and vector return correct value after " + std::to_string(testSize) + " adds and removeBack" + (testSize > 1 ? "'s" : "")] = &LinkedListTests::test07;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 08/13";
  tests["Test 08: Size of populated list is decreased by 1 by removeFront"] = &LinkedListTests::test08;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 09/13";
  tests["Test 09: Size of populated list is decreased by 1 by removeBack"] = &LinkedListTests::test09;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 10/13";
  tests["Test 10: removeFront returns false on empty list"] = &LinkedListTests::test10;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 11/13";
  tests["Test 11: removeBack returns false on empty list"] = &LinkedListTests::test11;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 12/13";
  tests["Test 12: search returns true if value is in list"] = &LinkedListTests::test12;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rInitalizing Test 13/13";
  tests["Test 13: serach returns false if value is not in the list"] = &LinkedListTests::test13;
  sleep_ms(100);
  std::cout.flush();
  std::cout << "\rTests have been initalized";
  std::cout.flush();
}


void LinkedListTests::printVector(std::vector<int> vec) {
  std::cout << "[";
  for (uint i = 0; i < vec.size(); i++) {
    std::cout << vec[i];
    if(i < vec.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]";
}


std::vector<int> LinkedListTests::createVector() {
  std::vector<int> vec;
  srand(time(NULL));
  for (uint i = 0; i < testSize; i++) {
    vec.push_back(rand()%(testSize * 10));
  }
  return vec;
}


void LinkedListTests::printResult(bool pass, std::string testName) {
  std::cout << "\n" << testName << (pass ? ": \033[32mPASSED\033[39;49;00m" : ": \033[31mFAILED\033[39;49;00m") << "\n";
  std::cout.flush();
}


void LinkedListTests::runTests() {
  std::cout << "\n\nRunning Tests:";
  for (auto test : tests) {
    printResult((this->*(test.second))(), test.first);
    std::cout.flush();
    sleep_ms(200);
  }
  std::cout << "\nTesting Complete\n\n";
}


void LinkedListTests::printErrors() {
  std::cout << "\nThe following \033[31mERRORS\033[39;49;00m have been detected:\n";
  std::ifstream ifs("ErrorList.txt", std::ifstream::in);
  if(ifs) {
    while(!ifs.eof()) {
      std::string temp = "";
      getline(ifs,temp);
      std::cout << temp << "\n";
    }
  }
}

//Size of empty list is zero
bool LinkedListTests::test01() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  passed = list->isEmpty() && (list->size() == 0);
  delete list;
  return passed;
}

//Size and vector return correct value after 1 addFront
bool LinkedListTests::test02() {
  bool passed = true;
  std::vector<int> vec;
  vec.push_back(1);
  auto list = new LinkedListOfInts();
  list->addFront(1);
  passed = (list->size() == 1) && (vec == list->toVector());
  delete list;
  return passed;
}

//Size and vector return correct value after 1 addBack
bool LinkedListTests::test03() {
  bool passed = true;
  std::vector<int> vec;
  vec.push_back(1);
  auto list = new LinkedListOfInts();
  list->addBack(1);
  passed = (list->size() == 1) && (vec == list->toVector());
  delete list;
  return passed;
}

//Size and vector return correct value after (testSize) addFront(s)
bool LinkedListTests::test04() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  std::vector<int> vec = createVector();
  std::cout << "\n";

  for (uint i = 1; i <= testSize; i++) {
    std::cout << "\r\t Adding " << i << "/" << testSize << " nodes";
    std::cout.flush();
    list->addFront(vec[testSize - i]);
  }

  if(list->size() != (int)testSize) {
    std::cout << "\n\t The size recieved: " << list->size() << "\n\t The size expected: " << testSize;
    passed = false;
  }
  if(vec != list->toVector()) {
    #ifdef PRINT_VECTORS
      std::cout << "\n\t The vector recieved: ";
      printVector(list->toVector());
      std::cout << "\n\t The vector expected: ";
      printVector(vec);
    #endif
    passed = false;
  }

  delete list;
  return passed;
}

//Size and vector return correct value after (testSize) addBacks(s)
bool LinkedListTests::test05() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  std::vector<int> vec = createVector();
  std::cout << "\n";

  for (uint i = 1; i <= testSize; i++) {
    std::cout << "\r\t Adding " << i << "/" << testSize << " nodes";
    std::cout.flush();
    list->addBack(vec[i - 1]);
  }

  if(list->size() != (int)testSize) {
    std::cout << "\n\t The size recieved: " << list->size() << "\n\t The size expected: " << testSize;
    passed = false;
  }
  if(vec != list->toVector()) {
    #ifdef PRINT_VECTORS
      std::cout << "\n\t The vector recieved: ";
      printVector(list->toVector());
      std::cout << "\n\t The vector expected: ";
      printVector(vec);
    #endif
    passed = false;
  }

  delete list;
  return passed;
}

//Size and vector return correct value after (testSize) adds and removeFronts(s)
bool LinkedListTests::test06() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  std::vector<int> vec = createVector();
  std::cout << "\n";

  for (uint i = 1; i <= testSize; i++) {
    std::cout << "\r\t Adding " << i << "/" << testSize << " nodes";
    std::cout.flush();
    list->addFront(vec[testSize - i]);
  }
  std::cout << "\n";
  for (uint i = 1; i <= testSize; i++) {
    std::cout << "\r\t Removing " << i << "/" << testSize << " nodes";
    std::cout.flush();
    list->removeFront();
  }
  vec.clear();
  if(list->size() != 0) {
    std::cout << "\n\t The size recieved: " << list->size() << "\n\t The size expected: 0";
    #ifdef PRINT_VECTORS
      std::cout << "\n\t The vector recieved: ";
      printVector(list->toVector());
      std::cout << "\n\t The vector expected: ";
      printVector(vec);
    #endif
    passed = false;
  }

  delete list;
  return passed;
}

//Size and vector return correct value after (testSize) adds and removeBack(s)
bool LinkedListTests::test07() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  std::vector<int> vec = createVector();
  std::cout << "\n";

  for (uint i = 1; i <= testSize; i++) {
    std::cout << "\r\t Adding " << i << "/" << testSize << " nodes";
    std::cout.flush();
    list->addFront(vec[testSize - i]);
  }
  std::cout << "\n";
  for (uint i = 1; i <= testSize; i++) {
    std::cout << "\r\t Removing " << i << "/" << testSize << " nodes";
    std::cout.flush();
    list->removeBack();
  }
  vec.clear();

  if(list->size() != 0) {
    std::cout << "\n\t The size recieved: " << list->size() << "\n\t The size expected: 0";
    #ifdef PRINT_VECTORS
      std::cout << "\n\t The vector recieved: ";
      printVector(list->toVector());
      std::cout << "\n\t The vector expected: ";
      printVector(vec);
    #endif
    passed = false;
  }

  delete list;
  return passed;
}

//Size of populated list is decreased by 1 by removeFront
bool LinkedListTests::test08() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  std::vector<int> vec = createVector();
  std::cout << "\n";

  for (uint i = 1; i <= testSize; i++) {
    std::cout << "\r\t Adding " << i << "/" << testSize << " nodes";
    std::cout.flush();
    list->addFront(vec[testSize - i]);
  }
  std::cout << ", calling removeFront";
  list->removeFront();
  for (uint i = 0; i < (vec.size() - 1); i++) {
    vec[i] = vec[i + 1];
  }
  vec.pop_back();

  if(list->size() != ((int)testSize - 1) ) {
    std::cout << "\n\t The size recieved: " << list->size() << "\n\t The size expected: " << (testSize - 1);
    #ifdef PRINT_VECTORS
      std::cout << "\n\t The vector recieved: ";
      printVector(list->toVector());
      std::cout << "\n\t The vector expected: ";
      printVector(vec);
    #endif
    passed = false;
  }

  delete list;
  return passed;
}

//Size of populated list is decreased by 1 by removeBack
bool LinkedListTests::test09() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  std::vector<int> vec = createVector();
  std::cout << "\n";

  for (uint i = 1; i <= testSize; i++) {
    std::cout << "\r\t Adding " << i << "/" << testSize << " nodes";
    std::cout.flush();
    list->addFront(vec[testSize - i]);
  }
  std::cout << ", calling removeBack";
  list->removeBack();
  vec.pop_back();

  if(list->size() != ((int)testSize - 1) ) {
    std::cout << "\n\t The size recieved: " << list->size() << "\n\t The size expected: " << (testSize - 1);
    #ifdef PRINT_VECTORS
      std::cout << "\n\t The vector recieved: ";
      printVector(list->toVector());
      std::cout << "\n\t The vector expected: ";
      printVector(vec);
    #endif
    passed = false;
  }

  delete list;
  return passed;
}

//removeFront returns false on empty list
bool LinkedListTests::test10() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  passed = !list->removeFront();
  delete list;
  return passed;
}

//removeBack returns false on empty list
bool LinkedListTests::test11() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  passed = !list->removeFront();
  delete list;
  return passed;
}

//search returns true if value is in list
bool LinkedListTests::test12() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  list->addFront(1);
  passed = list->search(1);
  delete list;
  return passed;
}

//serach returns false if value is not in the list
bool LinkedListTests::test13() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  passed = !list->search(1);
  delete list;
  return passed;
}
