# Bài tập nâng cao

Cho n đồ vật khác nhau, đồ vật thứ i có trọng lượng w; và giá trị vị. Bạn mang theo một chiếc túi có tải trọng tối đa là W, nhiệm vụ của bạn là chọn ra các đồ vật để cho vào túi sao cho tổng giá trị của các đồ vật lấy được là lớn nhất có thể?

_Input:_

-   Dòng đầu tiên chứa hai số nguyên dương n và W.
-   n dòng tiếp theo, mỗi dòng chứa hai số nguyên dương wi và vi phân tách nhau bởi dấu cách.

_Output:_

-   Dòng đầu tiên in ra tổng giá trị lớn nhất của các vật lấy được.
-   Dòng thứ hai in ra chỉ số của các vật được lựa chọn theo thứ tự tăng dần.

**Các tệp được yêu cầu**

-   _File Header.h_

```
//Nhap cac mon do
void enter(int &n, int &W, vector < pair < int, int > > items);
//dat co cac mon do da thu qua
void trace_back(int n, int W, vector < vector < int > > &dp, vector < pair < int, int > > &items);
//Giai phap tim cac mon do toi uu
void solution(int n, int W, vector < pair < int, int > > &items);
```

-   _File Source.cpp_

```
//Include Header và trien khai cac methods dc khai bao

```
