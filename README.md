# CT14: Bucket Sort Algorithms

## Overview

Non-comparison sorting algorithms that exploit properties of the data to sort faster than O(n log n). Covers counting sort, bucket sort, and radix sort — the "bucket sort" family required by CCD 2.8.4.

## Learning Objectives

- Understand why non-comparison sorts can beat O(n log n)
- Implement counting sort using a frequency array
- Implement bucket sort with range-based distribution
- Implement radix sort using counting sort as a subroutine
- Analyze Big O speed, space, and when each is appropriate

## Project Structure

```
ct14-bucket-sorts/
  include/
    BucketSorts.h        <- function declarations + discussion comments
  src/
    BucketSorts.cpp      <- TODO implementations
    main.cpp             <- demo driver
  tests/
    ct14_test.cpp        <- Google Test suite
  CMakeLists.txt
```

## Files

### `BucketSorts.cpp` — 3 TODOs

1. `counting_sort` — count occurrences, place directly
2. `bucket_sort` — distribute into buckets, sort each, concatenate
3. `radix_sort` — sort by each digit using counting sort
