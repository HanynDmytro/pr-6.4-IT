#include <iostream>
#include <cstdlib> // для rand() і srand()
#include <ctime>   // для time()
#include <cmath>   // для abs()
#include<windows.h>

using namespace std;

void InitArray(int* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 21 - 10;
    }
}

// Ітеративна функція для виведення масиву
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Ітеративна функція для обчислення суми елементів з непарними індексами
int sumOddIndexElements(const int* arr, int size) {
    int sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

// Ітеративна функція для пошуку першого від'ємного елемента
int findFirstNegative(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) return i;
    }
    return -1;
}

// Ітеративна функція для пошуку останнього від'ємного елемента
int findLastNegative(const int* arr, int size) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] < 0) return i;
    }
    return -1;
}

// Ітеративна функція для обчислення суми між першим та останнім від'ємними елементами
int sumBetweenNegatives(const int* arr, int start, int end) {
    int sum = 0;
    for (int i = start; i < end; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Ітеративна функція для стискання масиву (видалення елементів, модуль яких <= 1)
void compressArray(int* arr, int& size) {
    int newIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (abs(arr[i]) > 1) {
            arr[newIndex++] = arr[i];
        }
    }
    // Заповнюємо решту масиву нулями
    for (int i = newIndex; i < size; ++i) {
        arr[i] = 0;
    }
}

int main() {
    // Ініціалізуємо генератор випадкових чисел
    srand(time(0));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    // Динамічне виділення пам'яті для масиву
    int* arr = new int[n];
    InitArray(arr, n);

    cout << "Початковий масив: ";
    printArray(arr, n);

    // 1.1. Сума елементів з непарними індексами
    int sumOdd = sumOddIndexElements(arr, n);
    cout << "Сума елементів з непарними індексами: " << sumOdd << endl;

    // 1.2. Сума між першим та останнім від'ємними елементами
    int firstNeg = findFirstNegative(arr, n);
    int lastNeg = findLastNegative(arr, n);

    if (firstNeg != -1 && lastNeg != -1 && firstNeg < lastNeg) {
        int sumBetween = sumBetweenNegatives(arr, firstNeg + 1, lastNeg);
        cout << "Сума елементів між першим і останнім від'ємними: " << sumBetween << endl;
    }
    else {
        cout << "Не знайдено двох від'ємних елементів для обчислення суми." << endl;
    }

    // 2. Стиснення масиву
    compressArray(arr, n);
    cout << "Масив після стиснення: ";
    printArray(arr, n);

    // Звільнення динамічної пам'яті
    delete[] arr;

    return 0;
}
