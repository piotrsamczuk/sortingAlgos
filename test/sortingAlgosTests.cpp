#include <gtest/gtest.h>
#include "../sortingAlgos.hpp"
#include <random>
#include <limits.h>

#define RANDOMIZEDVECTORSIZE 10000

class sortTest: public ::testing::Test
{
    protected:
    virtual void SetUp() override
    {

    }

    virtual void TearDown() override
    {

    }

    std::vector<int> randomizedVector(int n = RANDOMIZEDVECTORSIZE)
    {
        std::vector<int> vec(n);
        std::minstd_rand engine;
        std::uniform_int_distribution<> dist(INT_MIN, INT_MAX);
        for(int i = 0; i < n; i++)
        {
            vec[i] = dist(engine);
        }
        return vec;
    }

    std::vector<int> sameDataFill(const int n = 500, const int val = 0)
    {
        std::vector<int> vec(n, val);
        return vec;
    }


    std::vector<int> unsortedEdgeCases = {4, 1, INT_MAX, 3, 2, 7, 16, INT_MIN, 9, -55, 10, 14, 8};
    std::vector<int> ascendingEdgeCases = {INT_MIN, -55, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16, INT_MAX};
    std::vector<int> descendingEdgeCases = {INT_MAX, 16, 14, 10, 9, 8, 7, 4, 3, 2, 1, -55, INT_MIN};
    std::vector<int> randomizedBig = randomizedVector();
    std::vector<int> emptyVec = { };
    std::vector<int> sameData = sameDataFill();
};

class mergeSortTest: public sortTest
{

};


void intFill(std::vector<int>& src)
{
    std::minstd_rand engine;
    std::uniform_int_distribution<> dist(INT_MIN, INT_MAX);
    for(auto& i : src)
    {
        i = dist(engine);
    }
}

// BAD IDEA 
// TEST_F(nonReturningSortTest, allTests)
// {
//     size_t sizeBefore = ascendingEdgeCases.size();
//     myMergeSort(unsortedEdgeCases, 0, unsortedEdgeCases.size() - 1);
//     myMergeSort(descendingEdgeCases, 0, descendingEdgeCases.size() - 1);
//     myMergeSort(randomizedBig, 0, randomizedBig.size() - 1);
//     ASSERT_EQ(unsortedEdgeCases.size(), sizeBefore);
//     ASSERT_EQ(descendingEdgeCases.size(), sizeBefore);
//     ASSERT_EQ(randomizedBig.size(), RANDOMIZEDVECTORSIZE);

// }

TEST_F(mergeSortTest, nonReturningUnsorted)
{
    size_t sizeBefore = unsortedEdgeCases.size();
    myMergeSort(unsortedEdgeCases, 0, unsortedEdgeCases.size() - 1);
    ASSERT_EQ(unsortedEdgeCases.size(), sizeBefore);
    for(int i = 0; i < unsortedEdgeCases.size() - 1; i++)
    {
        ASSERT_LE(unsortedEdgeCases[i], unsortedEdgeCases[i + 1]);
    }
}

TEST_F(mergeSortTest, nonReturningSorted)
{
    size_t sizeBefore = ascendingEdgeCases.size();
    myMergeSort(ascendingEdgeCases, 0, ascendingEdgeCases.size() - 1);
    ASSERT_EQ(ascendingEdgeCases.size(), sizeBefore);
    for(int i = 0; i < ascendingEdgeCases.size() - 1; i++)
    {
        ASSERT_LE(ascendingEdgeCases[i], ascendingEdgeCases[i + 1]);
    }
}

TEST_F(mergeSortTest, nonReturningReverseSorted)
{
    size_t sizeBefore = descendingEdgeCases.size();
    myMergeSort(descendingEdgeCases, 0, descendingEdgeCases.size() - 1);
    ASSERT_EQ(descendingEdgeCases.size(), sizeBefore);
    for(int i = 0; i < descendingEdgeCases.size() - 1; i++)
    {
        ASSERT_LE(descendingEdgeCases[i], descendingEdgeCases[i + 1]);
    }
}

