#ifndef BUCKET_SORTS_H
#define BUCKET_SORTS_H

#include <vector>
#include <string>

// =============================================================================
// CT14: Bucket Sort Algorithms (CCD 2.8.4)
// =============================================================================
//
// ? SEE DIAGRAM: images/svgs/bucket_sorts_overview.svg -- the three non-comparison sorts at a high level
// ? SEE DIAGRAM: images/svgs/bucket_sorts_comparison.svg -- side-by-side time, space, stability
//
// Non-comparison sorts that exploit properties of the data (integer keys,
// limited range) to sort faster than O(n log n).
//
// Design decisions:
//   - Free functions taking std::vector<int>& (modify in-place, no class needed)
//   - Ascending order (smallest first)
// =============================================================================

// ---------------------------------------------------------------------------
// Counting Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/svgs/counting_sort_complete.svg -- step-by-step on [4,2,7,1,4,2]
//
// ! DISCUSSION: How counting sort works.
//   - Count occurrences of each value in the input
//   - Use the counts to place elements directly into their sorted position
//   - Only works when the range of values (k) is known and reasonable
//
// ! DISCUSSION: Complexity and properties.
//   - Time: O(n + k) where k is the range of input values
//   - Space: O(k) for the count array
//   - Stable: Yes (with the standard implementation)
//   - Not a comparison sort -- never compares two elements directly
//
// TODO: Implement counting_sort
void counting_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Bucket Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/svgs/bucket_sort_complete.svg -- distributing into 3 buckets, sort, concatenate
//
// ! DISCUSSION: How bucket sort works.
//   - Distribute elements into a fixed number of "buckets" by value range
//   - Sort each bucket individually (often with insertion sort)
//   - Concatenate the sorted buckets back into the original array
//
// ! DISCUSSION: Complexity and properties.
//   - Time: O(n + k) average when data is uniformly distributed
//   - Worst case: O(n^2) if all elements land in one bucket
//   - Space: O(n + k) for the buckets
//   - Stable: Yes (if the per-bucket sort is stable)
//
// TODO: Implement bucket_sort
void bucket_sort(std::vector<int>& data, int num_buckets = 10);

// ---------------------------------------------------------------------------
// Radix Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/svgs/radix_sort_complete.svg -- digit-by-digit on [170,45,75,90,802,24,2,66]
//
// ! DISCUSSION: How radix sort works.
//   - Sort by each digit, starting from the least significant digit (LSD)
//   - Uses counting sort as a subroutine for each digit position
//   - After processing all digits, the array is fully sorted
//
// ! DISCUSSION: Complexity and properties.
//   - Time: O(d * (n + k)) where d = number of digits, k = base (10)
//   - Space: O(n + k)
//   - Stable: Yes (relies on stable counting sort at each digit)
//   - Works on non-negative integers
//
// TODO: Implement radix_sort
void radix_sort(std::vector<int>& data);

// Utility
void print_vector(const std::vector<int>& data, const std::string& label = "");

#endif // BUCKET_SORTS_H
