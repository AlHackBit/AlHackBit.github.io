#include <iostream>

int main() {
    Chat chat;
    int choice;
    std::string login, password, name, to, message;

    while (true) {
        std::cout << "1. ���������\n2. �室\n3. ��ࠢ��� ᮮ�饭��\n4. �������� ᮮ�饭��\n5. ��室\n";
        std::cout << "�롥�� ����⢨�: ";
        try {
            std::cin >> choice;
            if (std::cin.fail()) {
                throw std::invalid_argument("�訡�� �����. ��������� 楫�� �᫮.");
            }

            switch (choice) {
            case 1:
                std::cout << "������ �����: ";
                std::cin >> login;
                std::cout << "������ ��஫�: ";
                std::cin >> password;
                std::cout << "������ ���: ";
                std::cin >> name;
                chat.registerUser(login, password, name);
                break;
            case 2:
                std::cout << "������ �����: ";
                std::cin >> login;
                std::cout << "������ ��஫�: ";
                std::cin >> password;
                chat.loginUser(login, password);
                break;
            case 3:
                std::cout << "��ࠢ��� ᮮ�饭�� ���� (�����): ";
                std::cin >> to;
                std::cout << "������ ᮮ�饭��: ";
                std::cin.ignore();
                std::getline(std::cin, message);
                chat.sendMessageToUser(login, to, message);
                break;
            case 4:
                chat.showMessages(login);
                break;
            case 5:
                std::cout << "��室 �� �ணࠬ��.\n";
                return 0;
            default:
                std::cout << "������ �롮�. ���஡�� ᭮��.\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "�訡��: " << e.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}