# [Sắp Xếp - Tìm Kiếm] Bài 47: Factory Machine  

Một nhà máy có `n` máy có thể được sử dụng để tạo ra sản phẩm. Mục tiêu của bạn là tạo ra tổng số `t` sản phẩm. Đối với mỗi máy, bạn biết số giây nó cần để tạo ra một sản phẩm. Các máy có thể hoạt động đồng thời và bạn có thể tự do quyết định lịch trình của chúng.  

**Câu hỏi**: Thời gian ngắn nhất cần thiết để làm ra `t` sản phẩm là bao nhiêu?  
>! *(Gợi ý: Sử dụng Binary Search để tìm đáp án)* !<  

---

## Đầu vào  

- Dòng nhập đầu tiên có hai số nguyên `n` và `t`:  
    - `n`: Số lượng máy móc.  
    - `t`: Số sản phẩm cần tạo ra.  

- Dòng tiếp theo chứa `n` số nguyên `k1, k2, ..., kn`:  
    - `ki`: Thời gian cần thiết để tạo ra một sản phẩm sử dụng mỗi máy.  

---

## Đầu ra  

In một số nguyên: thời gian tối thiểu cần thiết để tạo ra `t` sản phẩm.  

---

## Ví dụ  

### Input 01  
```
3 7  
3 2 5  
```

### Output 01  
```
8  
```

---  


## Giới hạn  

- `1 ≤ n ≤ 2 * 10^5`  
- `1 ≤ t ≤ 10^9`  
- `1 ≤ ki ≤ 10^9`  

---  


**Gợi ý giải bài**

- >! Sử dụng thuật toán **Binary Search** trên khoảng thời gian để tìm đáp án tối ưu.   !<
- >!Tính số sản phẩm có thể tạo ra trong một khoảng thời gian cụ thể và điều chỉnh khoảng tìm kiếm dựa trên kết quả.!<

---  