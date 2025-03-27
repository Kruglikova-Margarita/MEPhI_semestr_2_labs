#include <stdio.h>
#include <stdlib.h>
#include "../numbers/item.h"
#include "../numbers/real/real.h"
#include "../numbers/complex/complex.h"
#include "../errorTypes/errors.h"
#include "../matrix/matrix.h"
#include "menu/menu.h"
#include "input/input.h"
#include "actions/actions.h"

int main() {
    printMenu();
    int action = chooseAction();
    if (exitLabel.code != 0) {
        printf("Error: %s\n", exitLabel.message);
        if (exitLabel.code == 8) return exitLabel.code;
    }
    while (action != 9) {
        switch(action) {
            case(1):
                printf("==Add up two numbers==\n");
                action1();
                if (exitLabel.code != 0) {
                    printf("Error: %s\n", exitLabel.message);
                    if (exitLabel.code == 8) return exitLabel.code;
                }
                break;
            case(2):
                printf("==Multiply two numbers==\n");
                action2();
                if (exitLabel.code != 0) {
                    printf("Error: %s\n", exitLabel.message);
                    if (exitLabel.code == 8) return exitLabel.code;
                }
                break;
            case(3):
                printf("==Find the difference between two numbers==\n");
                action3();
                if (exitLabel.code != 0) {
                    printf("Error: %s\n", exitLabel.message);
                    if (exitLabel.code == 8) return exitLabel.code;
                }
                break;
            case(4):
                printf("==Find the quotient between two numbers==\n");
                action4();
                if (exitLabel.code != 0) {
                    printf("Error: %s\n", exitLabel.message);
                    if (exitLabel.code == 8) return exitLabel.code;
                }
                break;
            case(5):
                printf("==Compare two numbers==\n");
                action5();
                if (exitLabel.code != 0) {
                    printf("Error: %s\n", exitLabel.message);
                    if (exitLabel.code == 8) return exitLabel.code;
                }
                break;
            case(6):
                printf("==Add up two matrix==\n");
                action6();
                if (exitLabel.code != 0) {
                    printf("Error: %s\n", exitLabel.message);
                    if (exitLabel.code == 8) return exitLabel.code;
                }
                break;
            case(7):
                printf("==Multiply two matrix==\n");
                action7();
                if (exitLabel.code != 0) {
                    printf("Error: %s\n", exitLabel.message);
                    if (exitLabel.code == 8) return exitLabel.code;
                }
                break;
            case(8):
                printf("==Transpose matrix==\n");
                action8();
                if (exitLabel.code != 0) {
                    printf("Error: %s\n", exitLabel.message);
                    if (exitLabel.code == 8) return exitLabel.code;
                }
                break;
        }
        printf("==End of action execution==\n");
        if (exitLabel.code != 8) {
            exitLabel.code = 0;
            exitLabel.message = NULL;
        }
        action = chooseAction();
        if (exitLabel.code != 0) {
            printf("Error: %s\n", exitLabel.message);
            return exitLabel.code;
        }
    }

    return exitLabel.code;
}