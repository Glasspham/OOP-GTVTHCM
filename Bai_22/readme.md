Xây dựng chương trình đố vui cho trẻ em với các câu hỏi là các biểu thức số học có dạng a # b = ?, với a, b là các số nguyên, và # là phép toán số học {+, -, \*}. Ví dụ: 2 + 5 = ?. Chương trình sẽ sinh ra các biểu thức ngẫu nhiên (ngẫu nhiên về phép toán và giá trị a,b) và người chơi sẽ nhập câu trả lời là giá trị đúng của biểu thức. Cấp độ khó của câu hỏi sẽ được tăng 1 nếu người chơi đúng liên tiếp n câu hỏi (ví dụ n = 3), ngược lại nếu sai một câu thì cấp độ khó sẽ giảm 1. Cấp độ khó của câu hỏi xác định theo qui luật:

-Level 1: chỉ có phép toán cộng, a, b <= 10

-Level 2: có phép toán + và - , a,b <= 10

-Level 3: có phép toán + , - ,và \* , a,b <= 10

-Level 4: có phép toán + và - , a,b <= 100

-Level 5+: có phép toán + , - và \* , a,b <= 100

a. Cài đặt lớp Bieuthuc với mô tả lớp như sau:

_File Bieuthuc.h_

```bash
class Bieuthuc {
protected:
    int a, b; // hai toán hạng
    char pheptoan; // ký tự đại diện phép toán {+, -, \*}
public:
    Bieuthuc(int level); // sinh ngẫu nhiên biểu thức theo quy luật
    friend ostream& operator << (ostream& out, Bieuthuc bt); // xuất ra theo dạng a # b
    bool kiemtra(float traloi); // nhận câu trả lời và kiểm tra xem giá trị biểu thức có trùng câu trả lời không
    float giatri(); // tính giá trị biểu thức
};
```

_File Bieuthuc.cpp_

```bash
#include "Bieuthuc.h"
```

b. Thiết kế chương trình chính cho phép sinh ngẫu nhiên các câu hỏi, hiển thị cấp độ khó, và số điểm hiện tại của người chơi.

c. Cài đặt lớp BieuthucCong, BieuthucTru, BieuthucNhan kế thừa từ lớp Bieuthuc để chỉ sinh ngẫu nhiên các biểu thức với phép toán +, - , \*.

d. Xây dựng lớp đề thi với các thành viên như sau:

_File Dethi.h_

```bash
class Dethi {
private:
    vector<Bieuthuc> ds; // Chứa danh sách các câu hỏi là các biểu thức
public:
    Dethi(int n1, int n2, int n3, int level=1); // Sinh danh sách gồm n1 biểu thức chỉ gồm phép cộng,
                                                // n2 biểu thức chỉ gồm phép trừ, và
                                                // n3 biểu thức chỉ gồm phép nhân.
    vector<Bieuthuc> danhsach() { return ds; }
    void xuat(ostream& output=cout); // xuất danh sách các câu hỏi ra màn hình, các câu hỏi có dạng a # b = ?
    int danhgia(istream& input=cin); // đọc n1 + n2 + n3 câu trả lời từ istream (có thể từ cin hoặc file), trả về số câu đúng.
};
```

_File Dethi.cpp_

```bash
#include "Dethi.h"
```

e. Xây dựng các lớp biểu thức phức tạp hơn, ví dụ (a _ a + b _ b) hay (a # b) \* (a # b), để tăng cấp độ khó cho trò chơi. _Lưu ý:_ có thể có nhiều phương án cài đặt, nên chọn phương án dùng lại code nhiều nhất có thể

_File BieuthucPT.h_

```bash
#pragma once
#include "Bieuthuc.h"
#include <iostream>
using namespace std;
class BieuthucPT : public Bieuthuc {
private:
     //..Bổ sung thêm dữ liệu để lưu trữ được (a#b) # (c#d)
public:
    BieuthucPT(int level);                                    // overide để sinh ngẫu nhiên được dạng biểu thức mới, quy luật sinh như sinh lớp Bieuthuc
    friend ostream& operator << (ostream& out, BieuthucPT bt);// overide để xuất dạng biểu thức mới
    bool kiemtra(float traloi);                               // overide...
    float giatri();                                           // overide...
};
```

_File BieuthucPT.cpp_

```bash
#include "BieuthucPT.h"
```

f. Kết hợp với lớp Phân số (class Fraction) đã làm trong buổi thực hành trước để xây dựng lớp BieuthucPhanSo, tăng thêm cấp độ khó cho trò chơi. _Lưu ý:_ Tận dụng code đã viết càng nhiều càng tốt

_File BieuthucPS.h_

```bash
#pragma once
#include "Bieuthuc.h"
#include "Fraction.h"

class BieuthucPS : public Bieuthuc {
protected:
    Fraction a, b;
public:
    BieuthucPS(int level);
    friend ostream& operator<<(ostream& out, BieuthucPS bt);
    bool kiemtra(float traloi);
    float giatri();
};
```

_File BieuthucPS.h_

```bash
#include "BieuthucPS.h"
```

_File Fraction.h_

```bash
#pragma once
class Fraction {

};
```

_File Fraction.cpp_

```bash
#include "Fraction.h"
```

Yêu cầu:

-   Nộp file Project
-   Hình chụp màn hình thực thi
