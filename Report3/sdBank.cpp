#include <iostream>
using namespace std;
#define tax 0.154f;

class Bank {
public:
    int cal(Bank bank, float yearInterest);
    int calTax(int moneyResult);

    int initialMoney;
    int savingMonth;
};

class BankUser {
public:
    float savingInterest = 4.0f;
    float depositInterest = 3.0f;
};

int Bank::cal(Bank bank, float yearInterest) {
    int noneTaxMoneyResult;
    noneTaxMoneyResult = bank.initialMoney * yearInterest * (bank.savingMonth + 1) * bank.savingMonth / 2 / 12;
    return noneTaxMoneyResult;
}

int Bank::calTax(int moneyResult) {
    int taxMoneyResult;
    taxMoneyResult = moneyResult - moneyResult * tax;
    return taxMoneyResult;
}

int main() {
    int noneTaxMoneyResult, taxMoneyResult;
    int whatSaving;

    BankUser bankUser;
    Bank bank;

    cout << "어떤 적금을 가입하시겠습니까? (특판 : 1, 일반 : 2)";
    cin >> whatSaving;
    cout << "얼마 입금하시겠습니까? : ";
    cin >> bank.initialMoney;
    cout << "몇 개월 입금하시겠습니까? : ";
    cin >> bank.savingMonth;

    if (whatSaving == '1') {
        noneTaxMoneyResult = bank.cal(bank, bankUser.savingInterest);
    }
    else if (whatSaving == '2') {
        noneTaxMoneyResult = bank.cal(bank, bankUser.depositInterest);
    }
    taxMoneyResult = bank.calTax(noneTaxMoneyResult);
    noneTaxMoneyResult += bank.initialMoney * bank.savingMonth;
    taxMoneyResult += bank.initialMoney * bank.savingMonth;

    cout << "세전 : " << noneTaxMoneyResult << endl;
    cout << "세후 : " << taxMoneyResult;

    return 0;
}