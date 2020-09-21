#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include "arrayTracker.h"
#include "ksmallSolution.h"
#include "ksmallTester.h"
#include "ksmallRuleChecker.h"

using namespace std;

int main() {
  ksmallSolution temp;
  ksmallTester tester;
    ksmallRuleChecker checkRules;

    if(checkRules.checkString("ksmallSolution.cpp", "vector") != -1) {
        cout << "vector found\n";
    }
    if(checkRules.checkString("ksmallSolution.cpp", "[") != -1) {
        cout << "array found\n";
    }

  int testCaseSize = 10;
  int testCaseRuns = 10;
  int score;
  int scoreAverage = 0;

  for(int i=0; i<testCaseRuns; i++) {
    arrayTracker* test;
    test = new arrayTracker(testCaseSize, i+1);
    score = tester.testPartition(test, temp.kSmallPartition(test, 0 , testCaseSize-1));
    if (score>=0)
      scoreAverage += score/testCaseRuns;
    else
      cout << "fail" << '\n';
    delete test;
  }
  cout << "par avg score: " << scoreAverage << '\n';

  arrayTracker* test2 = new arrayTracker(10);

  test2->setItem(0,55);
  test2->setItem(1,53);
  test2->setItem(2,51);
  test2->setItem(3,49);
  test2->setItem(4,47);
  test2->setItem(5,8);
  test2->setItem(6,7);
  test2->setItem(7,6);
  test2->setItem(8,8);
  test2->setItem(9,60);

  test2->displayArray();

  ksmallSolution temp2;
  cout << "\n temp2 " << temp2.kSmall(5,test2,0,test2->getSize()-1) << " \n";
  test2->displayArray();


}
