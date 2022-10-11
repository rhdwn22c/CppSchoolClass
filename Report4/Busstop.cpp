#include <iostream>
#include <ctime>
using namespace std;

// 기본적인 첫차 막차 시간 정보 등 기입
const int FirstBusTime = 6; // hour
const int LastBusTime = 22; // hour
const int DistanceToBus = 470; // m
const int BusTimeInterval = 20; // minute
const int WithinReach = 4; // km/h


class NowTime { // 시간 계산
public:
	int walkHour;
	int walkMinute;

	time_t nowWalkTime; // time_t 타입 선언
	struct tm pWalkTime; // tm 구조체 선언

	void SetTime() {
		nowWalkTime = time(NULL);
		localtime_s(&pWalkTime, &nowWalkTime); // 현재 시간 계산해 주기 (localtime은 VS에서 에러뜨기때문에 localtime_s로 사용)

		walkHour = pWalkTime.tm_hour; // 현재 시 넣기
		walkMinute = pWalkTime.tm_min; // 현재 분 넣기

		if (walkHour > 12) { // 12시간 계산법으로 A.M 과 P.M 구분하기
			cout << "현재 시각 : " << walkHour - 12 << " : " << walkMinute << " P.M" << endl;
		}
		else {
			cout << "현재 시각 : " << walkHour << " : " << walkMinute << " A.M" << endl;
		}
	}

};

class GetOutTime {
public:
	NowTime nowTime;

	int getOutWalkHour;
	int getOutWalkMinute;

	int arriveBusstopTime = DistanceToBus / (WithinReach * 1000 / 60); // 7.05 -> 7분 3초 (int형이므로 초 삭제)

	int ToArriveGetOutArrange(int walkMinute) { // arriveBusstopTime 변수를 바탕으로 출발 시간 정해주기
		if (walkMinute + arriveBusstopTime >= BusTimeInterval * 3) { // BusTimeInterval * 3 (60)분이 넘어가면 시간 정리 해주기 
			getOutWalkHour++;
			return BusTimeInterval - arriveBusstopTime;
		}
		else if (walkMinute + arriveBusstopTime >= BusTimeInterval * 2) {
			return BusTimeInterval * 3 - arriveBusstopTime;
		}
		else if (walkMinute + arriveBusstopTime >= BusTimeInterval && walkMinute + arriveBusstopTime < BusTimeInterval * 2) {
			return BusTimeInterval * 2 - arriveBusstopTime;
		}
		else if (walkMinute + arriveBusstopTime < BusTimeInterval) {
			return BusTimeInterval - arriveBusstopTime;
		}
		else {
			return walkMinute - arriveBusstopTime;
		}
	}

	void GetOutTimeToBus(int walkHour, int walkMinute) { // 나가야 할 시간 구하기
		getOutWalkHour = walkHour;
		getOutWalkMinute = walkMinute;

		if (getOutWalkHour < FirstBusTime || getOutWalkHour > LastBusTime) {
			cout << "6 : 13 A.M에 출발" << endl; // 초 계산 X
		}
		else if (getOutWalkHour > 12) {
			cout << getOutWalkHour - 12 << " : " << ToArriveGetOutArrange(walkMinute) << " P.M" << "에 출발 ";
		}
		else {
			cout << getOutWalkHour << " : " << ToArriveGetOutArrange(walkMinute) << " A.M" << "에 출발 ";
		}
	}

};

int main() {
	NowTime nowTime;
	GetOutTime getOutTime;

	nowTime.SetTime();
	getOutTime.GetOutTimeToBus(nowTime.walkHour, nowTime.walkMinute);
}
