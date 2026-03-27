#ifndef TUTORINGSESSION_H
#define TUTORINGSESSION_H
class TeachingAssistant;
class Student;
#include <iostream>
using namespace std;

class TutoringSession {
private:
    int sessionID;
    double durationMinutes;
    TeachingAssistant* ta;
    Student* student;

public:
    TutoringSession();
    TutoringSession(int sessionID, double durationMinutes, TeachingAssistant* ta, Student* student);
    double getDuration();
    void displaySession();
    TutoringSession operator+(const TutoringSession& other);
    friend bool operator>(TutoringSession s1, TutoringSession s2);
};

#endif