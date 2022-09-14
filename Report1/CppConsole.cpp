#include <iostream>
using namespace std;

class Bank {
public:
    int initialMoney;
    int savingMonth;
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
    monRes = bank.initialMoney * yearInt / 100 * (bank.savingMonth + 1) * bank.savingMonth / 2 / 12;
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

    cin >> bank.initialMoney;
    cin >> bank.savingMonth;

    monRes = user.cal(bank);
    taxRes = user.calTax(monRes);
    monRes += bank.initialMoney * bank.savingMonth;
    taxRes += bank.initialMoney * bank.savingMonth;

    cout << "세전 : " << monRes << endl;
    cout << "세후 : " << taxRes;

    return 0;
}