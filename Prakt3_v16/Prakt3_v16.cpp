#include <iostream>
#include <algorithm>
using namespace std;

union AccountOrAddress
{
    int bankAccount;
    char homeAddress[50];
};

struct Person
{
    char fullName[50];
    char workplace[50];
    AccountOrAddress info;

    bool isWorking() {
        return workplace[0] != '-';
    }
};

// Функция для сравнения двух работающих людей по номеру банковского счета
bool compareByBankAccount(Person a, Person b)
{
    return a.info.bankAccount < b.info.bankAccount;
}

// Функция для вывода информации о человеке
void printPerson(Person person)
{
    cout << "ФИО: " << person.fullName << endl;
    cout << "Место работы: " << person.workplace << endl;
    if (person.isWorking()) {
        cout << "Номер банковского счета: " << person.info.bankAccount << endl;
    }
    else {
        cout << "Домашний адрес: " << person.info.homeAddress << endl;
    }
    cout << "------------------------" << endl;
}

int main()
{
    setlocale(LC_ALL, "RU-ru");

    // Инициализация и вывод исходного массива
    Person people[] = {
        {"Иванов Иван Иванович", "ООО Ромашка", {.bankAccount = 123456}},
        {"Петров Петр Петрович", "-", {.homeAddress = "ул. Ленина, д. 10, кв. 5"}},
        {"Сидорова Анна Сергеевна", "ЗАО Тюльпан", {.bankAccount = 987654}},
        {"Козлов Алексей Владимирович", "-", {.homeAddress = "пр. Мира, д. 25"}},
        {"Чернышев Олег Алексадрович", "ООО Вектор", {.bankAccount = 238192}},
        {"Николаева Мария Дмитриевна", "ОАО Лилия", {.bankAccount = 456789}}
    };
    const int totalPeople = 6;

    cout << "Исходный список всех людей:" << endl;
    cout << "============================" << endl;
    for (int i = 0; i < totalPeople; i++) {
        printPerson(people[i]);
    }
    cout << endl;

    // Создание массива для работающих людей
    Person workingPeople[totalPeople];
    int workingCount = 0;

    // Заполнение массива работающих людей
    for (int i = 0; i < totalPeople; i++) {
        if (people[i].isWorking()) {
            workingPeople[workingCount] = people[i];
            workingCount++;
        }
    }

    // Сортировка работающих людей используя функцию compareByBankAccount
    sort(workingPeople, workingPeople + workingCount, compareByBankAccount);

    // Вывод отсортированного списка работающих
    cout << "Список работающих людей, упорядоченный по номеру банковского счета:" << endl;
    cout << "=====================================================================" << endl;

    if (workingCount == 0) {
        cout << "Нет работающих граждан в списке." << endl;
    }
    else {
        for (int i = 0; i < workingCount; i++) {
            printPerson(workingPeople[i]);
        }
    }
}
