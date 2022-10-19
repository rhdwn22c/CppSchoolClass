#include <iostream>
using namespace std;
#define YEAR 12
#define TAXFREE 200000

class Insurance {
public:
	int NationalPensionCalculate(int money) {
		return money * nationalPension;
	}

	int HealthInsuranceCalculate(int money) {
		return money * healthInsurance;
	}

	int LongTermCareInsuranceCalculate(int money) {
		return HealthInsuranceCalculate(money) * longTermCareInsurance;
	}

	int EmploymentInsuranceCalculate(int money) {
		return money * employmentInsurance;
	}

	int LocalIncomeTaxCalculate(int incomeTax) {
		return incomeTax * localIncomeTax;
	}

	int FinalInsuranceCalculate(int incomeTax, int money) {
		return NationalPensionCalculate(money) - HealthInsuranceCalculate(money) - LongTermCareInsuranceCalculate(money) - EmploymentInsuranceCalculate(money) - incomeTax - LocalIncomeTaxCalculate(incomeTax);
	}

private:
	float nationalPension = 0.045;
	float healthInsurance = 0.03495;
	float longTermCareInsurance = 0.1227;
	float employmentInsurance = 0.009;
	float localIncomeTax = 0.1;
};


int main() {
	Insurance insurance;
	int money;
	int incomeTax;

	cout << "연봉이 얼마인가요? : ";
	cin >> money;
	cout << "소득세가 얼마인가요? : ";
	cin >> incomeTax;

	money = (money / YEAR) - TAXFREE;

	money = money - insurance.FinalInsuranceCalculate(money, incomeTax);
	
	cout << "월 수령액 : " << money + TAXFREE << endl;

	return 0;
}