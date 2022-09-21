#include <iostream>
using namespace std;

const float taxPer = 0.154f;
const float savingInterest = 0.04f;
const float depositInterest = 0.03f;

class User
{
public:
    int id = 0;
    string* name = new string();

    int initialMoney = 0;
    int savingMonth = 0;

    void UserBank(const User& rhs) {
        initialMoney = rhs.initialMoney;
        savingMonth = rhs.savingMonth;
    }
};

class Bank
{
public:
    int SavingCal(User user);
    int DepositCal(User user);

};

int Bank::SavingCal(User user)
{
    int taxMoneyResult = 0;
    taxMoneyResult = user.initialMoney * savingInterest * (user.savingMonth + 1) * user.savingMonth / 24;
    taxMoneyResult = taxMoneyResult - taxMoneyResult * taxPer;
    return taxMoneyResult;
}

int Bank::DepositCal(User user)
{
    int taxMoneyResult;
    taxMoneyResult = user.initialMoney * depositInterest - ((user.initialMoney * depositInterest) * taxPer);
    return taxMoneyResult;
}

int main()
{
    int savingMoneyResult = 0;
    int depositMoneyResult = 0;
    string name;
    int id;

    User user;
    Bank bank;

    cout << "아이디를 입력해주세요 : ";
    cin >> id;
    cout << "이름을 입력해주세요 : ";
    cin >> name;
    cout << "돈을 얼마 넣으시겠습니까? : ";
    cin >> user.initialMoney;
    cout << "몇 개월 동안 넣으시겠습니까? : ";
    cin >> user.savingMonth;

    user.UserBank(user);

    savingMoneyResult = bank.SavingCal(user);
    savingMoneyResult += user.initialMoney * user.savingMonth;
    depositMoneyResult = user.initialMoney + bank.DepositCal(user);
    cout << id << " / " << name << endl;
    cout << "적금 : " << savingMoneyResult << endl;
    cout << "예금 : " << depositMoneyResult;
   

    return 0;
}