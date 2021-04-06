#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*return true for valid input, false for invalid input*/
bool check(char* charInput)
{
    int correct[9] = { 1,2,3,4,5,6,7,8,9 };

    vector<int> intInput;

    //convert char numbers into int
    for (int i = 0; i < 9; i++){
        intInput.push_back(charInput[i] - '0');
    }

    //arrange the int from small to big
    sort(intInput.begin(), intInput.end());

    for (int j = 0; j < 9; j++){
        if (intInput[j] == correct[j])
            continue;
        else
            return false;
    }

    return true;
}

int main()
{
    string input;
    vector<std::string> board;

    int total = 0; //"total" to count how many lines in total
    int start = 0; //"start" to mark the start of each sudoku board
    int row = 0; //"row" to act as the index of each line in the sudoku board


    while (getline(cin, input)) //get all the inputs
    {
        if (input.empty() == true)
            continue;
        else
        {
            board.push_back(input);
            total++;
        }
    }

    int boardNum = total / 9; //count how many sudoku board

    for (int count = 0; count < boardNum; count++){
        bool valid = true;

        //check if all rows in a sudoku board are valid
        for (row = start; row < start + 9; row++){
            char oneRow[9];
            for (int i = 0, j = 0; i < 17; i += 2, j++){
                oneRow[j] = board[row][i];
            }

            if (check(oneRow) == true){
                valid = true;
            }
            else{
                valid = false;
                goto output;
            }
        }

        //check if all columns in a sudoku board are valid
        for (int i = 0; i < 17; i += 2){
            char oneColumn[9];

            for (int j = 0, row = start; row < start + 9; row++, j++){
                oneColumn[j] = board[row][i];
            }

            if (check(oneColumn) == true){
                valid = true;
            }
            else{
                valid = false;
                goto output;
            }
        }

        //check if all squares in a sudoku board are valid
        for (row = start; row < start + 9; row += 3){
            for (int column = 0; column < 13; column += 6){
                char oneSquare[9];

                for (int r = row, i = 0; r < row + 3; r++){
                    for (int c = column; c < column + 5; c += 2){
                        oneSquare[i] = board[r][c];
                        i++;
                    }
                }

                if (check(oneSquare) == true){
                    valid = true;
                }
                else{
                    valid = false;
                    goto output;
                }
            }
        }

    output:
        if (valid == true)
            cout << "True" << endl;
        else
            cout << "False" << endl;

        start += 9;
    }
}