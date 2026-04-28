#include <iostream>
#include <string>

class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // [방식 3] 멤버 함수 (void, 참조 전달)
    // 호출하는 객체c의 값을 직접 변경
    void add_member_void(const Complex& a, const Complex& b) {
        this->real = a.real + b.real;
        this->imag = a.imag + b.imag;
    }

    // [방식 4] 멤버 함수 (return, 참조 전달 매개변수)
    // a.add(b) 형태로 호출하며 새로운 객체를 반환
    Complex add_member_return(const Complex& b) {
        return Complex(this->real + b.real, this->imag + b.imag);
    }

    // [방식 5] 연산자 오버로딩
    // a + b 형태로 직관적인 사용이 가능
    Complex operator+(const Complex& b) {
        return Complex(this->real + b.real, this->imag + b.imag);
    }

    void print(const std::string& label) const {
        std::cout << label << ": " << real << " + " << imag << "i" << std::endl;
    }
};

// [방식 1] 일반 함수 (void, 참조 전달)
void add_global_void(const Complex& a, const Complex& b, Complex& sum) {
    sum.real = a.real + b.real;
    sum.imag = a.imag + b.imag;
}

// [방식 2] 일반 함수 (return, 값 전달)
Complex add_global_return(Complex a, Complex b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);
    Complex c;

    std::cout << "----- 검증(a=1+2i, b=3+4i) -----\n" << std::endl;

    // 방식 1: 일반 함수 (void, 참조)
    add_global_void(a, b, c);
    c.print("1. 일반 함수 (void)");

    // 방식 2: 일반 함수 (return, 값)
    c = add_global_return(a, b);
    c.print("2. 일반 함수 (return)");

    // 방식 3: 멤버 함수 (void, 참조)
    c.add_member_void(a, b);
    c.print("3. 멤버 함수 (void)");

    // 방식 4: 멤버 함수 (return, 참조)
    c = a.add_member_return(b);
    c.print("4. 멤버 함수 (return)");

    // 방식 5: 연산자 오버로딩
    c = a + b;
    c.print("5. 연산자 오버로딩");

    return 0;
}
