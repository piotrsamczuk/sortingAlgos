#include <gtest/gtest.h>
#include "../sortingAlgos.hpp"
#include <random>
#include <limits.h>

// struct sortTest: public ::testing::Test
// {
//     virtual void SetUp() override
//     {

//     }

//     virtual void TearDown() override
//     {

//     }

//     std::vector<int> randomizedVector(int n = 10000)
//     {
//         std::vector<int> vec(n);
//         std::minstd_rand engine;
//         std::uniform_int_distribution<> dist(INT_MIN, INT_MAX);
//         for(int i = 0; i < n; i++)
//         {
//             vec[i] = dist(engine);
//         }
//         return vec;
//     }

//     const std::vector<int> unsortedEdgeCases = {4, 1, INT_MAX, 3, 2, 7, 16, INT_MIN, 9, -55, 10, 14, 8};
//     const std::vector<int> ascendingEdgeCases = {INT_MIN, -55, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16, INT_MAX};
//     const std::vector<int> descendingEdgeCases = {INT_MAX, 16, 14, 10, 9, 8, 7, 4, 3, 2, 1, -55, INT_MIN};
//     const std::vector<int> randomizedBig = randomizedVector(1000000);
// };

void intFill(std::vector<int>& src)
{
    std::minstd_rand engine;
    std::uniform_int_distribution<> dist(INT_MIN, INT_MAX);
    for(auto& i : src)
    {
        i = dist(engine);
    }
}

TEST(myMergeSort, unsortedSmallEdgeCases)
{
    std::vector<int> vec = {4, 1, INT_MAX, 3, 2, 7, 16, INT_MIN, 9, -55, 10, 14, 8};
    size_t sizeBefore = vec.size();
    myMergeSort(vec, 0, vec.size() - 1);
    ASSERT_EQ(vec.size(), sizeBefore);
    for(int i = 0; i < vec.size() - 1; i++)
    {
        ASSERT_LE(vec[i], vec[i + 1]);
    }
}

TEST(myMergeSort, sortedSmallEdgeCases)
{
    std::vector<int> vec = {INT_MIN, -55, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16, INT_MAX};
    size_t sizeBefore = vec.size();
    myMergeSort(vec, 0, vec.size() - 1);
    ASSERT_EQ(vec.size(), sizeBefore);
    for(int i = 0; i < vec.size() - 1; i++)
    {
        ASSERT_LE(vec[i], vec[i + 1]);
    }
}

TEST(myMergeSort, reverseSortedSmallEdgeCases)
{
    std::vector<int> vec = {INT_MAX, 16, 14, 10, 9, 8, 7, 4, 3, 2, 1, -55, INT_MIN };
    size_t sizeBefore = vec.size();
    myMergeSort(vec, 0, vec.size() - 1);
    ASSERT_EQ(vec.size(), sizeBefore);
    for(int i = 0; i < vec.size() - 1; i++)
    {
        ASSERT_LE(vec[i], vec[i + 1]);
    }
}

TEST(myMergeSort, randomizedBig)
{
    std::vector<int> vec(10000);
    intFill(vec);
    size_t sizeBefore = vec.size();
    myMergeSort(vec, 0, vec.size() - 1);
    ASSERT_EQ(vec.size(), sizeBefore);
    for(int i = 0; i < vec.size() - 1; i++)
    {
        ASSERT_LE(vec[i], vec[i + 1]);
    }
}

TEST(myMergeSort, empty)
{
    std::vector<int> emptyvec = {};

    myMergeSort(emptyvec, 0, emptyvec.size() - 1);
    ASSERT_TRUE(emptyvec.empty());
}

TEST(myMergeSort, identicalDataSmall)
{
    std::vector<int> data(50, 0);
    size_t beforeSort = data.size();
    myMergeSort(data, 0, data.size() - 1);
    ASSERT_EQ(data.size(), beforeSort);
    for(int i = 0; i < data.size() - 1; i++)
    {
        ASSERT_LE(data[i], data[i + 1]);
    }
}

TEST(returningMerge, sameSizeSmallSorted)
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

TEST(returningSimpleMyMergeSort, sortedEdgeCases)
{
    std::vector<int> sorted = {INT_MIN, -55, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16, INT_MAX};

    std::vector<int> returned;
    returned = returningMyMergeSort(sorted);
    ASSERT_EQ(returned.size(), sorted.size());
    for(int i = 0; i < returned.size() - 1; i++)
    {
        ASSERT_LE(returned[i], returned[i + 1]);
    }
}

TEST(returningSimpleMyMergeSort, reverseSortedSmallEdgeCases)
{
    std::vector<int> reverseSorted = {INT_MAX, 16, 14, 10, 9, 8, 7, 4, 3, 2, 1, -55, INT_MIN };
    std::vector<int> sorted = {INT_MIN, -55, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16, INT_MAX};

    std::vector<int> returned;
    returned = returningMyMergeSort(reverseSorted);
    ASSERT_EQ(returned.size(), reverseSorted.size());
    ASSERT_EQ(returned.size(), sorted.size());
    for(int i = 0; i < returned.size() - 1; i++)
    {
        ASSERT_LE(returned[i], returned[i + 1]);
    }
}

TEST(returningSimpleMyMergeSort, unsortedSmallEdgeCases)
{
    std::vector<int> unsorted = {4, 1, INT_MAX, 3, 2, 7, 16, INT_MIN, 9, -55, 10, 14, 8};
    std::vector<int> sorted = {INT_MIN, -55, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16, INT_MAX};

    std::vector<int> returned;
    returned = returningMyMergeSort(unsorted);
    ASSERT_EQ(returned.size(), unsorted.size());
    ASSERT_EQ(returned.size(), sorted.size());
    for(int i = 0; i < returned.size() - 1; i++)
    {
        ASSERT_LE(returned[i], returned[i + 1]);
    }
}