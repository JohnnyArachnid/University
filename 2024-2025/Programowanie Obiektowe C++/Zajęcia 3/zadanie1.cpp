#include <iostream>
#include <cstring>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T* max(T* a, T* b) {
    return (*a > *b) ? a : b;
}

template <typename T>
T max(T* data, size_t n) {
    T max_value = data[0];
    for (size_t i = 1; i < n; ++i) {
        if (data[i] > max_value)
            max_value = data[i];
    }
    return max_value;
}

template <>
char* max(char* a, char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

template <>
const char* max(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

template<typename T> 
const char* max(T *a, const T *b) {
    return (*a > *b) ? a : b;
}

template<> 
const char* max(char *a, const char *b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    int a = 5, b = 10;
    std::cout << "Max(5, 10): " << max(a, b) << std::endl;

    int x = 7, y = 3;
    std::cout << "Max(&7, &3): " << max(&x, &y) << std::endl;

    int arr[] = {1, 5, 3, 9, 2};
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;
    std::cout << "Max in array: " << max(arr, 5) << std::endl;

    char str5[] = "tiger";
    const char* str6 = "elephant";
    std::cout << "Max(tiger, elephant): " << max(str5, str6) << std::endl;

    char str1[] = "apple";
    char str2[] = "banana";
    std::cout << "Max(apple, banana): " << max(str1, str2) << std::endl;

    const char* str3 = "zebra";
    const char* str4 = "lion";
    std::cout << "Max(zebra, lion): " << max(str3, str4) << std::endl;

    return 0;
}