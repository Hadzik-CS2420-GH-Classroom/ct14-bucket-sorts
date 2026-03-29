# CT14 -- Header Diagrams

Conceptual diagrams referenced from `BucketSorts.h`.

---

## 1. The Three Non-Comparison Sorts
*`BucketSorts.h` -- what counting sort, bucket sort, and radix sort are and how they work at a high level*

![The Three Non-Comparison Sorts](svgs/bucket_sorts_overview.svg)

---

## 2. What Is k? The Value Range
*`BucketSorts.h` -- k determines whether non-comparison sorts beat O(n log n). Small k = fast. Huge k = use quick sort instead.*

![What Is k? The Value Range](svgs/what_is_k.svg)

---

## 3. Counting Sort -- Complete Walkthrough
*`BucketSorts.h` -- step-by-step on [4, 2, 7, 1, 4, 2] showing count array and placement*

![Counting Sort -- Complete Walkthrough](svgs/counting_sort_complete.svg)

---

## 4. Bucket Sort -- Complete Walkthrough
*`BucketSorts.h` -- distributing [42, 15, 73, 28, 91, 5] into 3 buckets, sort each, concatenate*

![Bucket Sort -- Complete Walkthrough](svgs/bucket_sort_complete.svg)

---

## 5. Radix Sort (LSD) -- Complete Walkthrough
*`BucketSorts.h` -- sorting [170, 45, 75, 90, 802, 24, 2, 66] digit-by-digit with 3 passes*

![Radix Sort -- Complete Walkthrough](svgs/radix_sort_complete.svg)

---

## 6. Non-Comparison Sorts -- Side-by-Side Comparison
*`BucketSorts.h` -- time, space, stability, and best-use at a glance*

![Non-Comparison Sorts -- Side-by-Side Comparison](svgs/bucket_sorts_comparison.svg)
