#include <string>

#ifndef student_h
#define student_h

using namespace std;

class Student {
private:
    int id;
    string firstName;
    string middleName;
    string lastName;
    string group;

public:
    Student() {}

    Student(int newId, string newFirstName, string newMiddleName, string newLastName, string newGroup) {
        id = newId;
        firstName = string(newFirstName);
        middleName = string(newMiddleName);
        lastName = string(newLastName);
        group = string(newGroup);
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

    string GetGroup() const noexcept {
        return group;
    }

    bool operator==(const Student &cmpStudent) const noexcept {
        int cmpID = cmpStudent.GetID();
        string cmpFirstName = cmpStudent.GetFirstName();
        string cmpMiddleName = cmpStudent.GetMiddleName();
        string cmpLastName = cmpStudent.GetLastName();
        string cmpGroup = cmpStudent.GetGroup();
        if ((id == cmpID) && (firstName == cmpFirstName) && (middleName == cmpMiddleName) && (lastName == cmpLastName) && (group == cmpGroup)) return true;
        return false;
    }

};

#endif