#include <iostream>
using namespace std;

class CPerson {
public:
	CPerson() : age(0) {
		cout << "CPerson()" << endl;
	}

	int GetAge() {
		return age;
	}

	void SetAge(int param) {
		age = param;
	}

protected:
	void Print() {
		cout << "CPerson::Print()" << endl;
	}

private:
	int age;
};

class CStudent : public CPerson {
public:
	CStudent() {
		cout << "CStudent()" << endl;
	}

	void TestFunc() {
		Print();
		SetAge(45);
		cout << CPerson::GetAge() << endl;
	}
};

int main() {
	CStudent student;

	student.SetAge(10);
	cout << student.GetAge() << endl;

	student.TestFunc();
}