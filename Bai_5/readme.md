# **Bài Tập Thực Hành**

Cho một phần mô tả ứng dụng quản lý tiền lương nhân viên của công ty XYZ như sau:

-   Mỗi nhân viên (Employee) thuộc một trong hai loại: nhân viên làm việc toàn thời gian (Full Time Employee) và nhân viên làm việc bán thời gian (Part Time Employee).
-   Tất cả nhân viên đều có các thuộc tính: mã, họ tên, ngày vào làm, số điện thoại, lương căn bản.
-   Ngoài ra,
    -   FullTimeEmplovee có thêm thuộc tính: hệ số lương, số năm kinh nghiệm.
    -   PartTimeEmployee có thêm thuộc tính: số giờ làm/tuần, mức lương mỗi giờ.
-   Cách tính tiền lương mỗi loại nhân viên như sau:
    -   Đối với FullTime Employee: `Lương` = `lương theo hệ số` + `% số năm kinh nghiệm` * `lương theo hệ số`.
        -   Trong đó: `lương theo hệ số` = `lương căn bản` * `hệ số lương`.
        -   Ví dụ: nhân viên có lương căn bản là 1.800.000, hệ số lương là 3.0, số năm kinh nghiêm là 5 thì lương = (1.800.000*3.0)+5%(1.800.000*3.0).
    -   Đối yới Part Time Employee: `Lương` = `30% lương căn bản` + `lương sản phẩm`.
        -   Trong đó: `lương sản phẩm` = `số giờ làm/tuần` * `mức lương mỗi giờ` và nếu làm vượt 40 giờ/tuần thì phần giờ dư được tính lương gấp rưỡi.

**Yêu cầu:**
## Câu 1. (5.0 điểm)
Cài đặt các lớp: Employee, FullTimeEmployee, PartTimeEmployee với mối quan hệ kế thừa. Lớp nào có thế là lớp trừu tượng? Hãy cài đặt tính trừu tượng (virtual) cho lớp đó. Ở mỗi lớp, phải có các get/set; constructor đủ tham số, trong đó có kiểm tra ràng buộc dữ liệu theo mô tả sau (nếu vi phạm ràng buộc thị gán giá trị mặc định hợp lý hoặc ném lỗi):
-   -> Ngày vào làm phải trước hoặc bằng ngày hiện tại.
-   -> Số điện thoại là chuỗi có 10 ký số và bắt đầu bằng số 0.
-   -> Hệ số lương phải ≥ 1.65 và ≤ 8.00.
Các thuộc tính còn lại phải ≥ 0 (nếu là kiếu số) và không được rổng (nếu là kiểu chuỗi) các kiểu dữ liệu ngày, tiền hợp lý.

## Câu 2. (5.0 điểm)
Cài đặt lớp khác để quản lý dạnh sách các nhân viên, sử dụng vector để chứa danh sách này. Trong lớp này, viết các phương thức sau, sao cho hợp lý:
-   -> Thêm cứng vào danh sách 5 nhân viên đủ loại, xuất ra toàn bộ danh sách dạng bảng, có tiêu đề và định dạng thông tin hợp lý
-   -> Thêm một nhân viên vào danh sách, không được thêm trùng mã.
-   -> Tính tổng lương của toàn bộ nhân viên.
-   -> Đếm số lương các nhân viên vào làm trong năm bất kỳ.
-   -> Cập nhật số giờ làm cho nhân viên.
-   -> Sắp xếp nhân viên giảm dần theo ngày vào làm.
-   -> Viết phương thức main gọi các phương thức yêu cầu trên và xuất kết quả ra màn hình, yêu cầu người đúng nhập thông tin khi thực hiện tính năng tương ứng.