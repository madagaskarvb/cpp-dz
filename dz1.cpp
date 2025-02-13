#include <iostream>
#include <string>

struct MyException {
    std::string message; 

    MyException(const std::string& msg) : message(msg) {}
};

void riskyFunction(int value) {
    if (value < 0) {
        throw MyException("Отрицательное значение недопустимо!");
    }
    std::cout << "Значение корректно: " << value << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    try {
        riskyFunction(10);

        riskyFunction(-5);
    }
    catch (const MyException& e) {
        std::cerr << "Произошла ошибка: " << e.message << std::endl;
    }

    return 0;
}
