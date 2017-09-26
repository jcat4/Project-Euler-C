#include <stdio.h>
#include <time.h>

#define UPPER 1000000000L // larger for optimization tests

/*
  If we list all the natural numbers below 10 that are multiples of
  3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
  
  Find the sum of all the multiples of 3 or 5 below 1000.
*/

unsigned long sumMultiplesOf(int n);

int main() {
  time_t startTime, endTime;
  unsigned long i, sum = 0;
  double totalTime;
    
  printf("Original Solution: \n");
  time(&startTime);
  
  for (i = UPPER; i > 0; i--) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
      sum += i;
    }
  }
  
  time(&endTime);
  totalTime = difftime(endTime, startTime);
  printf("%lu\nCalculated in %f seconds\n", sum, totalTime);
  
  printf("Optimized Solution: \n");
  time(&startTime);

  sum = sumMultiplesOf(3) + sumMultiplesOf(5) - sumMultiplesOf(15);
  
  time(&endTime);
  totalTime = difftime(endTime, startTime);
  printf("%lu\nCalculated in %f seconds\n", sum, totalTime);
  return 0;
}

unsigned long sumMultiplesOf(int n) {
  unsigned long p = UPPER / n;
  return n * (p * (p + 1)) / 2;
}