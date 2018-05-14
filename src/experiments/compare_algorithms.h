#ifndef KNAPSACK_PROBLEM_COMPARE_ALGORITHMS_H
#define KNAPSACK_PROBLEM_COMPARE_ALGORITHMS_H

void nEqualBkpSize(unsigned int max_n, unsigned int repetitions);
void fixedBkpSize(unsigned long bkpSize, unsigned int max_n, unsigned int repetitions);
void allItemsSize1_nEqualsW(unsigned int max_n, unsigned int repetitions);
void allItemsSize1Value1_nEqualsW(unsigned int max_n, unsigned int repetitions);
void bkpSizeExponential(unsigned int max_n, unsigned int repetitions);

#endif //KNAPSACK_PROBLEM_COMPARE_ALGORITHMS_H
