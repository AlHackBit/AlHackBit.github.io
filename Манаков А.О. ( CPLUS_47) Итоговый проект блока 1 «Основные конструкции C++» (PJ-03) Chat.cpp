#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include <string>

template <typename T>
class Container {
private:
    std::vector<T> items;
public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    const std::vector<T>& getItems() const {
        if (items.empty()) {
            throw std::runtime_error("Нет сообщений.");
        }
        return items;
    }
};

class Chat {
private:
    std::vector<User> users;
    std::map<std::string, Container<std::string>> messages; // Логин пользователя -> контейнер сообщений

public:
    void registerUser(const std::string& login, const std::string& password, const std::string& name) {
        for (const auto& user : users) {
            if (user.getLogin() == login) {
                throw std::runtime_error("Пользователь с таким логином уже существует.");
            }
        }
        users.emplace_back(login, password, name);
        std::cout << "Пользователь зарегистрирован.\n";
    }

    bool loginUser(const std::string& login, const std::string& password) {
        for (const auto& user : users) {
            if (user.getLogin() == login && user.checkPassword(password)) {
                std::cout << "Добро пожаловать, " << user.getName() << "!\n";
                return true;
            }
        }
        throw std::runtime_error("Неверный логин или пароль.");
    }

    void sendMessageToUser(const std::string& from, const std::string& to, const std::string& message) {
        auto it = std::find_if(users.begin(), users.end(), [&to](const User& user) {
            return user.getLogin() == to;
            });

        if (it == users.end()) {
            throw std::runtime_error("Пользователь с логином " + to + " не найден.");
        }
        messages[to].addItem("От " + from + ": " + message);
        std::cout << "Сообщение отправлено.\n";
    }

    void showMessages(const std::string& login) const {
        try {
            const auto& userMessages = messages.at(login).getItems();
            for (const auto& msg : userMessages) {
                std::cout << msg << std::endl;
            }
        }
        catch (const std::out_of_range&) {
            throw std::runtime_error("Сообщений для пользователя нет.");
        }
    }
};