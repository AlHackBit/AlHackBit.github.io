#include <string>
#include <vector>

class User {
private:
    std::string login;
    std::string password;
    std::string name;
public:
    User(const std::string& login, const std::string& password, const std::string& name)
        : login(login), password(password), name(name) {}

    std::string getLogin() const { return login; }
    std::string getName() const { return name; }
    bool checkPassword(const std::string& pass) const { return password == pass; }
};