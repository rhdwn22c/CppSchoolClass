#include <iostream>
using namespace std;
#define YEAR 12
#define TAXFREE 100000

class Insurance {
public:
	float nationalPension = 0.045;
	float healthInsurance = 0.03495;
	float longTermCareInsurance = 0.1227;
	float employmentInsurance = 0.009;
	float localIncomeTax = 0.1;

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
};


int main() {
	Insurance insurance;
	int money;
	int incomeTax;

	cout << "연봉이 얼마인가요? : ";
	cin >> money;
	cout << "소득세가 얼마인가요? : ";
	cin >> incomeTax;

	money = (money / YEAR) - (TAXFREE * 2);

	cout << money << endl;
	cout << insurance.NationalPensionCalculate(money) << endl;
	cout << insurance.HealthInsuranceCalculate(money) << endl;
	cout << insurance.LongTermCareInsuranceCalculate(money) << endl;
	cout << insurance.EmploymentInsuranceCalculate(money) << endl;
	cout << incomeTax << endl;
	cout << insurance.LocalIncomeTaxCalculate(incomeTax) << endl;

	money = money - insurance.NationalPensionCalculate(money) - insurance.HealthInsuranceCalculate(money) - insurance.LongTermCareInsuranceCalculate(money) - insurance.EmploymentInsuranceCalculate(money) - incomeTax - insurance.LocalIncomeTaxCalculate(incomeTax);
	
	cout << "월 수령액 : " << money + (TAXFREE * 2) << endl;

	return 0;
}