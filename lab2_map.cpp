#include <iostream>
#include <string>
#include <map>

struct Student {
    int midterm;
    int final;
};

int main() {
    int n;
    std::cout << "학생 수를 입력하세요: ";
    std::cin >> n;

    std::map<std::string, Student> students;

    for (int i = 0; i < n; ++i) {
        std::string name;
        Student student;

        std::cout << "학생 이름: ";
        std::cin >> name;
        std::cout << "중간 점수: ";
        std::cin >> student.midterm;
        std::cout << "기말 점수: ";
        std::cin >> student.final;

        students[name] = student; // 이름을 키로 하여 학생 정보 저장
    }

    std::cout << "\n학생 목록 (이름순):\n";
    for (const auto& entry : students) {
        std::cout << "이름: " << entry.first 
                  << ", 중간 점수: " << entry.second.midterm 
                  << ", 기말 점수: " << entry.second.final << std::endl;
    }

    return 0;
}

