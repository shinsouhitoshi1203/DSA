# [Sắp Xếp - Tìm Kiếm] Bài 18. Cặp số có tổng lớn hơn K

## Đề bài
Cho mảng `a` gồm `n` phần tử và số nguyên dương `k`. Đếm số lượng cặp số `a[i], a[j]` (i ≠ j) có tổng lớn hơn `k`.

---

## Đầu vào
- Dòng thứ 1 là số lượng phần tử trong mảng `n` và số nguyên dương `k`.
- Dòng thứ 2 là `n` phần tử trong mảng.

## Đầu ra
- Một số nguyên là số lượng cặp số `a[i], a[j]` (i ≠ j) có tổng lớn hơn `k`.

### Ví dụ
#### Input:
```
5 9
2 7 4 5 3
```
#### Output:
```
3
```

#### Giải thích:
- Các cặp số có tổng lớn hơn `9` là `(4, 7)`   `(5, 7)` và `(3, 7)`.

---

## Giới hạn
- `2 <= n <= 10^6`
- `1 <= k <= 10^6`
- `0 <= a[i] <= 10^6`

---
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
## Gợi ý:
- Sắp xếp mảng tăng dần sau đó với mỗi phần tử `a[i]` trong mảng, tìm xem trong đoạn `[i + 1, n - 1]` có bao nhiêu phần tử có giá trị lớn hơn `k - a[i]`.
- Bằng cách tìm vị trí đầu tiên của phần tử lớn hơn `k - a[i]` => Số lượng.