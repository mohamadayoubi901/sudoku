/**--sudoku.cpp-------------------------------------------------------------------
 
 * this header file define the data type sudoku for processing a sudoku game.
 * sudoku data members:
 * int gridDimension: the dimension of the grid
    Dyn2DArray initialGrid:  a pointer to 2d array that contain the data
    int nbrOfErrors: the numbers of error occured
    int nbrOfAllowedErrors: the number of allowed errors
    Dyn2DArray emptyElementsArray:a pointer to a 2 d contains having 1/0 elements
    int nbrOfMissedDigits: number digit to be guessed..
 */

/* 
 * File:   Sudoku.cpp
 * Author: moham
 * 
 * Created on 5 March 2021, 21:52
 */

#include "Sudoku.h"

Sudoku::Sudoku(Dyn2DArray initialGrid, int gridDimension) {
   this->gridDimension=gridDimension;// set grid dimension
   this->initialGrid=initialGrid; // set initial grid
   this->nbrOfErrors=0; // set nbrOfErrors to 0
   this->nbrOfAllowedErrors=5;// set nbrOfAllowedErrors to 5
   this->emptyElementsArray=generateEmptyElementsArray();
   // call generateEmptyElementsArray() and
   //set emptyElementsArray to the return 
   this->nbrOfMissedDigits=countMissedValues();
   // call countMissedValues()) and
   //set nbrOfMissedDigits to the return
}


 void Sudoku:: displaySudoku(){
     
     //display the array elements
  cout<<"   ";
  for (int i=0;i<gridDimension;i++){
   cout<<" col"<<i+1<<"   ";
   }
  for(int i=0;i<gridDimension;i++){
     cout<<"\nrow"<<i+1;
     for(int j=0;j<gridDimension;j++){
       if(initialGrid[i][j]!=0)
         cout<<"  "<<initialGrid[i][j]<<"     ";//display the element if it is not equal to 0
       else
         cout<<"  "<<" "<<"     "; // display empty space if the element equal to 0
     }
   }
 }
 Dyn2DArray Sudoku:: generateEmptyElementsArray(){
     
  Dyn2DArray EmptyElementsArray = new int*[gridDimension];
  //initialize a pointer EmptyElementsArray to a  2d array 
  //with dimension equal griddimension
   for(int i=0;i<gridDimension;i++){
    EmptyElementsArray[i]=new int[gridDimension];
    for(int j=0;j<gridDimension;j++){
      if(initialGrid[i][j]!=0)
        EmptyElementsArray[i][j]=1;
    //fill the EmptyElementsArray with 1 if the
    //if the corresponging initial grid element not equal to 0
      else 
        EmptyElementsArray[i][j]=0;
    //fill the EmptyElementsArray with 0 if the
   
     }
    }
  return EmptyElementsArray;
  //return the pointer EmptyElementsArray;
 }
 
 int Sudoku:: countMissedValues(){
   int count=0;
   //initialize an integer count 
   for(int i=0;i<gridDimension;i++){
      for(int j=0;j<gridDimension;j++){
       if(initialGrid[i][j]==0)
        count++;
       //increament count by 1
        }
     }
     return count;
     //return integer count
   }
 int Sudoku:: addValueInACell(int num, int row, int col){
     
   if(existInRow(num,row)){
     return 2;//call method exitinrow and return 2 if it is true
    }
   if(existInCol(num,col)){
      return 3;} //call method existInCol and return 3 if it is true
  if(existInBlock (num,row,col)){
     return 4;} //call method existInBlock and return 4 if it is true
  if(initialGrid[row-1][col-1]==0){
     initialGrid[row-1][col-1]=num; //set the element to num if it dosent exist before
      return 0;     //return 0;
    } 
  initialGrid[row-1][col-1]=num;//set the element and return 1;
    return 1;
 
 }
 
 bool Sudoku::  existInRow(int num, int row){
     
   for(int i=0;i<gridDimension;i++){
     if(initialGrid[row-1][i]==num)//check rows
       return true;//return true if exist
    }
   return false;// return false if not
 }
  bool Sudoku:: existInCol(int num, int col){
      
   for(int i=0;i<gridDimension;i++){
        if(initialGrid[i][col-1]==num)//check columns
           return true;//return true if exist
      }
    return false;//return false if not
 }
 
  
