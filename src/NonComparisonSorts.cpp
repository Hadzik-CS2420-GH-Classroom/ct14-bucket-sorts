#include "NonComparisonSorts.h"
#include <iostream>
#include <algorithm>
#include <cmath>

// ---------------------------------------------------------------------------
// Counting Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: cpp_diagrams.md #1 -- Steps 1a, 1b, 1c (Count Phase)
// ? SEE DIAGRAM: cpp_diagrams.md #2 -- Step 2 (Placement Phase)
//
void counting_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;

    // Step 1a: Find min and max -- O(n)
    int min_val = *std::min_element(data.begin(), data.end());
    int max_val = *std::max_element(data.begin(), data.end());

    // Step 1b: Allocate count array of size k -- O(k)
    int k = max_val - min_val + 1;
    std::vector<int> count(k, 0);

    // Step 1c: Tally -- count[value - min]++ for each element -- O(n)
    for (int val : data) {
        count[val - min_val]++;
    }

    // Step 2: Place elements using counts -- O(n + k)
    int idx = 0;
    for (int i = 0; i < k; ++i) {
        while (count[i]-- > 0) {
            data[idx++] = i + min_val;
        }
    }
}

// ---------------------------------------------------------------------------
// Bucket Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: cpp_diagrams.md #3 -- Steps 1a, 1b (Distribution Phase)
// ? SEE DIAGRAM: cpp_diagrams.md #4 -- Steps 2-3 (Sort + Concatenate)
//
void bucket_sort(std::vector<int>& data, int num_buckets) {
    if (data.size() <= 1) return;

    // Step 1a: Find min and max, compute range per bucket
    int min_val = *std::min_element(data.begin(), data.end());
    int max_val = *std::max_element(data.begin(), data.end());

    if (min_val == max_val) return;  // all elements are the same

    int range = max_val - min_val + 1;
    int range_per_bucket = static_cast<int>(std::ceil(
        static_cast<double>(range) / num_buckets));

    // Step 1b: Distribute elements into buckets -- O(n)
    std::vector<std::vector<int>> buckets(num_buckets);
    for (int val : data) {
        int bucket_idx = (val - min_val) / range_per_bucket;
        // Clamp to last bucket in case of rounding
        if (bucket_idx >= num_buckets) bucket_idx = num_buckets - 1;
        buckets[bucket_idx].push_back(val);
    }

    // Step 2: Sort each bucket -- O(n^2/k) total with insertion sort
    // Using std::sort here (which uses introsort internally)
    int idx = 0;
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());

        // Step 3: Concatenate -- O(n)
        for (int val : bucket) {
            data[idx++] = val;
        }
    }
}

// ---------------------------------------------------------------------------
// Radix Sort (LSD)
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: cpp_diagrams.md #5 -- Step 0 + Pass 1 Detail
// ? SEE DIAGRAM: cpp_diagrams.md #6 -- Passes 2-3 (Stability in Action)
//
// Helper: counting sort by a specific digit position
static void counting_sort_by_digit(std::vector<int>& data, int exp) {
    int n = static_cast<int>(data.size());
    std::vector<int> output(n);
    int count[10] = {0};  // k = 10 (base 10, digits 0-9)

    // Count occurrences of each digit at position exp
    for (int i = 0; i < n; ++i) {
        int digit = (data[i] / exp) % 10;
        count[digit]++;
    }

    // Convert counts to cumulative positions (for stability)
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build output array (iterate backwards for stability)
    for (int i = n - 1; i >= 0; --i) {
        int digit = (data[i] / exp) % 10;
        output[count[digit] - 1] = data[i];
        count[digit]--;
    }

    // Copy back to data
    data = output;
}

void radix_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;

    // Step 0: Find max to determine number of digits (d)
    int max_val = *std::max_element(data.begin(), data.end());

    // Process each digit: ones (exp=1), tens (exp=10), hundreds (exp=100), ...
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort_by_digit(data, exp);
    }
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
