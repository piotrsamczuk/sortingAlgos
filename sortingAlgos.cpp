#include "sortingAlgos.hpp"

void merge(std::vector<int>& vec, int left, int mid, int right)
{
    int leftsize = mid - left + 1;
    int rightsize = right - mid;
    std::vector<int> v1;
    std::vector<int> v2;
    for(int i = 0; i < leftsize; i++)
    {
        v1.push_back(vec[left + i]);
    }
    for(int i = 0; i < rightsize; i++)
    {
        v2.push_back(vec[mid + 1 + i]);
    }

    int i = 0;  //v1 index
    int j = 0;  //v2 index
    int k = left;  //src vec index
    while(i < leftsize and j < rightsize)
    {
        if(v1[i] < v2[j])
        {
            vec[k] = v1[i];
            i++;
            k++;
        }
        else
        {
            vec[k] = v2[j];
            j++;
            k++;
        }
    }

    while(i < leftsize)
    {
        vec[k] = v1[i];
        k++;
        i++;
    }
    while(j < rightsize)
    {
        vec[k] = v2[j];
        k++;
        j++;
    }
}

void myMergeSort(std::vector<int>& vec, int left, int right) //make a version which returns a vector
{
    if(left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    myMergeSort(vec, left, mid);        //left side
    myMergeSort(vec, mid + 1, right);    //right side
    merge(vec, left, mid, right);
}

std::vector<int> mergeSortedDataVecs(const std::vector<int>& v1, const std::vector<int>& v2)
{
    if(v1.empty())
    {
        return v2;
    }
    if(v2.empty())
    {
        return v1;
    }

    std::vector <int> res;
    int i = 0;
    int j = 0;
    while(i < v1.size() and j < v2.size())
    {
        if(v1[i] < v2[j])
        {
            res.push_back(v1[i]);
            i++;
        }
        else
        {
            res.push_back(v2[j]);
            j++;
        }
    }

    if(i == v1.size())
    {
        for(j; j < v2.size(); j++)
        {
            res.push_back(v2[j]);
        }
    }
    else if(j == v2.size())
    {
        for(i; i < v1.size(); i++)
        {
            res.push_back(v1[i]);
        }
    }
    return res;
}
