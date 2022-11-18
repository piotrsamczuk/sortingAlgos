#include <gtest/gtest.h>
#include "../sortingAlgos.hpp"

struct sortingAlgosTest
    :public ::testing::Test
{
    virtual void SetUp() override
    {

    }
    virtual void TearDown() override
    {

    }
};

TEST(sortingAlgosTests, myMergeSort)
{
    std::vector<int> unsorted = {4, 1, INT32_MAX, 3, 2, 7, 16, INT32_MIN, 9, -55, 10, 14, 8};
    std::vector<int> sorted = {INT32_MIN, -55, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16, INT32_MAX};

    myMergeSort(unsorted, 0, unsorted.size() - 1);
    ASSERT_EQ(unsorted.size(), sorted.size());
    for(int i = 0; i < unsorted.size(); i++)
    {
        ASSERT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(sortingAlgosTest, randomizedMyMergeSort)
{
    srand(time(NULL));
    std::vector<int> unsorted(1000);
    for(auto& i : unsorted)
    {
        i = (rand() % 100000) - 50000;
    }

    myMergeSort(unsorted, 0, unsorted.size() - 1);
    for(int i = 0; i < unsorted.size() - 1; i++)
    {
        ASSERT_LE(unsorted[i], unsorted[i + 1]);
    }
}