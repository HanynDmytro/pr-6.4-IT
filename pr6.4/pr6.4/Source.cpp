#include <iostream>
#include <cstdlib> // ��� rand() � srand()
#include <ctime>   // ��� time()
#include <cmath>   // ��� abs()
#include<windows.h>

using namespace std;

void InitArray(int* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 21 - 10;
    }
}

// ���������� ������� ��� ��������� ������
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ���������� ������� ��� ���������� ���� �������� � ��������� ���������
int sumOddIndexElements(const int* arr, int size) {
    int sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

// ���������� ������� ��� ������ ������� ��'������ ��������
int findFirstNegative(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) return i;
    }
    return -1;
}

// ���������� ������� ��� ������ ���������� ��'������ ��������
int findLastNegative(const int* arr, int size) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] < 0) return i;
    }
    return -1;
}

// ���������� ������� ��� ���������� ���� �� ������ �� ������� ��'������ ����������
int sumBetweenNegatives(const int* arr, int start, int end) {
    int sum = 0;
    for (int i = start; i < end; ++i) {
        sum += arr[i];
    }
    return sum;
}

// ���������� ������� ��� ��������� ������ (��������� ��������, ������ ���� <= 1)
void compressArray(int* arr, int& size) {
    int newIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (abs(arr[i]) > 1) {
            arr[newIndex++] = arr[i];
        }
    }
    // ���������� ����� ������ ������
    for (int i = newIndex; i < size; ++i) {
        arr[i] = 0;
    }
}

int main() {
    // ���������� ��������� ���������� �����
    srand(time(0));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "������ ������� �������� ������: ";
    cin >> n;

    // �������� �������� ���'�� ��� ������
    int* arr = new int[n];
    InitArray(arr, n);

    cout << "���������� �����: ";
    printArray(arr, n);

    // 1.1. ���� �������� � ��������� ���������
    int sumOdd = sumOddIndexElements(arr, n);
    cout << "���� �������� � ��������� ���������: " << sumOdd << endl;

    // 1.2. ���� �� ������ �� ������� ��'������ ����������
    int firstNeg = findFirstNegative(arr, n);
    int lastNeg = findLastNegative(arr, n);

    if (firstNeg != -1 && lastNeg != -1 && firstNeg < lastNeg) {
        int sumBetween = sumBetweenNegatives(arr, firstNeg + 1, lastNeg);
        cout << "���� �������� �� ������ � ������� ��'������: " << sumBetween << endl;
    }
    else {
        cout << "�� �������� ���� ��'����� �������� ��� ���������� ����." << endl;
    }

    // 2. ��������� ������
    compressArray(arr, n);
    cout << "����� ���� ���������: ";
    printArray(arr, n);

    // ��������� �������� ���'��
    delete[] arr;

    return 0;
}
