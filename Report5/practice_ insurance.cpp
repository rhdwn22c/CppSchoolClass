#include <iostream>
using namespace std;
#define YEAR 12

class Insurance {
public:
	float NationalPension = 0.045;
	float HealthInsurance = 0.03495;
	float LongTermCareInsurance = 0.1227;
	float EmploymentInsurance = 0.009;

	int NationalPensionCalculate(int money) {
		return money / YEAR * NationalPension;
	}

	int HealthInsuranceCalculate(int money) {
		return money / YEAR * HealthInsurance;
	}

	int LongTermCareInsuranceCalculate(int money) {
		return HealthInsuranceCalculate(money) * LongTermCareInsurance;
	}

	int EmploymentInsuranceCalculate(int money) {
		return money / YEAR * EmploymentInsurance;
	}
};


int main() {
	Insurance insurance;
	int money;

	cout << "연봉이 얼마인가요? : ";
	cin >> money;
    
	cout << insurance.NationalPensionCalculate(money) << endl;
	cout << insurance.HealthInsuranceCalculate(money) << endl;
	cout << insurance.LongTermCareInsuranceCalculate(money) << endl;
	cout << insurance.EmploymentInsuranceCalculate(money) << endl;

	money = (money / YEAR) - insurance.NationalPensionCalculate(money) - insurance.HealthInsuranceCalculate(money) - insurance.LongTermCareInsuranceCalculate(money) - insurance.EmploymentInsuranceCalculate(money);
	
	cout << "월 수령액 : " << money << endl;

	return 0;
}