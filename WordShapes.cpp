#include <iostream>
#include <string>
#include <vector>
#include <random>

std::vector<std::string> words = { "word1", "word2", "word3", "word4", "word5" };
std::random_device rd;
std::mt19937 rng(rd());

void printTriangle(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << words[j % words.size()] << " ";
        }
        std::cout << std::endl;
    }
}

void printPyramid(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            std::cout << words[j % words.size()] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Enter the number of word shapes to generate: ";
    int numShapes;
    std::cin >> numShapes;

    std::cout << "Enter the size of each shape: ";
    int size;
    std::cin >> size;

    for (int i = 0; i < numShapes; i++) {
        std::cout << "Shape " << i + 1 << ": " << std::endl;
        std::uniform_int_distribution<int> dist(0, 1);
        if (dist(rng) == 0) {
            printTriangle(size);
        } else {
            printPyramid(size);
        }
        std::cout << std::endl;
    }

    return 0;
}
