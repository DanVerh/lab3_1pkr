#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum Spec { KN, IT, MATH, PH, TR };
string strSpec[] = { "����'����� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

struct Student {
    string lname;
    int kurs;
    Spec spec;
    double phgr;
    double mgr;
    union {
        double itgr;
        double numbgr;
        double pedgr;
    };
};

void Create(Student* s, const int amSt);
void Print(Student* p, const int N);
int Count(Student* s, const int amSt);
double CountPerc(Student* s, const int amSt);

int main() {
    setlocale(LC_ALL, "Russian");

    int amSt;
    cout << "ʳ������ ��������: ";
    cin >> amSt;
    Student* s = new Student[amSt];

    Create(s, amSt);
    Print(s, amSt);
    cout << "ʳ������ ��������, �� ������� ����� �� �� ������: " << Count(s, amSt);
    cout << endl;
    cout << "³������ ��������, � ���� ������� ��� ����� 4: " << CountPerc(s, amSt);
    cout << endl;

    return 0;
}


void Create(Student* s, const int amSt) {
    int sp;
    for (int i = 0; i < amSt; i++) {
        cout << "�������: ";
        cin >> s[i].lname;
        cout << "����: ";
        cin >> s[i].kurs;
        cout << "������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "������ � ������: ";
        cin >> s[i].phgr;
        cout << "������ � ����������: ";
        cin >> s[i].mgr;
        if (s[i].spec == 0) {
            cout << "������ � �������������: ";
            cin >> s[i].itgr;
        }
        else if (s[i].spec == 1) {
            cout << "������ � ��������� ������: ";
            cin >> s[i].numbgr;
        }
        else {
            cout << "������ � ���������: ";
            cin >> s[i].pedgr;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N) {
    cout << "===========================================================================================" << endl;
    cout << "| No | ������� | ���� |        ������������        | Գ���� | ���������� | ����� ������ |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(3) << right << i + 1 << "";
        cout << "| " << setw(9) << right << p[i].lname
            << "| " << setw(5) << right << p[i].kurs
            << "| " << setw(28) << strSpec[p[i].spec]
            << "| " << setw(7) << right << p[i].phgr
            << "| " << setw(11) << right << p[i].mgr;
        if (p[i].spec == 0) {
            cout << "| " << setw(13) << right << p[i].itgr;
        }
        else if (p[i].spec == 1) {
            cout << "| " << setw(13) << right << p[i].numbgr;
        }
        else {
            cout << "| " << setw(13) << right << p[i].pedgr;
        }
        cout << "|";
        cout << endl;
    }
    cout << "===========================================================================================" << endl;
    cout << endl;
}

int Count(Student* s, const int amSt) {
    int count = 0;
    for (int i = 0; i < amSt; i++) {
        if (s[i].phgr > 3 && s[i].mgr > 3 && (s[i].itgr > 3 || s[i].numbgr > 3 || s[i].pedgr > 3))
            count++;
    }
    return count;
}

double CountPerc(Student* s, const int amSt) {
    int count = 0;
    double result;
    for (int i = 0; i < amSt; i++) {
        double avg = 0;
        if (s[i].spec == 0)
            avg = (s[i].phgr + s[i].mgr + s[i].itgr) / 3.0;
        else if (s[i].spec == 1)
            avg = (s[i].phgr + s[i].mgr + s[i].numbgr) / 3.0;
        else
            avg = (s[i].phgr + s[i].mgr + s[i].pedgr) / 3.0;

        if (avg < 4)
            count++;
    }

    result = (count * 1.0 / amSt * 1.0) * 100.0;
    return result;
}
