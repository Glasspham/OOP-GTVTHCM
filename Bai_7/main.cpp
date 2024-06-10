/*
a. Hiện thực Lớp Shape, Rectangle, và Triangle như sau, chạy thử và giải thích kết quả xuất ra màn hình.
b. Chỉnh sửa để kết quả xuất ra là diện tích của các hình thuộc lớp con tương ứng.
*/
#include<iostream>
using namespace std;

class Shape{
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0){
        width = a;
        height = b;
    }

    int area(){ 
        cout << "Parent class area :" << endl;
        return 0;
    }
};

class Rectangle : public Shape{
public:
    Rectangle(int a = 0,int b = 0):Shape(a, b){}

    int area (){
        cout <<"Rectangle class area :"<<endl;
        return(width * height);
    }
};

class Triangle : public Shape{
public:
Triangle(int a = 0,int b = 0):Shape(a, b){}
    int area (){
        cout <<"Triangle class area :"<<endl;
        return(width * height / 2);
    }
};

// Main function for the program
int main(){
    Shape*shape;
    Rectangle rec(10,7);
    Triangle  tri(10,5);
    // store the address of Rectangle
    shape =&rec;
    // call rectangle area.
    shape->area();
    // store the address of Triangle
    shape =&tri;
    // call triangle area.
    shape->area();
    return 0;
}
/*
Giải thích Kết quả Xuất ra Màn hình:
Khi chạy chương trình, kết quả xuất ra sẽ như sau:
Parent class area :
Parent class area :
Lý do:
Khi gọi shape->area(), vì area() trong lớp Shape không phải là hàm ảo, nên hàm area() của lớp Shape sẽ được gọi thay vì hàm area() của các lớp con.
Mặc dù shape đang trỏ tới đối tượng của Rectangle và Triangle, nhưng do cơ chế liên kết tĩnh (static binding), hàm area() của lớp cơ sở Shape được gọi.
*/


/*
Phần b: Chỉnh sửa để Kết quả Xuất ra là Diện Tích của Các Hình Thuộc Lớp Con Tương Ứng
Để kết quả xuất ra là diện tích của các hình thuộc lớp con, ta cần sử dụng hàm ảo (virtual function) trong lớp cơ sở Shape.
Chỉnh sửa mã nguồn:
*/

#include<iostream>
using namespace std;

class Shape{
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0){
        width = a;
        height = b;
    }

    virtual int area(){  // Sử dụng từ khóa virtual
        cout << "Parent class area :" << endl;
        return 0;
    }
};

class Rectangle : public Shape{
public:
    Rectangle(int a = 0, int b = 0): Shape(a, b){}

    int area (){
        cout << "Rectangle class area :" << endl;
        return(width * height);
    }
};

class Triangle : public Shape{
public:
    Triangle(int a = 0, int b = 0): Shape(a, b){}

    int area (){
        cout << "Triangle class area :" << endl;
        return(width * height / 2);
    }
};

// Main function for the program
int main(){
    Shape* shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);
    // store the address of Rectangle
    shape = &rec;
    // call rectangle area.
    cout << shape->area() << endl;
    // store the address of Triangle
    shape = &tri;
    // call triangle area.
    cout << shape->area() << endl;
    return 0;
}

/*
Kết quả sau khi chỉnh sửa:
Rectangle class area :
70
Triangle class area :
25
Lý do:
Khi sử dụng từ khóa virtual cho hàm area() trong lớp Shape, cơ chế liên kết động (dynamic binding) được áp dụng.
Khi gọi shape->area(), hàm area() tương ứng của đối tượng hiện tại (Rectangle hoặc Triangle) sẽ được gọi thay vì hàm area() của lớp cơ sở Shape.
*/