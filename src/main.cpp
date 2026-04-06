// =============================================================================
// CT14: Non-Comparison Sorts -- Bypassing the O(n log n) Barrier
// =============================================================================
//
// Scenario: sort integer data using algorithms that never compare two elements.
// Instead, they use element values as indices to place data directly.
// This lets them break the O(n log n) comparison-sort lower bound.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "NonComparisonSorts.h"

int main() {
    std::cout << "=== CT14: Non-Comparison Sorts ===\n";
    std::cout << "=== Bypassing the O(n log n) Barrier ===\n\n";

    // -----------------------------------------------------------------------
    // 1. Counting Sort -- count occurrences, place directly
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Counting sort uses values as array indices.
    //   - find min and max to determine the range k = max - min + 1
    //   - allocate a count array of size k, tally each element
    //   - walk the count array left-to-right, writing values back
    //   - O(n + k) time, O(k) space -- fast when k is small relative to n
    //   - example: exam scores 0-100, k = 101 -- much smaller than n
    //
    std::cout << "--- Part 1: Counting Sort ---\n";
    std::vector<int> data1 = {4, 2, 7, 1, 9, 3, 5, 8, 2, 6};

    print_vector(data1, "  Unsorted");
    counting_sort(data1);
    print_vector(data1, "  Sorted  ");

    // -----------------------------------------------------------------------
    // 2. Counting Sort -- trace the count array
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Let's trace what the count array looks like.
    //   - input: [14, 12, 17, 11, 14, 12] -- exam scores (small range)
    //   - min = 11, max = 17, k = 7 (values 11..17)
    //   - count[0..6] maps to values 11..17
    //     count[0]=1 (11), count[1]=2 (12), count[2]=0 (13),
    //     count[3]=2 (14), count[4]=0 (15), count[5]=0 (16), count[6]=1 (17)
    //   - walk left-to-right: write 11 once, 12 twice, skip 13, 14 twice...
    //   - result: [11, 12, 12, 14, 14, 17]
    //
    std::cout << "\n--- Part 2: Counting Sort Trace ---\n";
    std::vector<int> data2 = {14, 12, 17, 11, 14, 12};

    print_vector(data2, "  Unsorted");

    // Show the count array before sorting
    int min_val = *std::min_element(data2.begin(), data2.end());
    int max_val = *std::max_element(data2.begin(), data2.end());
    int k = max_val - min_val + 1;
    std::cout << "  min=" << min_val << "  max=" << max_val
              << "  k=" << k << " (range " << min_val << ".." << max_val << ")\n";

    std::vector<int> count(k, 0);
    for (int val : data2) count[val - min_val]++;

    std::cout << "  count[]: ";
    for (int i = 0; i < k; ++i) {
        std::cout << count[i] << "(" << (i + min_val) << ") ";
    }
    std::cout << "\n";

    counting_sort(data2);
    print_vector(data2, "  Sorted  ");

    // -----------------------------------------------------------------------
    // 3. Bucket Sort -- distribute into buckets, sort each, concatenate
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Bucket sort divides the range into equal-width buckets.
    //   - compute range_per_bucket = ceil(range / num_buckets)
    //   - each element goes to bucket_idx = (value - min) / range_per_bucket
    //   - sort each bucket individually (std::sort or insertion sort)
    //   - concatenate all buckets in order
    //   - O(n + k) average when data is uniformly distributed
    //   - O(n^2) worst case: all elements land in one bucket
    //
    std::cout << "\n--- Part 3: Bucket Sort ---\n";
    std::vector<int> data3 = {42, 15, 73, 28, 91, 5, 64, 37, 50, 19};

    print_vector(data3, "  Unsorted");
    bucket_sort(data3);
    print_vector(data3, "  Sorted  ");

    // -----------------------------------------------------------------------
    // 4. Bucket Sort -- show bucket distribution
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: The distribution step is the key to bucket sort.
    //   - with 5 buckets and range 5..91 (range = 87):
    //     range_per_bucket = ceil(87 / 5) = 18
    //     bucket 0: values 5-22   → [15, 5, 19]
    //     bucket 1: values 23-40  → [28, 37]
    //     bucket 2: values 41-58  → [42, 50]
    //     bucket 3: values 59-76  → [73, 64]
    //     bucket 4: values 77-94  → [91]
    //   - sort each bucket, then read left-to-right
    //   - works great when elements spread evenly across buckets
    //
    std::cout << "\n--- Part 4: Bucket Sort Distribution (5 buckets) ---\n";
    std::vector<int> data4 = {42, 15, 73, 28, 91, 5, 64, 37, 50, 19};
    int num_buckets = 5;

    int bmin = *std::min_element(data4.begin(), data4.end());
    int bmax = *std::max_element(data4.begin(), data4.end());
    int range = bmax - bmin + 1;
    int rpb = static_cast<int>(std::ceil(static_cast<double>(range) / num_buckets));

    std::cout << "  range=" << bmin << ".." << bmax
              << "  range_per_bucket=" << rpb << "\n";

    std::vector<std::vector<int>> buckets(num_buckets);
    for (int val : data4) {
        int idx = (val - bmin) / rpb;
        if (idx >= num_buckets) idx = num_buckets - 1;
        buckets[idx].push_back(val);
    }

    for (int i = 0; i < num_buckets; ++i) {
        std::cout << "  bucket[" << i << "] ("
                  << (bmin + i * rpb) << "-" << (bmin + (i + 1) * rpb - 1) << "): [";
        for (size_t j = 0; j < buckets[i].size(); ++j) {
            if (j > 0) std::cout << ", ";
            std::cout << buckets[i][j];
        }
        std::cout << "]\n";
    }

    bucket_sort(data4, num_buckets);
    print_vector(data4, "  Sorted  ");

    // -----------------------------------------------------------------------
    // 5. Radix Sort -- sort digit-by-digit using counting sort
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Radix sort processes one digit at a time (LSD → MSD).
    //   - LSD = Least Significant Digit: start from ones, then tens, hundreds
    //   - each pass uses a STABLE counting sort on just that digit
    //   - stability is critical: each pass must preserve the order from prior passes
    //   - after d passes (one per digit), the array is fully sorted
    //   - O(d * (n + k)) where d = digits in max, k = 10 (base 10)
    //
    std::cout << "\n--- Part 5: Radix Sort ---\n";
    std::vector<int> data5 = {170, 45, 75, 90, 802, 24, 2, 66};

    print_vector(data5, "  Unsorted");
    radix_sort(data5);
    print_vector(data5, "  Sorted  ");

    // -----------------------------------------------------------------------
    // 6. Radix Sort -- trace counting_sort_by_digit (Pass 1: ones)
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: This is the most complex part -- let's trace one pass.
    //   - counting_sort_by_digit is NOT the same as regular counting sort
    //   - regular counting sort: count values, write them back directly
    //   - counting_sort_by_digit: count DIGITS, use cumulative counts to
    //     PLACE WHOLE ELEMENTS into an output array
    //   - the cumulative count trick tells us: "elements with digit d go at
    //     positions count[d-1] through count[d]-1"
    //   - iterating BACKWARDS preserves stability (equal-digit elements
    //     keep their prior-pass ordering)
    //
    // ? SEE DIAGRAM: cpp_diagrams.md #5 -- Step 0 + Pass 1 Detail
    // ? SEE DIAGRAM: images/svgs/radix_counting_by_digit.svg -- the 4-step process
    //
    std::cout << "\n--- Part 6: Trace counting_sort_by_digit ---\n";
    std::vector<int> trace = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = static_cast<int>(trace.size());
    int exp = 1;  // ones digit

    std::cout << "  Pass 1 (exp=" << exp << "): sort by ones digit\n";
    print_vector(trace, "  Input   ");

    // Step 1: Extract digit for each element
    //
    // ! DISCUSSION: The digit extraction formula is (value / exp) % 10.
    //   - exp=1: ones digit     170/1 % 10 = 0
    //   - exp=10: tens digit    170/10 % 10 = 7
    //   - exp=100: hundreds     170/100 % 10 = 1
    //   - integer division truncates, then % 10 isolates one digit
    //
    std::cout << "  Step 1 -- extract digits: ";
    for (int i = 0; i < n; ++i) {
        int digit = (trace[i] / exp) % 10;
        std::cout << trace[i] << "→" << digit;
        if (i < n - 1) std::cout << "  ";
    }
    std::cout << "\n";

    // Step 2: Build count array (tally each digit)
    int tally[10] = {0};
    for (int i = 0; i < n; ++i) {
        tally[(trace[i] / exp) % 10]++;
    }

    std::cout << "  Step 2 -- count[]:      ";
    for (int i = 0; i < 10; ++i) {
        if (tally[i] > 0) std::cout << "[" << i << "]=" << tally[i] << " ";
    }
    std::cout << "\n";

    // Step 3: Convert to cumulative counts
    //
    // ! DISCUSSION: Cumulative counts tell us WHERE to place elements.
    //   - count[d] = number of elements with digit <= d
    //   - so count[d] - 1 is the LAST index where digit d should go
    //   - after placing one element, decrement count[d] to get the next slot
    //   - this is the key trick: we know exact positions without comparing
    //
    for (int i = 1; i < 10; ++i) {
        tally[i] += tally[i - 1];
    }

    std::cout << "  Step 3 -- cumulative[]: ";
    for (int i = 0; i < 10; ++i) {
        if (tally[i] > 0) std::cout << "[" << i << "]=" << tally[i] << " ";
    }
    std::cout << "\n";

    // Step 4: Place elements backwards into output
    //
    // ! DISCUSSION: Iterating BACKWARDS is what makes this STABLE.
    //   - when two elements have the same digit (e.g., 170 and 90 both have
    //     ones digit 0), the one that appeared LATER in the input should go
    //     to the LATER output position
    //   - by going backwards, we place 90 first (at the higher index),
    //     then 170 (at the lower index) -- preserving their input order
    //   - if we iterated forwards, 170 would go to the higher index and
    //     90 to the lower -- reversing their order (unstable!)
    //   - stability matters because future passes depend on prior ordering
    //
    std::vector<int> output(n);
    // Reset cumulative for the trace
    int cum[10] = {0};
    for (int i = 0; i < n; ++i) cum[(trace[i] / exp) % 10]++;
    for (int i = 1; i < 10; ++i) cum[i] += cum[i - 1];

    std::cout << "  Step 4 -- place backwards:\n";
    for (int i = n - 1; i >= 0; --i) {
        int digit = (trace[i] / exp) % 10;
        int pos = cum[digit] - 1;
        output[pos] = trace[i];
        cum[digit]--;
        std::cout << "    i=" << i << "  value=" << trace[i]
                  << "  digit=" << digit << "  → output[" << pos << "]\n";
    }
    print_vector(output, "  Result  ");

    // -----------------------------------------------------------------------
    // 7. Radix Sort -- show all three passes
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Watch how stability builds the final sorted order.
    //   - Pass 1 (ones): elements sorted by ones digit only
    //   - Pass 2 (tens): sorted by tens digit, but ones order is PRESERVED
    //   - Pass 3 (hundreds): sorted by hundreds, tens+ones order PRESERVED
    //   - after the last pass, ALL digit positions are sorted → fully sorted
    //
    // ? SEE DIAGRAM: cpp_diagrams.md #6 -- Passes 2-3 (Stability in Action)
    //
    std::cout << "\n--- Part 7: All Three Passes ---\n";
    std::vector<int> data7 = {170, 45, 75, 90, 802, 24, 2, 66};
    print_vector(data7, "  Original");

    int max7 = *std::max_element(data7.begin(), data7.end());
    std::cout << "  max=" << max7 << " → d=3 passes (ones, tens, hundreds)\n\n";

    // Manually run each pass to show intermediate state
    // We'll re-implement the digit sort inline to show each step
    for (int e = 1; max7 / e > 0; e *= 10) {
        std::string digit_name;
        if (e == 1) digit_name = "ones";
        else if (e == 10) digit_name = "tens";
        else if (e == 100) digit_name = "hundreds";
        else digit_name = "exp=" + std::to_string(e);

        // Run one pass of counting sort by digit
        int sz = static_cast<int>(data7.size());
        std::vector<int> out(sz);
        int c[10] = {0};

        for (int i = 0; i < sz; ++i) c[(data7[i] / e) % 10]++;
        for (int i = 1; i < 10; ++i) c[i] += c[i - 1];
        for (int i = sz - 1; i >= 0; --i) {
            int d = (data7[i] / e) % 10;
            out[c[d] - 1] = data7[i];
            c[d]--;
        }
        data7 = out;

        std::cout << "  Pass (exp=" << e << ", " << digit_name << "): ";
        print_vector(data7, "");
    }

    // -----------------------------------------------------------------------
    // 8. Why not comparison sort? The O(n log n) lower bound
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Comparison sorts CANNOT beat O(n log n). Here's why:
    //   - every comparison has 2 outcomes (yes/no), forming a binary tree
    //   - n! possible orderings → the tree needs at least log2(n!) leaves
    //   - by Stirling's approximation, log2(n!) ≈ n log n
    //   - so any comparison sort must make at least n log n comparisons
    //   - non-comparison sorts bypass this by using values as indices
    //   - the tradeoff: they only work on integers with a bounded range
    //
    std::cout << "\n--- Part 8: When to Use Non-Comparison Sorts ---\n";
    std::cout << "  Use when:    integer data, small known range (k << n)\n";
    std::cout << "  Examples:    exam scores (0-100), ages (0-150), zip codes\n";
    std::cout << "  Don't use:   strings, floats, huge/unknown range\n";
    std::cout << "  Tradeoff:    faster time, but more space (O(n+k))\n";

    // -----------------------------------------------------------------------
    // 9. Summary
    // -----------------------------------------------------------------------
    std::cout << "\n--- Summary ---\n";
    std::cout << "  Algorithm      | Time         | Space  | Stable? | Key idea\n";
    std::cout << "  ---------------|--------------|--------|---------|-------------------------\n";
    std::cout << "  Counting Sort  | O(n + k)     | O(k)   | Yes     | Count values, place directly\n";
    std::cout << "  Bucket Sort    | O(n+k) / n^2 | O(n+k) | Depends | Distribute, sort, concat\n";
    std::cout << "  Radix Sort     | O(d(n + k))  | O(n+k) | Yes     | Digit-by-digit counting sort\n";
    std::cout << "\n  k = value range, d = number of digits.\n";
    std::cout << "  All three bypass the O(n log n) lower bound for comparison sorts.\n";

    std::cout << "\n=== CT14 Complete ===\n";
    return 0;
}
