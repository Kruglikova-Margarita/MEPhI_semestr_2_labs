#include <iostream>
#include "SequenceClasses/Sequence.h"
using namespace std;
int main() {
    int ar[3] = {1, 2, 3};
    Sequence<int> *s1 = new ArraySequence<int>(ar, 3);
    s1->Print();
    cout << "\n";
    

    return 0;
}