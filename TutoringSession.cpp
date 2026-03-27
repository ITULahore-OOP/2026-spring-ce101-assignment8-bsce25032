#include "TutoringSession.h"
#include "TeachingAssistant.h"   // ✅ REQUIRED
#include "Student.h"             // ✅ REQUIRED
#include <iostream>              // ✅ REQUIRED
using namespace std;

TutoringSession::TutoringSession() {
    sessionID = 0;
    durationMinutes = 0;
    ta = nullptr;
    student = nullptr;
}
TutoringSession::TutoringSession(int sessionID, double durationMinutes, TeachingAssistant* ta, Student* student) {
    this->sessionID = sessionID;
    this->durationMinutes = durationMinutes;
    this->ta = ta;
    this->student = student;
}
double TutoringSession::getDuration() {
    return durationMinutes;
}
void TutoringSession::displaySession() {
    cout << "Session ID: " << sessionID << ", Duration: " << durationMinutes << " minutes, TA: " << ta->getName() << ", Student: " << student->getName() << endl;
}
TutoringSession TutoringSession::operator+(const TutoringSession& other) {
    return TutoringSession(999, durationMinutes + other.durationMinutes, ta, student);
}
bool operator>(TutoringSession s1, TutoringSession s2) {
    return s1.getDuration() > s2.getDuration();
}