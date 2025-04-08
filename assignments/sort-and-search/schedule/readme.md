
# [Sắp Xếp - Tìm Kiếm]. Bài 16. Xếp lịch diễn

Ca sĩ nổi tiếng Lệ Rơi vừa nhận được các lời mời lưu diễn của các đoàn ca nhạc. Đoàn thứ i mời lưu diễn từ ngày `a[i]` đến ngày `b[i]` (`a[i], b[i]` là các số nguyên, `a[i] ≤ b[i]`). Tuy nhiên tại một thời điểm, Lệ Rơi chỉ có thể tham gia hát cho một đoàn duy nhất mà thôi. Với mong muốn đem lời ca tiếng hát của mình đến nhiều khán giả nhất, Lệ Rơi quyết định sẽ chọn tham gia nhiều đoàn lưu diễn nhất có thể. Bạn hãy tính thử xem Lệ Rơi nên chọn tham gia những đoàn nào để số lượng đoàn là nhiều nhất mà không bị trùng nhau về mặt thời gian.

---

## Đầu vào

- Dòng thứ nhất là số nguyên `n` là số đoàn ca nhạc.
- Trong `n` dòng tiếp theo, dòng thứ i gồm hai số `a[i], b[i]` cách nhau một khoảng trắng là ngày bắt đầu và ngày kết thúc lưu diễn của đoàn thứ i.

---

## Giới hạn

- `1 ≤ n ≤ 10^5`
- `1 ≤ a[i] ≤ b[i] ≤ 10^6`

---

## Đầu ra

- Số nguyên xác định số lượng đoàn nhiều nhất mà Lệ Rơi có thể tham gia.

---

## Ví dụ

### Input 01
```
6
3 8
9 12
6 10
1 4
2 7
11 14
```

### Output 01
```
3
```