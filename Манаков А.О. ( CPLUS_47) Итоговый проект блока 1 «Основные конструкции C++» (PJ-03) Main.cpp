#include <iostream>

int main() {
    Chat chat;
    int choice;
    std::string login, password, name, to, message;

    while (true) {
        std::cout << "1. Регистрация\n2. Вход\n3. Отправить сообщение\n4. Показать сообщения\n5. Выход\n";
        std::cout << "Выберите действие: ";
        try {
            std::cin >> choice;
            if (std::cin.fail()) {
                throw std::invalid_argument("Ошибка ввода. Ожидается целое число.");
            }

            switch (choice) {
            case 1:
                std::cout << "Введите логин: ";
                std::cin >> login;
                std::cout << "Введите пароль: ";
                std::cin >> password;
                std::cout << "Введите имя: ";
                std::cin >> name;
                chat.registerUser(login, password, name);
                break;
            case 2:
                std::cout << "Введите логин: ";
                std::cin >> login;
                std::cout << "Введите пароль: ";
                std::cin >> password;
                chat.loginUser(login, password);
                break;
            case 3:
                std::cout << "Отправить сообщение кому (логин): ";
                std::cin >> to;
                std::cout << "Введите сообщение: ";
                std::cin.ignore();
                std::getline(std::cin, message);
                chat.sendMessageToUser(login, to, message);
                break;
            case 4:
                chat.showMessages(login);
                break;
            case 5:
                std::cout << "Выход из программы.\n";
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}