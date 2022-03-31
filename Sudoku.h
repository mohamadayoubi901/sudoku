/*--sudoku.h-------------------------------------------------------------------
 
 * this header file define the data type sudoku for processing a sudoku game.
 * sudoku data members:
 * int gridDimension: the dimension of the grid
    Dyn2DArray initialGrid:  a pointer to 2d array that contain the data
    int nbrOfErrors: the numbers of error occured
    int nbrOfAllowedErrors: the number of allowed errors
    Dyn2DArray emptyElementsArray:a pointer to a 2 d contains having 1/0 elements
    int nbrOfMissedDigits: number digit to be guessed.
 * 

  */

/* 
 * File:   Sudoku.h
 * Author: moham
 *
 * Created on 5 March 2021, 21:52
 */

#ifndef SUDOKU_H
#define SUDOKU_H
#include <cstdlib>
#include <iostream.h>
typedef int** Dyn2DArray;
//define type Dyn2DArray that is a pointer to a dynamic 2D array of integer

class Sudoku {
public:
    Sudoku(Dyn2DArray initialGrid, int gridDimension);
    /*purpose: create a sudoku object and set its data member 
     * t
     precondition: gridDemension should be a square number 
              initial Grid data should be between 0 and 9
     post condition:
     * int gridDimension set to the taken grid dimention
    Dyn2DArray initialGrid : set to the taken intial grid;
    int nbrOfErrors set to 0;
    int nbrOfAllowedErrors set to 5;
    Dyn2DArray emptyElementsArray set too the return of the called method 
    generateEmptyElementsArray()
    int nbrOfMissedDigits set to return of the called method countMissedValues()
     */
     void runGame();
     /*purpose run a game for the sudoku by prompting the user to enter 
      the elements and acting corresponding to his choice and exit if he solve 
      the sudokuand fill all its element or if he make more erros than the 
      allowed number
      precondition: gridDemension should be a square number initial Grid data 
      should be between 0 and 9 
       
      post-condition:
   the defined data memeber theValue/rowNumber/colNumber 
     are filled by prompting the user to enter it and check if the entered data 
     is valid then set resultOfAddValueInACell to the return of addValueInACell 
      if the resultOfAddValueInACell is 2,3 or 4 display a corresponding error 
      message and increment the nbrOfErrors by 1 
      and if it 0 decreasenbrOfMissedDigits and display a corresponding message;
      if it is 1 display a corresponding message nbrOfErrors and exit if it is 
      higher than nbrOfAllowedErrors and it test the nbrOfMissedDigits 
      and exit if it is 0
      the function test 
     */
private:
    int gridDimension;
    //a integer that represent the grid Dimension of the sudoku array
    Dyn2DArray initialGrid;
    //a pointer to a 2d array the contains the sudoku data
    int nbrOfErrors;
    //an integer that represent the number of error made by the user
    int nbrOfAllowedErrors;
    //an  integer that represent the number of error that the
    //user can make before loosing the game
    Dyn2DArray emptyElementsArray;
    //a pointer to a 2D array with elements having the value 0 if their
//corresponding elements are to be input by the user and the value 1 if their values are set 
//already
    int nbrOfMissedDigits;
    //number of digit to be filled by the user
    
    void displaySudoku();
    /*purpose:displays the filled elements of 
initialGrid in a tabular format. Empty elements  replaced by spaces
     precondition:none
     post condition: display the sudoku array*/
    Dyn2DArray generateEmptyElementsArray();
    /*purpose:t generates 
and returns a dynamic 2D array has the elements equal to 1 if tis corresponding elements in the 
data member initialGrid is different from 0, otherwise equal to 0
     precondition:
     post condition return a pointer to a 2d array having element 1/0*/
    int countMissedValues();
    /*purpose: returns the number of the 0 
values in the data member initialGrid.
     precondition:
     post-condition: return an integer that represent the number to be entered*/
    int addValueInACell(int num, int row, int col);
    /*purpose: store a number in element in the initial grid after checking for 
     his presence if the row column or blocks and return the right number of 
     if it exist before of=r added in a new place or added in a place added
     before by the user
     precondition:
     numb row and col between 1 -9
     * post condition :
     call methods existInRow  existInCol existInBlock  to check the number 
     and the row and column then return 0 or 1 if it added the number or 2.3.4
     if the one the corresponding called method return true
     */
    bool existInRow(int num, int row);
    /*purpose: check if num exist in the same row
     precondition: row  and num between 1 and 9
     post condition return (true if the num exist and false if it does not)*/
    bool existInCol(int num, int col);
    /*purpose: check if num exist in the same column
     precondition: column  and num between 1 and 9
     post condition return (true if the num exist and false if it does not)*/
    bool existInBlock(int num, int row, int col);
    /*purpose: check if num exist in the same blog
     precondition: row, col  and num between 1 and 9
     post condition return (true if the num exist and false if it does not)*/

};

#endif /* SUDOKU_H */

