/*
 * @Filename: LinkedListTests.cpp
 * @Author:   Ben Sokol <Ben>
 * @Email:    bensokol@ku.edu
 * @Created:  October 28th, 2017 [2:21pm]
 * @Modified: November 1st, 2017 [11:35am]
 *
 * Copyright (C) 2017 by Ben Sokol. All Rights Reserved.
 */


#include "LinkedListTests.hpp"


LinkedListTests::LinkedListTests() {
  std::cout << "\n\033[36mWelcome to LinkedList Tester!\033[39;49;00m\n\n";
  testSize = 10;
  initalizeTests();
}


LinkedListTests::LinkedListTests(int value) {
  std::cout << "\n\033[36mWelcome to LinkedList Tester!\033[39;49;00m\n\n";
  testSize = (value > 0 ? value : 10);
  initalizeTests();
}


void LinkedListTests::initalizeTests() {
  std::string testSizeStr = std::to_string(testSize);
  std::string plural = (testSize > 1 ? "'s" : "");
  std::cout << "\rInitalizing Tests";
  tests["Test 01: isEmpty returns true when list is empty"] = &LinkedListTests::test01;
  tests["Test 02: isEmpty returns false when list is not empty"] = &LinkedListTests::test02;
  tests["Test 03: Size and vector return correct value after 1 addFront"] = &LinkedListTests::test03;
  tests["Test 04: Size and vector return correct value after 1 addBack"] = &LinkedListTests::test04;
  tests["Test 05: Size and vector return correct value after " + testSizeStr + " addFront" + plural] = &LinkedListTests::test05;
  tests["Test 06: Size and vector return correct value after " + testSizeStr + " addBack" + plural] = &LinkedListTests::test06;
  tests["Test 07: Size and vector return correct value after " + testSizeStr + " add" + plural + " and " + testSizeStr + " removeFront" + plural] = &LinkedListTests::test07;
  tests["Test 08: Size and vector return correct value after " + testSizeStr + " add" + plural + " and " + testSizeStr + " removeBack" + plural] = &LinkedListTests::test08;
  tests["Test 09: Size of populated list is decreased by 1 by removeFront"] = &LinkedListTests::test09;
  tests["Test 10: Size of populated list is decreased by 1 by removeBack"] = &LinkedListTests::test10;
  tests["Test 11: removeFront returns false on empty list"] = &LinkedListTests::test11;
  tests["Test 12: removeBack returns false on empty list"] = &LinkedListTests::test12;
  tests["Test 13: search returns true if value is in list"] = &LinkedListTests::test13;
  tests["Test 14: search returns false if value is not in the list"] = &LinkedListTests::test14;
  tests["Test 15: search returns true if value is in the list multiple times"] = &LinkedListTests::test15;
  tests["Test 16: Normal Usage Test"] = &LinkedListTests::test16;
  std::cout << "\r" << tests.size() << " Tests have been initalized";
}


void LinkedListTests::printVector(std::vector<int> vec) {
  if (vec.size() > 15) {
    std::cout << "Please use a smaller test size (testSize <= 15) to view vectors.";
    return;
  }
  std::cout << "[";
  for (uint i = 0; i < vec.size(); i++) {
    std::cout << ((vec[i] < 0) ? "" : " ") << vec[i] << ((i < vec.size() - 1) ? ", " : "");
  }
  std::cout << "]";
}


std::vector<int> LinkedListTests::createVector() {
  std::vector<int> vec;
  srand(time(NULL));
  for (uint i = 0; i < testSize; i++) {
    vec.push_back(rand()%(testSize * 10));
    if (vec[i] % 2) {
      vec[i] *= -1;
    }
  }
  return vec;
}


void LinkedListTests::printResult(bool pass, std::string testName) {
  std::cout << "\n" << testName << (pass ? ": \033[32mPASSED\033[39;49;00m" : ": \033[31mFAILED\033[39;49;00m") << "\n";
  std::cout.flush();
}


bool LinkedListTests::testExpectedSize(bool passed, int linkedList, int expected) {
  if(linkedList != expected) {
    std::cout << "\n\t The size recieved: " << linkedList << "\n\t The size expected: " << expected;
    return false;
  }
  return passed;
}


