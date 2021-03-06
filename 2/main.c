#include <stdio.h>

#define UPPER 4000000

/*
  Each new term in the Fibonacci sequence is generated by adding the 
  previous two terms. By starting with 1 and 2, the first 10 terms will be:

    1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

  By considering the terms in the Fibonacci sequence whose values do not 
  exceed four million, find the sum of the even-valued terms.
*/

unsigned int sumOfEvenFib(int first, int second, unsigned int sum);

int main() {
  
  unsigned int sum = 0;
  printf("Original Solution: \n");
  printf("sum: %u\n", sumOfEvenFib(1, 2, sum));
  
  return 0;
}

unsigned int sumOfEvenFib(int first, int second, unsigned int sum) {
  if (first > UPPER) {
    return sum;
  }
  
  (first & 1) == 0 ? (sum) += first : 0;
  
  sumOfEvenFib(second, first + second, sum);
}