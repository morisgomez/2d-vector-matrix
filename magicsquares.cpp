/*
PIC 10A Homework 6, MagicSquares.cpp
Author: Moris Gomez
UID: 705089833
Discussion Section: 5B
Date: 11/18/2022
*/
#include <iostream>
#include <vector>

using namespace std;
/*
-----------------------------------------------
You can define other helper functions here if you want.
*/
bool input_valid(const vector<int> & vec)
{
    int value = vec[0];
    bool flag;
    if (vec.size() == 16) //checks if there are 16 values.
    {
        for (int counter = 1; counter < vec.size(); counter++) //access each element in 1d vector.
        {
            if (value == vec[counter]) //if true, value is a repeat.
            {
                flag = false;
            }
            else //new value is counter.
            {
                value = vec[counter];
                flag = true;
            }
        } //closes for loop.
    }
    else
    {
        flag = false;
    }
    return flag;
}
/*
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
*/
vector<vector<int>> write_vector_to_square(const vector<int> & vec)
{
   vector<vector<int>> square;
    //BELOW CREATES EMPTY NESTED VECTORS TO OUTER VEC.
    vector<int> row1 (4);
    vector<int> row2 (4);
    vector<int> row3 (4);
    vector<int> row4 (4);
    //BELOW ADDS EMPTY NESTED VECTORS TO OUTER VEC.
    square.push_back(row1);
    square.push_back(row2);
    square.push_back(row3);
    square.push_back(row4);
    //BELOW ARE THE 4 ROWS WHICH NEED TO BE PUSHED BACK INTO SQUARE ONCE THEY HAVE VALUES.
    //vec = {1, 2, 3, 4, ||||| 5, 6, 7, 8, ||||| 9, 10, 11, 12, ||||| 13, 14, 15, 16}
    //index={0, 1, 2, 3, ||||| 4, 5, 6, 7, ||||| 8,  9, 10, 11, ||||| 12, 13, 14, 15}
    //BELOW ADDS VALUES FROM VEC TO SQUARE'S ROWS.
    int counter = 0;
    while(counter < vec.size()) //gives access to elements inside vec vector.
    {
        for (int i = 0; i < square.size(); i++) //gives access to each sub vector.
        {
            for (int j = 0; j < square[i].size(); j++) //gives access to the elements within the sub vectors.
            {
                square[i][j] = vec[counter]; //assigns square vale the vec value being accessed.
                counter++;
            } //closes nested for loop;
        } //closes outer loop for selecting inner vector.
    } //closes while loop.
    return square;
} //closes function.
/*
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
*/
bool is_magic_squares(const vector<vector<int>> & vec)
{
    bool flag;
    //rows.
    int row1 = vec[0][0] + vec[0][1] + vec[0][2] + vec[0][3];
    int row2 = vec[1][0] + vec[1][1] + vec[1][2] + vec[1][3];
    int row3 = vec[2][0] + vec[2][1] + vec[2][2] + vec[2][3];
    int row4 = vec[3][0] + vec[3][1] + vec[3][2] + vec[3][3];
    //columns.
    int column1 = vec[0][0] + vec[1][0] + vec[2][0] + vec[3][0];
    int column2 = vec[0][1] + vec[1][1] + vec[2][1] + vec[3][1];
    int column3 = vec[0][2] + vec[1][2] + vec[2][2] + vec[3][2];
    int column4 = vec[0][3] + vec[1][3] + vec[2][3] + vec[3][3];
    //diagonals.
    int diag1 = vec[0][0] + vec[1][1] + vec[2][2] + vec[3][3];
    int diag2 = vec[3][0] + vec[2][1] + vec[1][2] + vec[0][3];

    //BELOW CONDITION CHECKS IF ALL ABOVE VARIABLES HAVE THE SAME VALUE.
    if (row1 == row2 && row2 == row3 && row3 == row4 && row4 == column1 && column1 == column2 && column2 == column3 && column3 == column4 && column4 == diag1 && diag1 == diag2)
    {
        flag = true; //bool becomes true.
    }
    else
    {
        flag = false; //bool becomes false.
    }
    return flag;
} //closes function.

// DO NOT MODIFY THE CODE BELOW THIS LINE
//-----------------------------------------------
int main(){
    int input;
    vector<int> myvector;
    cout << "Please input a sequence of 16 positive integers, ending with Q:" << endl;
    while (cin >> input){
        myvector.push_back(input);
    }

    bool flag1 = input_valid(myvector);

    if (flag1 == 0){
        cout<<"invalid input!"<<endl;
    }else{
        vector<vector<int>> mag_square;
        mag_square = write_vector_to_square(myvector);
        bool flag2 = is_magic_squares(mag_square);
        if (flag2){
            cout << "This is a magic square."<<endl;
        }else{
            cout << "This is not a magic square." << endl;
        }
    }
    return 0;
}

//BELOW ARE CASES TESTED:
//case 1: 16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1 Q ---> is magic square.
//case 2: 2 2 3 5 Q ---> invalid input.
//case 3: 16 3 2 13 5 10 11 8 9 6 7 12 4 15 1 14 Q ---> not a magic square.
//case 4: 53 95 17 33 66 46 74 63 82 12 44 91 62 21 96 90 Q ---> not a magic square.
//case 5: 18 16 65 34 81 75 13 33 82 62 27 92 68 56 29 72 Q ---> not a magic square.
//case 6: 5 3 1 7 9 1 5 8 6 10 2 1 2 8 2 4 Q ---> not a magic square.
//case 7: 8 8 3 1 1 5 8 3 1 9 7 10 9 1 6 10 Q ---> not a magic square.
//case 8: 21 1 12 7 11 8 20 2 5 10 3 23 4 22 6 9 Q ---> is a magic square.
