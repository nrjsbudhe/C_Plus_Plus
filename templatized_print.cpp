#include <iostream>
#include <vector>
#include <string>
#include <numeric>

// Overload for individual elements
template <typename T>
void printAnswer(const T& element) {
    std::cout << element << std::endl;
}

// Overload for arrays
template <typename T, std::size_t N>
void printAnswer(const T (&array)[N]) {
    for (const auto& elem : array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Overload for vectors
template <typename T>
void printAnswer(const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}


int main() {
    int num = 42;
    char ch = 'A';
    std::string str = "Hello, World!";
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec = {6, 1, 1, 1, 1};
    std::vector<char> vec1 = {'a', 'b', 'c', 'd', 'e'};
    std::vector<std::string> vec2 = {"Hello", "World", "!"};
    std::vector<float> vec3 = {1.1, 2.2, 3.3, 4.4, 5.5};

    printAnswer(num);  // Calls the overload for single elements
    printAnswer(ch);   // Calls the overload for single elements
    printAnswer(str);  // Calls the overload for single elements
    printAnswer(arr);  // Calls the overload for arrays
    printAnswer(vec1);  // Calls the overload for arrays
    printAnswer(vec2);  // Calls the overload for arrays
    printAnswer(vec3);   // Calls the overload for arrays
    printAnswer(std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>()));  // Calls the overload for single elements
    std::cout << vec[-1] << std::endl;
    return 0;
}
