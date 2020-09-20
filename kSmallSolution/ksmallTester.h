#ifndef KSMALL_TESTER_H
#define KSMALL_TESTER_H

#include "arrayTracker.h"

class ksmallTester
{
private:
public:
  ksmallTester();
  int testPartition(arrayTracker* testSubject, int pivotIndex);
};
#endif /* KSMALL_TESTER_HPP */