TEST_F(mergeSortTest, nonReturningRandomizedBig)
{
    size_t sizeBefore = randomizedBig.size();
    myMergeSort(randomizedBig, 0, randomizedBig.size() - 1);
    ASSERT_EQ(randomizedBig.size(), sizeBefore);
    for(int i = 0; i < randomizedBig.size() - 1; i++)
    {
        ASSERT_LE(randomizedBig[i], randomizedBig[i + 1]);
    }
}

TEST_F(mergeSortTest, nonReturningEmpty)
{
    myMergeSort(emptyVec, 0, emptyVec.size() - 1);
    ASSERT_TRUE(emptyVec.empty());
}

TEST_F(mergeSortTest, nonReturningSameData)
{
    size_t beforeSort = sameData.size();
    myMergeSort(sameData, 0, sameData.size() - 1);
    ASSERT_EQ(sameData.size(), beforeSort);
    for(int i = 0; i < sameData.size() - 1; i++)
    {
        ASSERT_LE(sameData[i], sameData[i + 1]);
    }
}

TEST(returningMerge, returningSmallData)
{
    std::vector<int> left = {1, 3, 5};
    std::vector<int> right = {2, 4, 6};
    std::vector<int> result;
    result = returningMerge(left, right);
    size_t sizeSum = left.size() + right.size();
    ASSERT_EQ(result.size(), sizeSum);
    for(int i = 0; i < result.size() - 1; i++)
    {
        ASSERT_LE(result[i], result[i + 1]);
    }
}

TEST(returningMerge, diffSizeSmallSorted)
{
    std::vector<int> left = {1, 3, 5};
    std::vector<int> right = {2, 4, 6, 16};
    std::vector<int> result;
    result = returningMerge(left,right);
    size_t sizeSum = left.size() + right.size();
    ASSERT_EQ(result.size(), sizeSum);
    for(int i = 0; i < result.size() - 1; i++)
    {
        ASSERT_LE(result[i], result[i + 1]);
    }
}

TEST(returningMerge, sameSizeSmallUnsorted)
{
    std::vector<int> left = {5, 3, 5};
    std::vector<int> right = {10, 5, 7};
    std::vector<int> result;
    result = returningMerge(left,right);
    size_t sizeSum = left.size() + right.size();
    ASSERT_EQ(result.size(), sizeSum);
}
TEST(returningMerge, diffSizeSmallUnsorted)
{
    std::vector<int> left = {5, 3, 5, -56};
    std::vector<int> right = {10, 5, 7};
    std::vector<int> result;
    result = returningMerge(left,right);
    size_t sizeSum = left.size() + right.size();
    ASSERT_EQ(result.size(), sizeSum);
}

TEST_F(mergeSortTest, returningSorted)
{
    std::vector<int> returned;
    returned = returningMyMergeSort(ascendingEdgeCases);
    ASSERT_EQ(returned.size(), ascendingEdgeCases.size());
    for(int i = 0; i < returned.size() - 1; i++)
    {
        ASSERT_LE(returned[i], returned[i + 1]);
    }
}

TEST_F(mergeSortTest, returningReverseSorted)
{
    std::vector<int> returned;
    returned = returningMyMergeSort(descendingEdgeCases);
    ASSERT_EQ(returned.size(), descendingEdgeCases.size());
    for(int i = 0; i < returned.size() - 1; i++)
    {
        ASSERT_LE(returned[i], returned[i + 1]);
    }
}

TEST_F(mergeSortTest, returningUnsorted)
{
    std::vector<int> returned;
    returned = returningMyMergeSort(unsortedEdgeCases);
    ASSERT_EQ(returned.size(), unsortedEdgeCases.size());
    for(int i = 0; i < returned.size() - 1; i++)
    {
        ASSERT_LE(returned[i], returned[i + 1]);
    }
}

TEST_F(mergeSortTest, returningRandomizedBig)
{
    std::vector<int> returned;
    returned = returningMyMergeSort(randomizedBig);
    ASSERT_EQ(returned.size(),  RANDOMIZEDVECTORSIZE);
    for(int i = 0; i < returned.size() - 1; i++)
    {
        ASSERT_LE(returned[i], returned[i + 1]);
    }
}