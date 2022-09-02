#include <iostream>
using namespace std;

float taxPer = 0.154f;
float yearInt = 0.0355f;

class Bank {
public:
    int money;
    int year;
};

class BankUser {
public:
    int calculation(Bank bank);
    int calculationTax(int moneyResult);
};

int BankUser :: calculation(Bank bank) {
    int moneyResult;

    moneyResult = bank.money * yearInt * (bank.year + 1) * bank.year / 2 / 12 - 5;
    return moneyResult;
}

int BankUser :: calculationTax(int moneyResult) {
    int taxRes;

    taxRes = moneyResult - moneyResult * taxPer;
    return taxRes;
}


int main() {
    BankUser user;
    Bank bank;

    int moneyResult, taxResult;

    cout << "�����Աݾ� : ";
    cin >> bank.money;
    cout << "��ǥ�Ⱓ : ";
    cin >> bank.year;

    moneyResult = user.calculation(bank);
    taxResult = user.calculationTax(moneyResult);
    moneyResult += bank.money * bank.year;
    taxResult += bank.money * bank.year;

    cout << "���ݽ� ���� :  " << moneyResult <<  endl;
    cout << "���ݽ� ���� : " << taxResult << endl;
}