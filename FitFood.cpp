#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct User {
    int age;
    string gender;
    double weight;
    double height;
    string goal;
    string disease;
    int activityLevel;
};

struct UserFoodInfo {
    double dailyCalories;
    double dailyCarbs;
    double dailyProtein;
    double dailyFat;
};

void Input_user_information(User& user) {
    cout << "나이: ";
    cin >> user.age;

    cout << "성별 (남/여): ";
    cin >> user.gender;

    cout << "체중 (kg): ";
    cin >> user.weight;

    cout << "신장 (cm): ";
    cin >> user.height;

    cout << "식단 목표 (L(체중 감소), M(체중 유지), G(체중 증가)): ";
    cin >> user.goal;

    cout << "질병 (당뇨, 신장질환, 암, 해당없음): ";
    cin >> user.disease;

    cout << "평소 활동 수준 (1~4): ";
    cin >> user.activityLevel;
}

void calculate_titer(const User& user, UserFoodInfo& foodInfo) {
    // 적정 섭취 칼로리 계산
    if (user.gender == "남") {
        foodInfo.dailyCalories = (66 + (13.7 * user.weight) + (5 * user.height) - (6.75 * user.age)) * 1.55;
    }
    else if (user.gender == "여") {
        foodInfo.dailyCalories = (655 + (9.6 * user.weight) + (1.8 * user.height) - (4.7 * user.age)) * 1.55;
    }

    // 식단 목표에 따라 조정
    if (user.goal == "L") {
        foodInfo.dailyCalories -= 500;
    }
    else if (user.goal == "G") {
        foodInfo.dailyCalories += 500;
    }

    // 영양소 계산
    foodInfo.dailyCarbs = foodInfo.dailyCalories * 55 / 100;
    foodInfo.dailyProtein = foodInfo.dailyCalories * 25 / 100;
    foodInfo.dailyFat = foodInfo.dailyCalories * 20 / 100;

    if (user.disease == "당뇨") {
        foodInfo.dailyCarbs -= 50;
    }
    else if (user.disease == "신장질환") {
        foodInfo.dailyProtein -= 20;
    }
    else if (user.disease == "암") {
        foodInfo.dailyProtein += 20;
    }
}

void generate_exerciseplan(const User& user) {
    cout << "=== 운동 종목 추천 ===\n";

    if (user.activityLevel == 1) {
        cout << "걷기 : 낮은 강도의 운동으로, 일상 생활에 쉽게 통합할 수 있는 운동입니다. 우선 꾸준히 걷는 것 부터 시작해보세요!\n";
    }
    else if (user.activityLevel == 2) {
        cout << "1. 러닝 : 보통 정도의 활동 수준을 가진 당신에게 러닝은 유용한 유산소 운동입니다. 러닝을 통해 심혈관 기능과 체력을 향상시켜보세요!\n";
        cout << "2. 수영 : 수영은 관절에 부담을 주지 않으면서 전신 근육을 고르게 강화시킬 수 있는 유용한 운동입니다!\n";
    }
    else if (user.activityLevel == 3) {
        cout << "웨이트 트레이닝 : 비교적 높은 활동 수준을 유지하고 조금 더 발전된 신체를 가지기 위해서는 고강도 운동이 필요합니다. 주기적인 웨이트 트레이닝으로 신체를 업그레이드 해보세요!\n";
    }
    else if (user.activityLevel == 4) {
        cout << "기능성 운동 : 이미 높은 활동 수준을 보유하고 계신 당신은 신체의 속근육, 밸런스를 발전시키기 위한 요가나 필라테스와 같은 기능성 운동이 도움이 될 수 있습니다. 신체의 기반을 다시 한번 점검해보세요!\n";
    }

    cout << "\n";
}

void display_disease_tips(const string& disease) {
    // 질병에 따른 팁을 출력
    if (disease == "당뇨") {
        cout << "당뇨 환자의 경우, 탄수화물 섭취를 관리하여야 합니다. 정기적이고 규칙적인 식사가 중요하며, 식사 일정의 계획이 아주 중요합니다. 과도한 신체활동은 혈당을 급격하게 떨어뜨릴 수 있으므로, 운동 강도를 적절히 조절해야 합니다.\n";
    }
    else if (disease == "신장질환") {
        cout << "신장질환 환자의 경우, 단백질 섭취를 제한해야 할 수 있습니다. 신장 기능이 감소하면서 피로가 증가할 수 있으므로 저강도 신체활동을 위주로 해주는 것이 좋습니다.\n";
    }
    else if (disease == "암") {
        cout << "암 환자의 경우, 영양 섭취를 유지하는 것이 중요합니다. 단백질 섭취를 증가시켜 근육 손실을 최소화하고, 치료에 대비합니다. 치료와 상태 경과에 따라 운동 계획을 수립하는 것이 좋습니다.\n";
    }

    cout << "\n";
}

int main() {
    User user;
    UserFoodInfo foodInfo;

    Input_user_information(user);
    calculate_titer(user, foodInfo);

    cout << "\n=== 일일 적정 섭취 영양소 ===\n";
    cout << "칼로리: " << foodInfo.dailyCalories << " kcal\n";
    cout << "탄수화물: " << foodInfo.dailyCarbs << " g\n";
    cout << "단백질: " << foodInfo.dailyProtein << " g\n";
    cout << "지방: " << foodInfo.dailyFat << " g\n\n";

    generate_exerciseplan(user);

    if (user.disease != "해당없음") {
        cout << "=== 질병에 따른 팁 ===\n";
        display_disease_tips(user.disease);
    }

    return 0;
}
