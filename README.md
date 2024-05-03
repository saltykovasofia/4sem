#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    // 1. Чтение из файла целочисленного одномерного вектора
    std::ifstream inputFile("input.txt");
    std::vector<int> vec;
    int num;
    while (inputFile >> num) {
        vec.push_back(num);
    }
    inputFile.close();#include <iostream>
