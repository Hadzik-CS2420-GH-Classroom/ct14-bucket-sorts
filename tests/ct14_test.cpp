#include <gtest/gtest.h>
#include "NonComparisonSorts.h"
#include <vector>
#include <algorithm>

// ==================== Counting Sort ====================

TEST(CountingSortTest, BasicSort) {
    std::vector<int> data = {4, 2, 7, 1, 9, 3};
    counting_sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 7, 9}));
}

TEST(CountingSortTest, AlreadySorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    counting_sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(CountingSortTest, ReverseSorted) {
    std::vector<int> data = {5, 4, 3, 2, 1};
    counting_sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(CountingSortTest, Duplicates) {
    std::vector<int> data = {3, 1, 2, 3, 1, 2};
    counting_sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 1, 2, 2, 3, 3}));
}

TEST(CountingSortTest, SingleElement) {
    std::vector<int> data = {42};
    counting_sort(data);
    EXPECT_EQ(data, (std::vector<int>{42}));
}

TEST(CountingSortTest, EmptyVector) {
    std::vector<int> data = {};
    counting_sort(data);
    EXPECT_TRUE(data.empty());
}

// ==================== Bucket Sort ====================

TEST(BucketSortTest, BasicSort) {
    std::vector<int> data = {42, 15, 73, 28, 91, 5};
    bucket_sort(data);
    EXPECT_EQ(data, (std::vector<int>{5, 15, 28, 42, 73, 91}));
}

TEST(BucketSortTest, AlreadySorted) {
    std::vector<int> data = {10, 20, 30, 40, 50};
    bucket_sort(data);
    EXPECT_EQ(data, (std::vector<int>{10, 20, 30, 40, 50}));
}

TEST(BucketSortTest, Duplicates) {
    std::vector<int> data = {30, 10, 20, 30, 10};
    bucket_sort(data);
    EXPECT_EQ(data, (std::vector<int>{10, 10, 20, 30, 30}));
}

TEST(BucketSortTest, SingleElement) {
    std::vector<int> data = {7};
    bucket_sort(data);
    EXPECT_EQ(data, (std::vector<int>{7}));
}

TEST(BucketSortTest, EmptyVector) {
    std::vector<int> data = {};
    bucket_sort(data);
    EXPECT_TRUE(data.empty());
}

// ==================== Radix Sort ====================

TEST(RadixSortTest, BasicSort) {
    std::vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};
    radix_sort(data);
    EXPECT_EQ(data, (std::vector<int>{2, 24, 45, 66, 75, 90, 170, 802}));
}

TEST(RadixSortTest, AlreadySorted) {
    std::vector<int> data = {1, 10, 100, 1000};
    radix_sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 10, 100, 1000}));
}

TEST(RadixSortTest, SingleDigits) {
    std::vector<int> data = {9, 3, 7, 1, 5};
    radix_sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 3, 5, 7, 9}));
}

TEST(RadixSortTest, Duplicates) {
    std::vector<int> data = {55, 22, 55, 11, 22};
    radix_sort(data);
    EXPECT_EQ(data, (std::vector<int>{11, 22, 22, 55, 55}));
}

TEST(RadixSortTest, SingleElement) {
    std::vector<int> data = {42};
    radix_sort(data);
    EXPECT_EQ(data, (std::vector<int>{42}));
}

TEST(RadixSortTest, EmptyVector) {
    std::vector<int> data = {};
    radix_sort(data);
    EXPECT_TRUE(data.empty());
}
