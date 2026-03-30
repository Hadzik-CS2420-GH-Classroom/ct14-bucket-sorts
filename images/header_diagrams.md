# CT14 -- Header Diagrams

Conceptual diagrams referenced from `NonComparisonSorts.h`.

---

## 1. The Three Non-Comparison Sorts
*`NonComparisonSorts.h` -- what counting sort, bucket sort, and radix sort are and how they work at a high level*

![The Three Non-Comparison Sorts](svgs/bucket_sorts_overview.svg)

---

## 2. What Is k? The Value Range
*`NonComparisonSorts.h` -- k determines whether non-comparison sorts beat O(n log n). Small k = fast. Huge k = use quick sort instead.*

![What Is k? The Value Range](svgs/what_is_k.svg)

---

## 3. Counting Sort -- Complete Walkthrough
*`NonComparisonSorts.h` -- step-by-step on [14, 12, 17, 11, 14, 12] showing count array and placement (min=11, max=17, k=7)*

![Counting Sort -- Complete Walkthrough](svgs/counting_sort_complete.svg)

---

## 4. Bucket Sort -- Complete Walkthrough
*`NonComparisonSorts.h` -- distributing [42, 15, 73, 28, 91, 5] into 3 buckets, sort each, concatenate*

![Bucket Sort -- Complete Walkthrough](svgs/bucket_sort_complete.svg)

---

## 5. Radix Sort (LSD) -- Complete Walkthrough
*`NonComparisonSorts.h` -- sorting [170, 45, 75, 90, 802, 24, 2, 66] digit-by-digit with 3 passes*

![Radix Sort -- Complete Walkthrough](svgs/radix_sort_complete.svg)

---

## 6. Non-Comparison Sorts -- Side-by-Side Comparison
*`NonComparisonSorts.h` -- time, space, stability, and best-use at a glance*

![Non-Comparison Sorts -- Side-by-Side Comparison](svgs/bucket_sorts_comparison.svg)

---

## 7. When to Use Non-Comparison Sorts
*`NonComparisonSorts.h` -- integers only, good vs bad use cases, quick decision guide*

![When to Use Non-Comparison Sorts](svgs/when_to_use_noncomparison.svg)

---

## 8. All 9 Sorting Algorithms: When to Use Each
*All CTs -- comprehensive guide covering O(n^2), O(n log n), and O(n+k) sorts with best use cases and decision guide*

![All 9 Sorting Algorithms: When to Use Each](svgs/all_nine_sorts_guide.svg)