bool Sudoku:: existInBlock(int num, int row, int col){
    int bx=(row-1)/3;//initialize bx to row -1 divide by 3 
    int by=(col-1)/3;//initialize by to col-1 divide by 3 
    for(int i=(bx*3);i<(bx*3+3);i++){//loop from bx*3 to bx*3+3(blog in row)
        for(int j=(by*3);j<(by*3+3);j++){//loop from by*3 to by*3+3(blog in col)
            if(initialGrid[i][j]==num )
                return true;//return true if the num exist in the blog
       
        }
    }
    return false;//return false if not
}

void Sudoku:: runGame(){
    
int theValue=0,rowNumber=0,colNumber=0,resultOfAddValueInACell;
emptyElementsArray=generateEmptyElementsArray();
// call generateEmptyElementsArray() and
   //set emptyElementsArray to the return 
nbrOfMissedDigits=countMissedValues();
 // call countMissedValues()) and
   //set nbrOfMissedDigits to the return

do{ //loop till infinite
    
   displaySudoku();//call displaySudoku() to display the sudoku
   do{ 
      theValue=0;
      rowNumber=0;
      colNumber=0;
      while(rowNumber>gridDimension || rowNumber<1){//loop till rownumb is valid
       cout<<"\nEnter the row(between 1 and 9):";//prompt the user to enter row
       cin>>rowNumber;
       if(rowNumber>gridDimension || rowNumber<1){//check the entered row
          cerr<<"\ninvalid row number";
          }
       }
      while(colNumber>gridDimension || colNumber<1){//loop till colnumb is valid  
       cout<<"\nEnter the column(between 1 and 9):";//prompt the user to enter col
       cin>>colNumber;
       if(colNumber>gridDimension || colNumber<1){//check the entered column 
        cerr<<"\ninvalid column number";
        }
      }
    if(emptyElementsArray[rowNumber-1][colNumber-1]!=0){
       //check if the element with the same row and column  exist in the data
   cout<<"\nThe element["<<rowNumber<<"]["<<colNumber<<"] is initially assigned";
   }
  
  }while(emptyElementsArray[rowNumber-1][colNumber-1]!=0);
  //loop until the entered row and colum correspond 
  //to a new elemnt not existing in the data
   
      
    
    while(theValue>9 || theValue<1){//loop till value is valid
     cout<<"\nEnter the value you want to add(between 1 and 9):";
     cin>>theValue;//prompt the user to enter a value

     if(theValue>9|| theValue<1){//check if the value entered is valid
       cerr<<"\ninvalid value number";
     }
   }
   
     resultOfAddValueInACell=addValueInACell(theValue, rowNumber,colNumber);
     //call the method addValueInACell
     //set resultOfAddValueInACell to the returned integer
switch(resultOfAddValueInACell){
    case 0: cout<<"\n the value is stored in a cell that was not assigned yet"<<endl;
       nbrOfMissedDigits--;//decrease the number digit to be entered
       break;
       
    case 1:
      cout<<"\nthe value is stored in a cell that was previously assigned"<<endl;
      break;
            
    case 2:
      cout<<"\nThe value exists in the same row"<<endl;
      nbrOfErrors++;//increase the number of error made by the user
    cout<<"\nNumber of errors is "<<nbrOfErrors<<" out of "<<nbrOfAllowedErrors<<endl;
    break;
    
    case 3: 
      cout<<"\nThe value exists in the same column"<<endl;
       nbrOfErrors++;//increase the number of error made by the user
    cout<<"\nNumber of errors is "<<nbrOfErrors<<" out of "<<nbrOfAllowedErrors<<endl;
      break;
    
    case 4:
        cout<<"\nThe value exists in the same block"<<endl;
        nbrOfErrors++;//increase the number of error made by the user
    cout<<"\nNumber of errors is "<<nbrOfErrors<<" out of "<<nbrOfAllowedErrors<<endl;
    break;
  }
    
  if(nbrOfErrors>=nbrOfAllowedErrors){//check the number of error made
  cout<<"\nhard luck out of chances try again"<<endl;
  break;//exit the loop
  }


  if(nbrOfMissedDigits==0){//check the number of digit to be entered
  cout<<"congratulation you have win the  game";
  break;//exit the loop
  }


}while(true);

}
