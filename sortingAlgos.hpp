#ifndef SORTINGALGOS_HPP
#define SORTINGALGOS_HPP

#include <iostream>
#include <time.h>
#include <vector>

class dataClass
{
private:
    const size_t n = 1000;
    std::vector<int> dataVec;
public:
    void randomizeData();
    dataClass();
    void displayData();
    void merge(std::vector<int>& vec, int left, int mid, int right);
    void myMergeSort(std::vector<int>& vec, int left, int right);
    std::vector<int> getData() { return dataVec; }
};

void merge(std::vector<int>& vec, int left, int mid, int right);
void myMergeSort(std::vector<int>& vec, int left, int right);

#endif /*SORTINGALGOS_HPP*/