#include <string>

#ifndef teacher_h
#define teacher_h

using namespace std;

class Teacher {
private:
    int id;
    string firstName;
    string middleName;
    string lastName;
    string discipline;

public:
    Teacher() {}

    Teacher(int newId, string newFirstName, string newMiddleName, string newLastName, string newDiscipline) {
        id = newId;
        firstName = string(newFirstName);
        middleName = string(newMiddleName);
        lastName = string(newLastName);
        discipline = newDiscipline;
    }

    int GetID() const noexcept {
        return id;
    }

    string GetFirstName() const noexcept {
        return firstName;
    }

    string GetMiddleName() const noexcept {
        return middleName;
    }

    string GetLastName() const noexcept {
        return lastName;
    }

    string GetDiscipline() const noexcept {
        return discipline;
    }

    bool operator==(const Teacher &cmpTeacher) {
        int cmpID = cmpTeacher.GetID();
        string cmpFirstName = cmpTeacher.GetFirstName();
        string cmpMiddleName = cmpTeacher.GetMiddleName();
        string cmpLastName = cmpTeacher.GetLastName();
        string cmpDiscipline = cmpTeacher.GetDiscipline();
        if ((id == cmpID) && (firstName == cmpFirstName) && (middleName == cmpMiddleName) && (lastName == cmpLastName) && (discipline == cmpDiscipline)) return true;
        return false;
    }
};

#endif