bool LinkedListTests::testExpectedVectors(bool passed, std::vector<int> linkedList, std::vector<int> expected) {
  if(linkedList != expected) {
    if (expected.size() > 15 || linkedList.size() > 15) {
      std::cout << "\n\t The vector received from LinkedListOfInts is not the same as the expected vector.";
      std::cout << "\n\t Please use a smaller test size (testSize <= 15) to view the vectors.";
      return passed;
    }
    std::cout << "\n\t The vector recieved: ";
    printVector(linkedList);
    std::cout << "\n\t The vector expected: ";
    printVector(expected);
    return false;
  }
  return passed;
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


void LinkedListTests::runTests() {
  std::cout << "\n\nRunning Tests:";
  for (auto test : tests) {
    printResult((this->*(test.second))(), test.first);
    std::cout.flush();
  }
  std::cout << "\nTesting Complete\n";
}

// isEmpty returns true when list is empty
bool LinkedListTests::test01() {
  bool passed = true;
  auto list = new LinkedListOfInts();
  passed = list->isEmpty() && (list->size() == 0);
  delete list;
  return passed;
}

// isEmpty returns false when list is not empty
bool LinkedListTests::test02() {
  bool passed = true;
  std::vector<int> vec(1, 1);
  auto list = new LinkedListOfInts();
  list->addFront(1);
  passed = (list->size() == 1) && (vec == list->toVector() && !list->isEmpty());
  delete list;
  return passed;
}

// Size and vector return correct value after 1 addFront
bool LinkedListTests::test03() {
  bool passed = true;
  std::vector<int> vec(1, 1);
  auto list = new LinkedListOfInts();
  list->addFront(1);
  passed = (list->size() == 1) && (vec == list->toVector());
  delete list;
  return passed;
}

// Size and vector return correct value after 1 addBack
bool LinkedListTests::test04() {
  bool passed = true;
  std::vector<int> vec(1, 1);
  auto list = new LinkedListOfInts();
  list->addBack(1);
  passed = (list->size() == 1) && (vec == list->toVector());
  delete list;
  return passed;
}

// Size and vector return correct value after (testSize) addFront(s)
bool LinkedListTests::test05() {
  bool passed = true;
  std::vector<int> vec = createVector();
  auto list = new LinkedListOfInts();
  std::cout << "\n";

  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Adding " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    list->addFront(vec[vec.size() - i]);
  }

  // Is the size correct?
  passed = testExpectedSize(passed, list->size(), (int)vec.size());

  // Are the vectors the same?
  passed = testExpectedVectors(passed, list->toVector(), vec);

  delete list;
  return passed;
}

// Size and vector return correct value after (testSize) addBacks(s)
bool LinkedListTests::test06() {
  bool passed = true;
  std::vector<int> vec = createVector();
  auto list = new LinkedListOfInts();
  std::cout << "\n";

  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Adding " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    list->addBack(vec[i - 1]);
  }

  // Is the size correct?
  passed = testExpectedSize(passed, list->size(), (int)vec.size());

  // Are the vectors the same?
  passed = testExpectedVectors(passed, list->toVector(), vec);

  delete list;
  return passed;
}

// Size and vector return correct value after (testSize) adds and removeFronts(s)
bool LinkedListTests::test07() {
  bool passed = true;
  std::vector<int> vec = createVector();
  auto list = new LinkedListOfInts();

  std::cout << "\n";
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Adding " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    list->addFront(vec[vec.size() - i]);
  }

  std::cout << "\n";
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Removing " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    list->removeFront();
  }
  vec.clear();

  // Is the size correct?
  passed = testExpectedSize(passed, list->size(), 0);

  // Are the vectors the same?
  passed = testExpectedVectors(passed, list->toVector(), vec);

  delete list;
  return passed;
}

// Size and vector return correct value after (testSize) adds and removeBack(s)
bool LinkedListTests::test08() {
  bool passed = true;
  std::vector<int> vec = createVector();
  auto list = new LinkedListOfInts();

  std::cout << "\n";
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Adding " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    list->addFront(vec[vec.size() - i]);
  }

  std::cout << "\n";
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Removing " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    list->removeBack();
  }
  vec.clear();

  // Is the size correct?
  passed = testExpectedSize(passed, list->size(), 0);

  // Are the vectors the same?
  passed = testExpectedVectors(passed, list->toVector(), vec);

  delete list;
  return passed;
}

// Size of populated list is decreased by 1 by removeFront
bool LinkedListTests::test09() {
  bool passed = true;
  std::vector<int> vec = createVector();
  auto list = new LinkedListOfInts();
  std::cout << "\n";

  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Adding " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    list->addFront(vec[vec.size() - i]);
  }
  std::cout << "\r\t Finished Adding " << vec.size() << " nodes, calling removeFront";
  list->removeFront();
  for (uint i = 0; i < (vec.size() - 1); i++) {
    vec[i] = vec[i + 1];
  }
  vec.pop_back();

  // Is the size correct?
  passed = testExpectedSize(passed, list->size(), vec.size());

  // Are the vectors the same?
  passed = testExpectedVectors(passed, list->toVector(), vec);

  delete list;
  return passed;
}

