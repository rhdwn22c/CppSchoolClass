#include <iostream>
using namespace std;
#define tax 0.0154f;

class Bank {
public:
    int cal(Bank bank, float yearInt);
    int calTax(int monRes);

    int startMoney;
    int calYear;
};

class BankUser {
public:
    float specialYearInt = 4.0f;
    float normalYearInt = 3.0f;
};

int Bank::cal(Bank bank, float yearInt) {
    int moneyResult;
    moneyResult = bank.startMoney * yearInt * (bank.calYear + 1) * bank.calYear / 2 / 12;
    return moneyResult;
}

int Bank::calTax(int moneyResult) {
    int taxResult;
    taxResult = moneyResult - moneyResult * tax;
    return taxResult;
}

int main() {
    int moneyResult, taxResult;
    char whatSaving;

    BankUser user;
    Bank bank;

    cout << "어떤 적금을 가입하시겠습니까? (특판 : s, 일반 : n)";
    cin >> whatSaving;
    cout << "얼마 입금하시겠습니까? : ";
    cin >> bank.startMoney;
    cout << "몇 개월 입금하시겠습니까? : ";
    cin >> bank.calYear;

    if (whatSaving == 's') {
        moneyResult = bank.cal(bank, user.specialYearInt);
    }
    else if (whatSaving == 'n') {
        moneyResult = bank.cal(bank, user.normalYearInt);
    }
    taxResult = bank.calTax(moneyResult);
    moneyResult += bank.startMoney * bank.calYear;
    taxResult += bank.startMoney * bank.calYear;

    cout << "세전 : " << moneyResult << endl;
    cout << "세후 : " << taxResult;

    return 0;
}