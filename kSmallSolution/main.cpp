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
}
