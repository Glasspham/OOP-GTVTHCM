# Xây dựng ứng dụng thi trắc nghiệm

-   Đề thi trắc nghiệm bao gồm nhiều câu hỏi trắc nghiệm

-   Mỗi câu hỏi trắc nghiệm bao gồm các thành phần:

    – Nội dung câu hỏi

    – Nội dung đáp án A

    – Nội dung đáp án B

    – Đáp án đúng

-   **Ứng dụng gồm các chức năng sau:**

    – Tạo một đề thi trắc nghiệm mới

    – Thêm một câu hỏi mới từ bàn phím vào đề thi hiện hành

    – In danh sách câu hỏi hiện đang có trong đề thi

    – Lưu danh sách câu hỏi vào file \*.TTN; tên file được nhập từ bàn phím (ví dụ LTHDT–CN15B.TTN)

    – Đọc nội dung một file \*.TTN vào bộ nhớ

    – Cho thi và tính số câu trả lời đúng của thí sinh

**\*Yêu cầu:**

a) Tạo lớp CauhoiTN với các thuộc tính như yêu cầu, các phương thức bao gồm:

-   nhap(): nhập liệu từ bàn phím.

-   docfile(ifstream& f): đọc dữ liệu một câu hỏi từ file stream f.

-   ghifile(ofstream& f): ghi nội dung câu hỏi vào file stream f.

-   kiemtra(): hiện câu hỏi, và cho người dùng nhập câu trả lời, kiểm tra câu trả lời có đúng đáp án không.

-   xuat(): xuất câu hỏi ra màn hình (bao gồm đáp án đúng).

b) Xây dựng thực đơn (Menu) để người dùng có thể lựa chọn chức năng (bao gồm chức năng thoát chương trình).

c) Viết hàm bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) với lớp CauHoiTN để kiểm tra hai câu hỏi có trùng nhau hay không (dùng từ khoá friend).

d) Thực thi chương trình, nhập dữ liệu ít nhất 5 câu hỏi và chụp các màn hình khi thử nghiệm các chức năng. Nộp file word có các màn hình được chụp.