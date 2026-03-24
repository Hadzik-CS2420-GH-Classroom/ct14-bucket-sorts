#include "BucketSorts.h"
#include <iostream>
#include <algorithm>

// ---------------------------------------------------------------------------
// Counting Sort
// ---------------------------------------------------------------------------
void counting_sort(std::vector<int>& data) {
    // TODO: Implement counting sort
    //   1. Find the min and max values
    //   2. Create a count array of size (max - min + 1)
    //   3. Count occurrences of each value
    //   4. Overwrite data with sorted values using the counts
}

// ---------------------------------------------------------------------------
// Bucket Sort
// ---------------------------------------------------------------------------
void bucket_sort(std::vector<int>& data, int num_buckets) {
    // TODO: Implement bucket sort
    //   1. Find the min and max values to determine bucket ranges
    //   2. Create num_buckets empty buckets (vectors)
    //   3. Distribute each element into its bucket
    //   4. Sort each bucket (use insertion sort or std::sort)
    //   5. Concatenate all buckets back into data
}

// ---------------------------------------------------------------------------
// Radix Sort
// ---------------------------------------------------------------------------
void radix_sort(std::vector<int>& data) {
    // TODO: Implement radix sort (LSD)
    //   1. Find the maximum value to determine the number of digits
    //   2. For each digit position (ones, tens, hundreds, ...):
    //      a. Use counting sort on that digit
    //   3. After all digit passes, data is sorted
}

// ---------------------------------------------------------------------------
// Utility
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label) {
    if (!label.empty()) std::cout << label << ": ";
    std::cout << "[";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i + 1 < data.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
