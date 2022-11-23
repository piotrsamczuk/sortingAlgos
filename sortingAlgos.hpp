#ifndef SORTINGALGOS_HPP
#define SORTINGALGOS_HPP

#include <iostream>
#include <vector>

class myMergeSortClass
{
public:
    // void merge(std::vector<int>& vec, int left, int mid, int right);
    // void myMergeSort(std::vector<int>& vec, int left, int right);
    // std::vector<int> returningMerge(const std::vector<int>& left, const std::vector<int>& right);
    // std::vector<int> returningMyMergeSort(std::vector<int> vec);
};

void merge(std::vector<int>& vec, int left, int mid, int right);
void myMergeSort(std::vector<int>& vec, int left, int right);
std::vector<int> returningMerge(const std::vector<int>& left, const std::vector<int>& right);
std::vector<int> returningMyMergeSort(std::vector<int> vec);

#endif /*SORTINGALGOS_HPP*/