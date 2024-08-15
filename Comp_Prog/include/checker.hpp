#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <iostream>
#include <vector>

class Checker {
    public:
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

};

#endif // CHECKER_HPP