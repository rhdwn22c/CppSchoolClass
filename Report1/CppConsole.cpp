#include <iostream>
using namespace std;

class Bank {
public:
    int startMoney;
    int calYear;
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
    monRes = bank.startMoney * yearInt / 100 * (bank.calYear + 1) * bank.calYear / 2 / 12;
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

    cin >> bank.startMoney;
    cin >> bank.calYear;

    monRes = user.cal(bank);
    taxRes = user.calTax(monRes);
    monRes += bank.startMoney * bank.calYear;
    taxRes += bank.startMoney * bank.calYear;

    cout << "세전 : " << monRes << endl;
    cout << "세후 : " << taxRes;

    return 0;
}