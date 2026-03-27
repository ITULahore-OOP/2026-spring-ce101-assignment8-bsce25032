#include <iostream>
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"
#include "Department.h"
using namespace std;

int main() {
    Department dept("Computer Science");
    Student* students[50];
    TeachingAssistant* tas[50];
    TutoringSession sessions[50];
    int studentCount = 0;
    int taCount = 0;
    int sessionCount = 0;
    int choice;
    do {
        cout << "1. Add Student" << endl;
        cout << "2. Add Staff" << endl;
        cout << "3. Add Teaching Assistant" << endl;
        cout << "4. Display All Members" << endl;
        cout << "5. Create Tutoring Session" << endl;
        cout << "6. Merge Two Sessions (+ operator)" << endl;
        cout << "7. Compare Two Sessions (> operator)" << endl;
        cout << "8. Grade Assignment (TA)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            string name;
            int id;
            double cgpa;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            students[studentCount] = new Student(name, id, cgpa);
            dept.addMember(students[studentCount]);
            studentCount++;
            cout << "Student added" << endl;
        }
        else if (choice == 2) {
            string name, cardID;
            int id, access;
            double salary;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter salary: ";
            cin >> salary;
            cout << "Enter Card ID: ";
            cin >> cardID;
            cout << "Enter Access Level: ";
            cin >> access;
            AccessCard card(cardID, access);
            Staff* st = new Staff(name, id, salary, card);
            dept.addMember(st);
            cout << "Staff added" << endl;
        }
        else if (choice == 3) {
            string name, cardID;
            int id, access, hours;
            double cgpa, salary;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            cout << "Enter salary: ";
            cin >> salary;
            cout << "Enter working hours: ";
            cin >> hours;
            cout << "Enter Card ID: ";
            cin >> cardID;
            cout << "Enter Access Level: ";
            cin >> access;
            AccessCard card(cardID, access);
            tas[taCount] = new TeachingAssistant(name, id, cgpa, salary, card, hours);
            dept.addMember(tas[taCount]);
            taCount++;
            cout << "Teaching Assistant added" << endl;
        }
        else if (choice == 4) {
            dept.displayAllRoles();
        }
        else if (choice == 5) {
            if (studentCount == 0 || taCount == 0) {
                cout << "Need at least 1 student and 1 TA!\n";
                continue;
            }
            int sid;
            double duration;
            int sIndex, tIndex;
            cout << "Enter Session ID: ";
            cin >> sid;
            cout << "Enter Duration (minutes): ";
            cin >> duration;
            cout << "Select Student index (0 to " << studentCount - 1 << "): ";
            cin >> sIndex;
            cout << "Select TA index (0 to " << taCount - 1 << "): ";
            cin >> tIndex;
            sessions[sessionCount] = TutoringSession(sid, duration, tas[tIndex], students[sIndex]);
            sessionCount++;
            cout << "Session created" << endl;
        }
        else if (choice == 6) {
            if (sessionCount < 2) {
                cout << "Need at least 2 sessions!\n";
                continue;
            }
            int a, b;
            cout << "Enter two session indices: ";
            cin >> a >> b;
            TutoringSession merged = sessions[a] + sessions[b];
            merged.displaySession();
        }
        else if (choice == 7) {
            if (sessionCount < 2) {
                cout << "Need at least 2 sessions!\n";
                continue;
            }
            int a, b;
            cout << "Enter two session indices: ";
            cin >> a >> b;
            if (sessions[a] > sessions[b]) {
                cout << "Session " << a << " is longer" << endl;
            }
            else {
                cout << "Session " << b << " is longer" << endl;
            }
        }
        else if (choice == 8) {
            if (taCount == 0) {
                cout << "No TAs available" << endl;
                continue;
            }
            int index;
            cout << "Select TA index (0 to " << taCount - 1 << "): ";
            cin >> index;
            int type;
            cout << "1. Numeric Grade" << endl;
            cout << "2. Letter Grade" << endl;
            cout << "Choose: " << endl;
            cin >> type;

            if (type == 1)
            {
                int score;
                cout << "Enter score: ";
                cin >> score;
                tas[index]->gradeAssignment(score);
            }
            else
            {
                string grade;
                cout << "Enter letter grade: ";
                cin >> grade;
                tas[index]->gradeAssignment(grade);
            }
        }

    } while (choice != 0);
    cout << "Exiting system..." << endl;

    return 0;
}