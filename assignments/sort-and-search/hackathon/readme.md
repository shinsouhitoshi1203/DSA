# [Sắp Xếp - Tìm Kiếm] Bài 56. 28Tech Hackathon  

## Mô tả bài toán  
28Tech định tổ chức một kỳ thi **Hackathon**, kỳ thi này sẽ gồm **N** cuộc thi nhỏ diễn ra lần lượt. Mỗi cuộc thi sẽ chứa một số lượng problem cụ thể, Hackathon sẽ diễn ra trong **H** giờ liên tiếp. Mỗi giờ bạn có thể quyết định mình sẽ giải được **K** problem.  

Nếu cuộc thi nào mà bạn đã giải hết các problem của cuộc thi đó thì bạn không thể dành thời gian thừa để làm các problem trong các cuộc thi khác.  

Nhiệm vụ của bạn là xác định giá trị nhỏ nhất của **K** để đảm bảo được mình sẽ hoàn thành tất cả problem trong các cuộc thi kịp thời gian.  

---

## Đầu vào  
- **Dòng 1**: Gồm hai số nguyên **N** và **H**.  
- **Dòng 2**: Gồm **N** số tương ứng với số lượng problem trong các cuộc thi nhỏ của Hackathon.  

---

## Giới hạn  
- $1 \leq N \leq 2 \cdot 10^5$  
- $H \leq 10^9$  
- Các problem trong các cuộc thi là số nguyên dương không vượt quá $10^6$.  

---  


## Đầu ra  
In ra giá trị nhỏ nhất của **K** tìm được.  

---

## Ví dụ  

### Input 01  
```
5 8  
5 5 4 2 2  
```

### Output 01  
```
3  
```

### Giải thích test:  
Các cuộc thi mất lần lượt 2, 2, 2, 1, 1 giờ để hoàn thành.  