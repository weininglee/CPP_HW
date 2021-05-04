#pragma once
#include <iostream>
using namespace std;
void rec(int* arrayPtr, int curStep, int start, int ELEMENTS_FOR_COMBINATION, int DLEMENTS_FOR_CHOICE);
int step[100];

void PrintCombination(int* arrayPtr, int ELEMENTS_FOR_COMBINATION, int DLEMENTS_FOR_CHOICE) {
    rec(arrayPtr, 0, 0, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);
}

void rec(int* arrayPtr, int curStep, int start, int ELEMENTS_FOR_COMBINATION, int DLEMENTS_FOR_CHOICE) {
    int j;
    if (curStep == DLEMENTS_FOR_CHOICE) {
        for (int i = 0; i < DLEMENTS_FOR_CHOICE - 1; i++) {
            cout << arrayPtr[step[i]] << " ";
        }
        cout << arrayPtr[step[DLEMENTS_FOR_CHOICE - 1]] << endl;
    }
    else {
        for (j = start; j < ELEMENTS_FOR_COMBINATION; j++) {
            step[curStep] = j;
            rec(arrayPtr, curStep + 1, j + 1, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);
        }
    }
}