// Size of populated list is decreased by 1 by removeBack
bool LinkedListTests::test10() {
  bool passed = true;
  std::vector<int> vec = createVector();
  auto list = new LinkedListOfInts();
  std::cout << "\n";

  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Adding " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    list->addFront(vec[vec.size() - i]);
  }
  std::cout << "\r\t Finished Adding " << vec.size() << " nodes, calling removeBack";
  list->removeBack();
  vec.pop_back();

  // Is the size correct?
  passed = testExpectedSize(passed, list->size(), vec.size());

  // Are the vectors the same?
  passed = testExpectedVectors(passed, list->toVector(), vec);

  delete list;
  return passed;
}

// removeFront returns false on empty list
bool LinkedListTests::test11() {
  auto list = new LinkedListOfInts();
  bool passed = !list->removeFront();
  delete list;
  return passed;
}

// removeBack returns false on empty list
bool LinkedListTests::test12() {
  auto list = new LinkedListOfInts();
  bool passed = !list->removeFront();
  delete list;
  return passed;
}

// search returns true if value is in list
bool LinkedListTests::test13() {
  bool passed = true;
  std::vector<int> vec = createVector();
  auto list = new LinkedListOfInts();

  std::cout << "\n";
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Adding " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    list->addFront(vec[vec.size() - i]);
  }

  std::cout << ((vec.size() > 0) ? "\n" : "");
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Searching " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    passed = ((!list->search(vec[i - 1])) ? false : passed);
  }

  delete list;
  return passed;
}

// search returns false if value is not in the list
bool LinkedListTests::test14() {
  auto list = new LinkedListOfInts();
  bool passed = !list->search(1);
  delete list;
  return passed;
}

// search returns true if value is in the list multiple times
bool LinkedListTests::test15() {
  bool passed = true;
  std::vector<int> vec = createVector();
  auto list = new LinkedListOfInts();

  std::cout << "\n";
  list->addBack(100);
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Adding " << i << "/" << (vec.size() + 2) << " nodes";
    std::cout.flush();
    list->addFront(vec[vec.size() - i]);
  }
  std::cout << "\r\t Adding " << (vec.size() + 2) << "/" << (vec.size() + 2) << " nodes";
  vec.push_back(100);
  std::cout << "\r\t Adding " << (vec.size() + 1) << "/" << (vec.size() + 1) << " nodes";
  vec.emplace(vec.begin(),100);
  list->addFront(100);

  std::cout << "\n";
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Searching " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    passed = ((!list->search(vec[i - 1])) ? false : passed);
  }

  delete list;
  return passed;
}

// Normal Usage Test
bool LinkedListTests::test16() {
  bool passed = true;
  std::vector<int> vec = createVector();
  auto list = new LinkedListOfInts();

  std::cout << "\n";
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Adding " << i << "/" << vec.size() << " nodes using addFront";
    std::cout.flush();
    list->addFront(vec[vec.size() - i]);
  }

  std::cout << "\n";
  for (uint i = 1; i <= (5 > vec.size() ? vec.size() : 5); i++) {
    std::cout << "\r\t Removing " << i << "/" << (5 > vec.size() ? vec.size() : 5) << " nodes using removeBack";
    std::cout.flush();
    list->removeBack();
    vec.pop_back();
  }

  std::cout << "\n\t Adding 2 nodes using addFront then addBack";
  list->addFront(100);
  vec.emplace(vec.begin(),100);
  list->addBack(100);
  vec.push_back(100);

  std::cout << "\n\t Removing 2 nodes using removeFront then removeBack";
  list->removeFront();
  for (uint i = 0; i < (vec.size() - 1); i++) {
    vec[i] = vec[i + 1];
  }
  vec.pop_back();
  list->removeBack();
  vec.pop_back();

  std::cout << ((vec.size() > 0) ? "\n" : "");
  for (uint i = 1; i <= vec.size(); i++) {
    std::cout << "\r\t Searching " << i << "/" << vec.size() << " nodes";
    std::cout.flush();
    passed = ((!list->search(vec[i - 1])) ? false : passed);
  }

  // Is the size correct?
  passed = testExpectedSize(passed, list->size(), vec.size());

  // Are the vectors the same?
  passed = testExpectedVectors(passed, list->toVector(), vec);

  delete list;
  return passed;
}
