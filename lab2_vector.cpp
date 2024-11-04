#include <iostream>
#include <vector>

void inputMatrix(std::vector<std::vector<int>>& matrix) {
    std::cout << "행렬의 요소를 입력하세요:\n";
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    std::vector<std::vector<int>> C(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

int main() {
    int rows, cols;

    std::cout << "행렬의 행과 열의 크기를 입력하세요: ";
    std::cin >> rows >> cols;

    // 행렬 A, B, C 선언
    std::vector<std::vector<int>> A(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> B(rows, std::vector<int>(cols));

    // 행렬 입력
    std::cout << "행렬 A:\n";
    inputMatrix(A);
    std::cout << "행렬 B:\n";
    inputMatrix(B);

    // 행렬 덧셈
    std::vector<std::vector<int>> C = addMatrices(A, B);

    // 결과 출력
    std::cout << "행렬 C (A + B):\n";
    for (const auto& row : C) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
