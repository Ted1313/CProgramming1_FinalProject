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
    cout << "����: ";
    cin >> user.age;

    cout << "���� (��/��): ";
    cin >> user.gender;

    cout << "ü�� (kg): ";
    cin >> user.weight;

    cout << "���� (cm): ";
    cin >> user.height;

    cout << "�Ĵ� ��ǥ (L(ü�� ����), M(ü�� ����), G(ü�� ����)): ";
    cin >> user.goal;

    cout << "���� (�索, ������ȯ, ��, �ش����): ";
    cin >> user.disease;

    cout << "��� Ȱ�� ���� (1~4): ";
    cin >> user.activityLevel;
}

void calculate_titer(const User& user, UserFoodInfo& foodInfo) {
    // ���� ���� Į�θ� ���
    if (user.gender == "��") {
        foodInfo.dailyCalories = (66 + (13.7 * user.weight) + (5 * user.height) - (6.75 * user.age)) * 1.55;
    }
    else if (user.gender == "��") {
        foodInfo.dailyCalories = (655 + (9.6 * user.weight) + (1.8 * user.height) - (4.7 * user.age)) * 1.55;
    }

    // �Ĵ� ��ǥ�� ���� ����
    if (user.goal == "L") {
        foodInfo.dailyCalories -= 500;
    }
    else if (user.goal == "G") {
        foodInfo.dailyCalories += 500;
    }

    // ����� ���
    foodInfo.dailyCarbs = foodInfo.dailyCalories * 55 / 100;
    foodInfo.dailyProtein = foodInfo.dailyCalories * 25 / 100;
    foodInfo.dailyFat = foodInfo.dailyCalories * 20 / 100;

    if (user.disease == "�索") {
        foodInfo.dailyCarbs -= 50;
    }
    else if (user.disease == "������ȯ") {
        foodInfo.dailyProtein -= 20;
    }
    else if (user.disease == "��") {
        foodInfo.dailyProtein += 20;
    }
}

void generate_exerciseplan(const User& user) {
    cout << "=== � ���� ��õ ===\n";

    if (user.activityLevel == 1) {
        cout << "�ȱ� : ���� ������ �����, �ϻ� ��Ȱ�� ���� ������ �� �ִ� ��Դϴ�. �켱 ������ �ȴ� �� ���� �����غ�����!\n";
    }
    else if (user.activityLevel == 2) {
        cout << "1. ���� : ���� ������ Ȱ�� ������ ���� ��ſ��� ������ ������ ����� ��Դϴ�. ������ ���� ������ ��ɰ� ü���� �����Ѻ�����!\n";
        cout << "2. ���� : ������ ������ �δ��� ���� �����鼭 ���� ������ ���� ��ȭ��ų �� �ִ� ������ ��Դϴ�!\n";
    }
    else if (user.activityLevel == 3) {
        cout << "����Ʈ Ʈ���̴� : ���� ���� Ȱ�� ������ �����ϰ� ���� �� ������ ��ü�� ������ ���ؼ��� ���� ��� �ʿ��մϴ�. �ֱ����� ����Ʈ Ʈ���̴����� ��ü�� ���׷��̵� �غ�����!\n";
    }
    else if (user.activityLevel == 4) {
        cout << "��ɼ� � : �̹� ���� Ȱ�� ������ �����ϰ� ��� ����� ��ü�� �ӱ���, �뷱���� ������Ű�� ���� �䰡�� �ʶ��׽��� ���� ��ɼ� ��� ������ �� �� �ֽ��ϴ�. ��ü�� ����� �ٽ� �ѹ� �����غ�����!\n";
    }

    cout << "\n";
}

void display_disease_tips(const string& disease) {
    // ������ ���� ���� ���
    if (disease == "�索") {
        cout << "�索 ȯ���� ���, ź��ȭ�� ���븦 �����Ͽ��� �մϴ�. �������̰� ��Ģ���� �Ļ簡 �߿��ϸ�, �Ļ� ������ ��ȹ�� ���� �߿��մϴ�. ������ ��üȰ���� ������ �ް��ϰ� ����߸� �� �����Ƿ�, � ������ ������ �����ؾ� �մϴ�.\n";
    }
    else if (disease == "������ȯ") {
        cout << "������ȯ ȯ���� ���, �ܹ��� ���븦 �����ؾ� �� �� �ֽ��ϴ�. ���� ����� �����ϸ鼭 �Ƿΰ� ������ �� �����Ƿ� ������ ��üȰ���� ���ַ� ���ִ� ���� �����ϴ�.\n";
    }
    else if (disease == "��") {
        cout << "�� ȯ���� ���, ���� ���븦 �����ϴ� ���� �߿��մϴ�. �ܹ��� ���븦 �������� ���� �ս��� �ּ�ȭ�ϰ�, ġ�ῡ ����մϴ�. ġ��� ���� ����� ���� � ��ȹ�� �����ϴ� ���� �����ϴ�.\n";
    }

    cout << "\n";
}

int main() {
    User user;
    UserFoodInfo foodInfo;

    Input_user_information(user);
    calculate_titer(user, foodInfo);

    cout << "\n=== ���� ���� ���� ����� ===\n";
    cout << "Į�θ�: " << foodInfo.dailyCalories << " kcal\n";
    cout << "ź��ȭ��: " << foodInfo.dailyCarbs << " g\n";
    cout << "�ܹ���: " << foodInfo.dailyProtein << " g\n";
    cout << "����: " << foodInfo.dailyFat << " g\n\n";

    generate_exerciseplan(user);

    if (user.disease != "�ش����") {
        cout << "=== ������ ���� �� ===\n";
        display_disease_tips(user.disease);
    }

    return 0;
}
