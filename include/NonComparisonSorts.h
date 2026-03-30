#pragma once

#include <vector>
#include <string>

// =============================================================================
// CT14: Non-Comparison Sorts (CCD 2.8.4)
// =============================================================================
//
// ? SEE DIAGRAM: header_diagrams.md #1 -- the three non-comparison sorts overview
// ? SEE DIAGRAM: header_diagrams.md #2 -- what is k? the value range tradeoff
// ? SEE DIAGRAM: header_diagrams.md #7 -- when to use non-comparison sorts (integers only)
//
// Non-comparison sorts exploit integer key properties (value range, digit
// structure) to sort faster than O(n log n). They never compare two elements
// directly -- instead they use values as indices.
//
// Design: free functions taking std::vector<int>& (ascending order, in-place).
// =============================================================================

// ---------------------------------------------------------------------------
// Counting Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: header_diagrams.md #3 -- complete walkthrough on [14,12,17,11,14,12]
//
// Count occurrences of each value, then place directly.
// Time: O(n + k) where k = value range (max - min + 1)
// Space: O(k) for the count array
// Stable: Yes
//
void counting_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Bucket Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: header_diagrams.md #4 -- complete walkthrough on [42,15,73,28,91,5]
//
// Distribute into range-based buckets, sort each bucket, concatenate.
// Time: O(n + k) avg, O(n^2) worst (all in one bucket)
// Space: O(n + k)
// Stable: depends on per-bucket sort (stable if using insertion sort)
//
void bucket_sort(std::vector<int>& data, int num_buckets = 10);

// ---------------------------------------------------------------------------
// Radix Sort (LSD)
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: header_diagrams.md #5 -- digit-by-digit on [170,45,75,90,802,24,2,66]
//
// Sort digit-by-digit from least significant to most, using stable
// counting sort at each digit position.
// Time: O(d * (n + k)) where d = max digits, k = base (10)
// Space: O(n + k)
// Stable: Yes (requires stable sub-sort at each digit)
//
void radix_sort(std::vector<int>& data);


// ? SEE DIAGRAM: header_diagrams.md #6 -- side-by-side comparison table


// Utility
void print_vector(const std::vector<int>& data, const std::string& label = "");

