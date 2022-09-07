#include <iostream>
using namespace std;

class Bank {
public:
    int money;
    int year;
};

class BankUser {
public:
    int cal(Bank bank);
    int calTax(int monRes);

    float taxPer = 15.4f;
    float yearInt = 3.55f;
};

int BankUser :: cal(Bank bank) {
    int monRes;
    monRes = bank.money * yearInt / 100 * (bank.year + 1) * bank.year / 2 / 12;
    return monRes;
}

int BankUser :: calTax(int monRes) {
    int taxRes;
    taxRes = monRes - monRes * taxPer / 100;
    return taxRes;
}

int main() {
    int monRes, taxRes;

    BankUser user;
    Bank bank;

    cin >> bank.money;
    cin >> bank.year;

    monRes = user.cal(bank);
    taxRes = user.calTax(monRes);
    monRes += bank.money * bank.year;
    taxRes += bank.money * bank.year;

    cout << "세전 : " << monRes << endl;
    cout << "세후 : " << taxRes;

    return 0;
}