#include <iostream>
using namespace std;

class Bank {
public:
    int money;
    int year;
};

class BankUser {
public:
    int cal(Bank bank, float yearInt);
    int calTax(int monRes);

    float taxPer = 15.4f;
    float sYearInt = 4.0f;
    float nYearInt = 3.0f;
};

int BankUser::cal(Bank bank, float yearInt) {
    int monRes;
    monRes = bank.money * yearInt / 100 * (bank.year + 1) * bank.year / 2 / 12;
    return monRes;
}

int BankUser::calTax(int monRes) {
    int taxRes;
    taxRes = monRes - monRes * taxPer / 100;
    return taxRes;
}

int main() {
    int monRes, taxRes;
    int whatSaving;

    BankUser user;
    Bank bank;

    cout << "� ������ �����Ͻðڽ��ϱ�? (Ư�� : s, �Ϲ� : n)";
    cin >> whatSaving;
    cout << "�� �Ա��Ͻðڽ��ϱ�? : ";
    cin >> bank.money;
    cout << "�� ���� �Ա��Ͻðڽ��ϱ�? : ";
    cin >> bank.year;

    if (whatSaving == 's') {
        monRes = user.cal(bank, user.sYearInt);
    }
    else if (whatSaving == 'n') {
        monRes = user.cal(bank, user.nYearInt);
    }
    taxRes = user.calTax(monRes);
    monRes += bank.money * bank.year;
    taxRes += bank.money * bank.year;

    cout << "���� : " << monRes << endl;
    cout << "���� : " << taxRes;

    return 0;
}