#include <iostream>
#include <string>

struct Student {
    std::string name;
    int midterm;
    int final;
};

struct TreeNode {
    Student student;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insert(TreeNode* node, const Student& student) {
    if (node == nullptr) {
        TreeNode* newNode = new TreeNode{student, nullptr, nullptr};
        return newNode;
    }

    if (student.name < node->student.name) {
        node->left = insert(node->left, student);
    } else {
        node->right = insert(node->right, student);
    }
    return node;
}

void inorder(TreeNode* node) {
    if (node) {
        inorder(node->left);
        std::cout << "이름: " << node->student.name 
                  << ", 중간 점수: " << node->student.midterm 
                  << ", 기말 점수: " << node->student.final << std::endl;
        inorder(node->right);
    }
}

void freeTree(TreeNode* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }
}

int main() {
    int n;
    std::cout << "학생 수를 입력하세요: ";
    std::cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; ++i) {
        Student student;
        std::cout << "학생 이름: ";
        std::cin >> student.name;
        std::cout << "중간 점수: ";
        std::cin >> student.midterm;
        std::cout << "기말 점수: ";
        std::cin >> student.final;

        root = insert(root, student);
    }

    std::cout << "\n학생 목록 (이름순):\n";
    inorder(root);

    freeTree(root);
    return 0;
}

