#include <iostream>

void inputMatrix(int** matrix, int rows, int cols) {
    std::cout << "행렬의 요소를 입력하세요:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void addMatrices(int** A, int** B, int** C, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols;

    std::cout << "행렬의 행과 열의 크기를 입력하세요: ";
    std::cin >> rows >> cols;

    // 행렬 A, B, C의 동적 메모리 할당
    int** A = new int*[rows];
    int** B = new int*[rows];
    int** C = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        A[i] = new int[cols];
        B[i] = new int[cols];
        C[i] = new int[cols];
    }

    // 행렬 입력
    std::cout << "행렬 A:\n";
    inputMatrix(A, rows, cols);
    std::cout << "행렬 B:\n";
    inputMatrix(B, rows, cols);

    // 행렬 덧셈
    addMatrices(A, B, C, rows, cols);

    // 결과 출력
    std::cout << "행렬 C (A + B):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 메모리 해제
    freeMatrix(A, rows);
    freeMatrix(B, rows);
    freeMatrix(C, rows);

    return 0;
}
