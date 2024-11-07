Описание
Данная программа — консольное приложение для общения, которое позволяет пользователям регистрироваться, входить в систему, отправлять сообщения и просматривать свои входящие сообщения. Программа разработана на языке C++ и состоит из классов для управления пользователями и взаимодействия между ними.

Структура проекта
main.cpp: основной файл программы с функцией main().
User.h и User.cpp: классы для представления пользователя.
Container.h: шаблонный класс для хранения сообщений.
Chat.h и Chat.cpp: класс для управления пользователями и отправкой сообщений.

Структура классов
Класс User
Класс представляет пользователя чата.

Атрибуты:

std::string login — логин пользователя.
std::string password — пароль пользователя.
std::string name — имя пользователя.

Методы:

User(const std::string& login, const std::string& password, const std::string& name) — конструктор.
std::string getLogin() const — возвращает логин.
std::string getName() const — возвращает имя.
bool checkPassword(const std::string& pass) const — проверяет правильность пароля.

Шаблонный класс Container<T>
Шаблонный класс для хранения сообщений.

Методы:

void addItem(const T& item) — добавляет элемент.
const std::vector<T>& getItems() const — возвращает элементы или выбрасывает исключение, если контейнер пуст.

Класс Chat
Класс для управления пользователями, аутентификацией и отправкой сообщений.

Атрибуты:

std::vector<User> users — список зарегистрированных пользователей.
std::map<std::string, Container<std::string>> messages — ассоциативный контейнер для хранения сообщений.
Методы:

void registerUser(const std::string& login, const std::string& password, const std::string& name) — регистрирует нового пользователя.
bool loginUser(const std::string& login, const std::string& password) — выполняет вход.
void sendMessageToUser(const std::string& from, const std::string& to, const std::string& message) — отправляет сообщение.
void showMessages(const std::string& login) const — показывает сообщения.
