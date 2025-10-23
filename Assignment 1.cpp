// ================= START CODE =================
// File: student_records.cpp
//
// GITHUB REPO LINK (paste your repo here):
//  https://github.com/afiqahbariza/student-records
//
// Grading system (5 GRED SAHAJA - CONFIRMED):
// 75 – 100  = A  → 4.00
// 60 – 74   = B  → 3.00
// 45 – 59   = C  → 2.00
// 40 – 44   = D  → 1.00
// < 39      = F  → 0.00
// ===============================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_STUDENTS = 10;
const int MAX_SUBJECTS = 5;

struct Subject {
    string name;
    int credit;
    int mark;
    string grade;
    double gradePoint;
};

struct Student {
    string name;
    int age;
    Subject subjects[MAX_SUBJECTS];
    int subjectCount;
    double cpa;
};

pair<string, double> getGradePoint(int mark) {
    if (mark >= 75) return make_pair("A", 4.00);
    else if (mark >= 60) return make_pair("B", 3.00);
    else if (mark >= 45) return make_pair("C", 2.00);
    else if (mark >= 40) return make_pair("D", 1.00);
    else return make_pair("F", 0.00);
}

void computeGrade(Subject &sub) {
    auto gp = getGradePoint(sub.mark);
    sub.grade = gp.first;
    sub.gradePoint = gp.second;
}

double computeCPA(const Student &s) {
    double total = 0;
    int creditSum = 0;
    for (int i = 0; i < s.subjectCount; i++) {
        total += s.subjects[i].gradePoint * s.subjects[i].credit;
        creditSum += s.subjects[i].credit;
    }
    return (creditSum == 0) ? 0 : total / creditSum;
}

int main() {
    Student students[MAX_STUDENTS];
    int n;

    cout << "Enter number of students (max 10): ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\n--- Student " << i + 1 << " ---\n";
        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "Age: ";
        cin >> students[i].age;

        cout << "Number of subjects (max 5): ";
        cin >> students[i].subjectCount;
        cin.ignore();

        for (int j = 0; j < students[i].subjectCount; j++) {
            cout << "\nSubject " << j + 1 << " name: ";
            getline(cin, students[i].subjects[j].name);

            cout << "Credit: ";
            cin >> students[i].subjects[j].credit;

            do {
                cout << "Mark (0-100): ";
                cin >> students[i].subjects[j].mark;
            } while (students[i].subjects[j].mark < 0 || students[i].subjects[j].mark > 100);

            computeGrade(students[i].subjects[j]);
            cin.ignore();
        }
        students[i].cpa = computeCPA(students[i]);
    }

    cout << "\n\n===== STUDENT SUMMARY =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\nName: " << students[i].name
             << " | Age: " << students[i].age
             << " | CPA: " << fixed << setprecision(2) << students[i].cpa << "\n";

        for (int j = 0; j < students[i].subjectCount; j++) {
            cout << "  " << j + 1 << ") "
                 << students[i].subjects[j].name
                 << " | Credit: " << students[i].subjects[j].credit
                 << " | Mark: " << students[i].subjects[j].mark
                 << " | Grade: " << students[i].subjects[j].grade << "\n";
        }
    }

    return 0;
}