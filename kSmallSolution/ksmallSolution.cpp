#ifndef KSMALL_SOLUTION_CPP
#define KSMALL_SOLUTION_CPP

#include "ksmallSolution.hpp"
#include "arrayTracker.hpp"

ksmallSolution::ksmallSolution() {
}

void ksmallSolution::arraySwap(arrayTracker* swappingArray, int indexA, int indexB)
{
  int temp = swappingArray->getItem(indexA);
  swappingArray->setItem(indexA, swappingArray->getItem(indexB));
  swappingArray->setItem(indexB, temp);
}


int ksmallSolution::kSmallPartition(arrayTracker* unsortedArray, int first, int last)
{

  int pivotIdx = first;
  int pivotValue = unsortedArray->getItem(pivotIdx);

  for(int compareIdx = first + 1; compareIdx < last + 1; compareIdx++) {
    if(unsortedArray->getItem(compareIdx) < pivotValue) {
      arraySwap(unsortedArray, compareIdx, pivotIdx+1);
      arraySwap(unsortedArray, pivotIdx, pivotIdx+1);
      pivotIdx++;
    }
  }
  return pivotIdx;
}


int ksmallSolution::kSmall(int k, arrayTracker* unsortedArray, int first, int last)
{
    //int kthSmallestValue = 0;
    int pivotIndex = kSmallPartition(unsortedArray, first, last);

    if(k < pivotIndex - first + 1){
        return kSmall(k, unsortedArray, first, pivotIndex - 1);
    }
    else if(k == pivotIndex - first + 1){
        return pivotIndex;
    }else{
        return kSmall(k - (pivotIndex - first +1), unsortedArray, pivotIndex + 1, last);
    }

    return pivotIndex;
}

#endif /* KSMALL_SOLUTION_CPP */
