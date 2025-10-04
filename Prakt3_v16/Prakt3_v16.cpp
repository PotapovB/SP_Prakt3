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

// ������� ��� ��������� ���� ���������� ����� �� ������ ����������� �����
bool compareByBankAccount(Person a, Person b)
{
    return a.info.bankAccount < b.info.bankAccount;
}

// ������� ��� ������ ���������� � ��������
void printPerson(Person person)
{
    cout << "���: " << person.fullName << endl;
    cout << "����� ������: " << person.workplace << endl;
    if (person.isWorking()) {
        cout << "����� ����������� �����: " << person.info.bankAccount << endl;
    }
    else {
        cout << "�������� �����: " << person.info.homeAddress << endl;
    }
    cout << "------------------------" << endl;
}

int main()
{
    setlocale(LC_ALL, "RU-ru");

    // ������������� � ����� ��������� �������
    Person people[] = {
        {"������ ���� ��������", "��� �������", {.bankAccount = 123456}},
        {"������ ���� ��������", "-", {.homeAddress = "��. ������, �. 10, ��. 5"}},
        {"�������� ���� ���������", "��� �������", {.bankAccount = 987654}},
        {"������ ������� ������������", "-", {.homeAddress = "��. ����, �. 25"}},
        {"�������� ���� ������������", "��� ������", {.bankAccount = 238192}},
        {"��������� ����� ����������", "��� �����", {.bankAccount = 456789}}
    };
    const int totalPeople = 6;

    cout << "�������� ������ ���� �����:" << endl;
    cout << "============================" << endl;
    for (int i = 0; i < totalPeople; i++) {
        printPerson(people[i]);
    }
    cout << endl;

    // �������� ������� ��� ���������� �����
    Person workingPeople[totalPeople];
    int workingCount = 0;

    // ���������� ������� ���������� �����
    for (int i = 0; i < totalPeople; i++) {
        if (people[i].isWorking()) {
            workingPeople[workingCount] = people[i];
            workingCount++;
        }
    }

    // ���������� ���������� ����� ��������� ������� compareByBankAccount
    sort(workingPeople, workingPeople + workingCount, compareByBankAccount);

    // ����� ���������������� ������ ����������
    cout << "������ ���������� �����, ������������� �� ������ ����������� �����:" << endl;
    cout << "=====================================================================" << endl;

    if (workingCount == 0) {
        cout << "��� ���������� ������� � ������." << endl;
    }
    else {
        for (int i = 0; i < workingCount; i++) {
            printPerson(workingPeople[i]);
        }
    }
}
