#include <iostream>
#include <cstring>

using namespace std;

class Sample {
    char *name;
    // (1) Sample 객체의 개수를 관리하는 정적 변수 count 선언
    static int count;

public:
    Sample() { 
        name = nullptr;
        count++; // 객체 생성 시 개수 증가
    }

    // (2) 생성자: this와 new 키워드를 이용하여 name 초기화
    Sample(const char * name) {
        this->name = new char[strlen(name) + 1]; 
        strcpy(this->name, name);
        count++;
    }

    // (4) 복사 생성자: 동적 할당된 메모리를 위한 깊은 복사 구현
    Sample(const Sample& s) {
        if (s.name != nullptr) {
            this->name = new char[strlen(s.name) + 1];
            strcpy(this->name, s.name);
        } else {
            this->name = nullptr;
        }
        count++; 
    }

    // (3) 소멸자: char* name을 동적 해제시켜주는 코드 작성
    ~Sample() {
        if (this->name != nullptr) {
            delete[] this->name;
        }
        count--;
    }

    // (1) 출력을 해주는 함수 printCount() 구현
    static void printCount() {
        cout << "현재 Sample 객체의 개수: " << count << endl;
    }
};

// (1) 정적 변수 count 초기화
int Sample::count = 0;


int main() {
    Sample::printCount(); 

    Sample a("sample");
    
    Sample b(a);

    Sample::printCount();

    return 0;
}