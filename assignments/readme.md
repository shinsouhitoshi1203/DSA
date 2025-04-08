shinsouhitoshi1203
# Sắp xếp và tìm kiếm
## Keys

1. In actual practice, we use STL's utilities, ie. `sort`, `upper_bound` for better performance.

2. The most important and common sort algorithms are:
`mergesort` , `quicksort` and `heapsort` with an average time complexity of $O(nlogn)$

3. There are two main search algorithm: `sequential.search` and `binary.search`

    a. `sequential.search` is `bruth-force`, which takes $O(n)$ time complexity to proceed.

    b. `binary.search` is `divide.conquer`, which takes $O(logn)$ time complexity

    > `binary.search` is only for sorted arrays

## Logic of binary search

This logic can be used for `binary.search > answer`

1. Find the identify for searching, such that $[min, max] \rightarrow Ans$

2. Find the search scope

3. Build a related functions for conditions. Check if match the conditions or not to move the `s` and `e`

## Time complexity comparision

<img src="https://baadamsecurity.com/wp-content/uploads/2024/10/Logarithmic-time-complexity-blog-1.jpg" />


## Danh sách bài tập sắp xếp và tìm kiếm

| tên bài tập | dạng bài tập |
| ----------- | ------------ |
| `choptree` | >!tìm kiếm trên ans!< |
| `factory` | >!tìm kiếm trên ans!< |
| `hackathon` | >!tìm kiếm trên ans!< |
| `pair_k` | >!tìm kiếm!< |
| `schedule` | >!sắp xếp!< |