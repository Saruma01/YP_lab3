#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция линейного поиска
int* linear_search(int* begin, int* end, int value) {
    for (int* ptr = begin; ptr != end; ++ptr) {
        if (*ptr == value) {
            return ptr;
        }
    }
    return end;
}

// Функция двоичного поиска
int* binary_search(int* begin, int* end, int value) {
    int* left = begin;
    int* right = end;

    while (left < right) {
        int* mid = left + (right - left) / 2;

        if (*mid < value) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}

// Глобальные переменные для хранения массива
int* array_ptr = nullptr;
size_t array_size = 0;

// Функция для вывода массива
void print_array() {
    if (array_ptr == nullptr) {
        cout << "Массив не создан!" << endl;
        return;
    }

    cout << "Текущий массив: [";
    for (size_t i = 0; i < array_size; ++i) {
        cout << array_ptr[i];
        if (i != array_size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Функция создания массива
void create_array() {
    // Удаляем старый массив, если он существует
    if (array_ptr != nullptr) {
        delete[] array_ptr;
    }

    cout << "Введите размер массива: ";
    cin >> array_size;

    // Создаем новый массив
    array_ptr = new int[array_size];
    srand(time(nullptr));

    // Заполняем случайными числами от 0 до 99
    for (size_t i = 0; i < array_size; ++i) {
        array_ptr[i] = rand() % 100;
    }

    print_array();
}

// Функция для выполнения линейного поиска
void perform_linear_search() {
    if (array_ptr == nullptr) {
        cout << "Массив не создан!" << endl;
        return;
    }

    int value;
    cout << "Введите искомое значение: ";
    cin >> value;

    int* result = linear_search(array_ptr, array_ptr + array_size, value);

    if (result == array_ptr + array_size) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout << "Элемент найден по индексу " << (result - array_ptr) << endl;
    }
}

// Функция для сортировки массива
void sort_array() {
    if (array_ptr == nullptr) {
        cout << "Массив не создан!" << endl;
        return;
    }

    sort(array_ptr, array_ptr + array_size);
    cout << "Массив отсортирован." << endl;
    print_array();
}

// Функция для перемешивания массива
void shuffle_array() {
    if (array_ptr == nullptr) {
        cout << "Массив не создан!" << endl;
        return;
    }

    random_shuffle(array_ptr, array_ptr + array_size);
    cout << "Массив перемешан." << endl;
    print_array();
}

// Функция для выполнения двоичного поиска
void perform_binary_search() {
    if (array_ptr == nullptr) {
        cout << "Массив не создан!" << endl;
        return;
    }

    int value;
    cout << "Введите искомое значение: ";
    cin >> value;

    int* result = binary_search(array_ptr, array_ptr + array_size, value);

    if (result == array_ptr + array_size) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout << "Первый элемент >= " << value << " найден по индексу "
            << (result - array_ptr) << " (значение: " << *result << ")" << endl;
    }
}

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");

    while (true) {
        cout << "\nМеню:" << endl;
        cout << "1. Создать/пересоздать массив" << endl;
        cout << "2. Выполнить линейный поиск" << endl;
        cout << "3. Отсортировать массив" << endl;
        cout << "4. Перемешать массив" << endl;
        cout << "5. Выполнить двоичный поиск" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите команду: ";

        int command;
        cin >> command;

        switch (command) {
        case 1:
            create_array();
            break;
        case 2:
            perform_linear_search();
            print_array();
            break;
        case 3:
            sort_array();
            break;
        case 4:
            shuffle_array();
            break;
        case 5:
            perform_binary_search();
            print_array();
            break;
        case 0:
            // Освобождаем память перед выходом
            if (array_ptr != nullptr) {
                delete[] array_ptr;
            }
            return 0;
        default:
            cout << "Неизвестная команда!" << endl;
        }
    }
}