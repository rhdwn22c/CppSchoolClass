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

    cout << "어떤 적금을 가입하시겠습니까? (특판 : s, 일반 : n)";
    cin >> whatSaving;
    cout << "얼마 입금하시겠습니까? : ";
    cin >> bank.money;
    cout << "몇 개월 입금하시겠습니까? : ";
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

    cout << "세전 : " << monRes << endl;
    cout << "세후 : " << taxRes;

    return 0;
}