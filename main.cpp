#include <iostream>

using namespace std;
int sudoku[9][9] =
    {//Solvable Sudoku
     {1, 0, 6, 0, 0, 2, 3, 0, 0},
     {0, 5, 0, 0, 0, 6, 0, 9, 1},
     {0, 0, 9, 5, 0, 1, 4, 6, 2},
     {0, 3, 7, 9, 0, 5, 0, 0, 0},
     {5, 8, 1, 0, 2, 7, 9, 0, 0},
     {0, 0, 0, 4, 0, 8, 1, 5, 7},
     {0, 0, 0, 2, 6, 0, 5, 4, 0},
     {0, 0, 4, 1, 5, 0, 6, 0, 9},
     {9, 0, 0, 8, 7, 4, 2, 1, 0}
     //Solvable Sudoku
     /*
     {0, 0, 9, 0, 4, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 5, 3, 1, 0},
     {0, 6, 1, 0, 0, 8, 0, 5, 0},
     {0, 0, 5, 4, 0, 0, 2, 0, 3},
     {0, 1, 0, 0, 0, 7, 0, 0, 8},
     {0, 8, 0, 0, 0, 0, 7, 6, 0},
     {3, 0, 6, 0, 1, 9, 4, 0, 0},
     {7, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 4, 0, 5, 0, 6, 2, 7}
     */
     /*Unsolvable Sudoku
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 5, 3, 1, 0},
     {0, 6, 1, 0, 0, 8, 0, 5, 0},
     {0, 0, 5, 4, 0, 0, 2, 0, 3},
     {0, 1, 0, 0, 0, 7, 0, 0, 8},
     {0, 8, 0, 0, 0, 0, 7, 6, 0},
     {3, 0, 6, 0, 1, 9, 4, 0, 0},
     {7, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 4, 0, 5, 0, 6, 2, 7}*/
    };
int yCor = 6;
int xCor = 0;
int num = 1;
int noChangeCounter = 0;
int tempArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int checkArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int zeroYCordsArr[9] = {10, 10, 10, 10, 10, 10, 10, 10, 10};
int zeroXCordsArr[9] = {10, 10, 10, 10, 10, 10, 10, 10, 10};
int tempXArray[9] = {10, 10, 10, 10, 10, 10, 10, 10, 10};
int tempYArray[9] = {10, 10, 10, 10, 10, 10, 10, 10, 10};

void checkReplace(int x){
    //check current xArray and current yArray with current tempArray and if only one available then add number to current zeroYCord and zeroXcord
     for (int i = 0; i < 9; i++){
        checkArray[i] = i+1;
     }
     int tempNum = 0;
     int zeroCounter = 0;
     for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (checkArray[i] == tempArray[j]){
                checkArray[i] = 0;
            }
            if (checkArray[i] == tempYArray[j]){
                checkArray[i] = 0;
            }
            if (checkArray[i] == tempXArray[j]){
                checkArray[i] = 0;
            }
        }
     }
     /*
     for (int i = 0; i < 9; i++){
        cout << checkArray[i] << " ";
     }
     cout << "\n";
     cout << "\n";
}*/
    for (int i = 0; i < 9; i++){
        if (checkArray[i] == 0){
            zeroCounter++;
        }
        else if (tempNum == 0 && checkArray != 0){
            tempNum = checkArray[i];
        }
        else {
            //break;
        }
    }
    if (zeroCounter == 8){
        sudoku[zeroYCordsArr[x]][zeroXCordsArr[x]] = tempNum;
        //cout << "Here on:" << tempNum << zeroYCordsArr[x] << zeroXCordsArr[x];
        noChangeCounter = 0;
    }
}
void getXLine(int x){
    for (int i = 0; i < 9; i++){
        tempXArray[i] = sudoku[zeroYCordsArr[x]][i];
        //cout << tempXArray[i] << " ";
    }
    //cout << "\n";
}

void getYLine(int x){
    for (int i = 0; i < 9; i++){
        tempYArray[i] = sudoku[i][zeroXCordsArr[x]];
        //cout << tempYArray[i] << " ";
        //Have function here to start checking things off
    }
    //cout << "\n";
}

void checkSquare(){
    /*for (int i = 0; zeroYCordsArr[i] != 10; i++){
        //cout << zeroYCordsArr[i] << zeroXCordsArr[i] << " ";

    }
    //cout << "\n";*/
    for (int i = 0; zeroYCordsArr[i] != 10; i++){
        getXLine(i);
        getYLine(i);
        //cout << "\n";
        checkReplace(i);
    }
}

void getZeros(){//Function gets the coordinates of the zeros and sends to function
   int x = 0; //Index for position in coordinate array
   for (int i = yCor ; i < yCor+3; i++) {
    for (int j = xCor; j < xCor+3; j++) {
        //cout << sudoku[i][j]<<  " ";
        if (sudoku[i][j] == 0){
            //cout << i << j << " ";
            zeroYCordsArr[x] = i;
            zeroXCordsArr[x] = j;
            x++;
        }
    }
    //cout << "\n";
}
   checkSquare();
}

void sendNum(){ //Function creates array that will contain all numbers that need to be checked.

   int arrayPos = 0;
   for (int i = yCor ; i < yCor+3; i++) {
    for (int j = xCor; j < xCor+3; j++) {
        //cout << sudoku[i][j]<<  " ";
        if (sudoku[i][j] != 0){
            tempArray[arrayPos] = sudoku[i][j];
            arrayPos++;
        }
    }
    //cout << "\n";
}/*
   for (int i = 0; i < 9; i++){
    cout << tempArray[i] << " ";
   }
   cout << "\n";*/
   getZeros();
}

int main()
{

   while (noChangeCounter < 10){
   //int tempArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; Why does this make it not work?????
   int num = 1;
   for (int i = 0; i < 9; i++){
    tempArray[i] = 0;
    zeroYCordsArr[i] = 10;
    zeroXCordsArr[i] = 10;
    tempXArray[i] = 10;
    tempYArray[i] = 10;
    checkArray[i] = i+1;
   }
   sendNum();
   noChangeCounter++;
   if (xCor == 6 && yCor == 6){
    xCor = 0;
    yCor = 0;
   }
   else if(xCor == 6){
    xCor = 0;
    yCor += 3;
   }
   else {
    xCor += 3;
   }
   //cout << yCor << xCor << " ";
}
//sendNum();
int zeroCounter = 0;
for (int i = 0 ; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        if (sudoku[i][j] == 0){
            zeroCounter++;
            break;
        }
    }
}
if (zeroCounter > 0){
    for (int i = 0 ; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << sudoku[i][j]<<  " ";
    }
    cout << "\n";
}
    cout << "\n\n\n";
    cout << "Sudoku could not be solved\n\n";
}
else {
for (int i = 0 ; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        cout << sudoku[i][j]<<  " ";
    }
    cout << "\n";
}
    cout << "\n\n\n";
    cout << "Your sudoku was solved!\n\n";
}
return 0;
}
