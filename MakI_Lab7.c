/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Isaac Mak
| Course:           CS-211: Introduction to Programming for Engineers
| Program  Name:    Lab #7
| Date:             11/21/2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|  Generates statistic from two arrays of integer values
|  The first array will be given from a data file and the second array will be calculated from the first array
|  The statistics will ge generated form these two arrays and are bound to a maximum number of elements
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   The inputs are the two arrays of integer values and the data file with the integers
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   The FillCalculateArray function will take in the first array and return the second array based on the previous
|   array. 
|   The averages and highest value of each array are processed in this program
|   The AddFive function will add 5 to each element of any array passed into it
|   The AddElements function will add elements from the calculated array to the first array
| 
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The outputs of this program are the statistics of the two arrays,
|   the statistics of the two arrays after AddFive and Add Elements have been processed,
|   and the highest value and averages of each of the 4 arrays
|
|--------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "MakI_Lab7.h"

int main(void) {
  
  // Declaration of the two initial arrays
  int calculatedArray[MAX_ARRAY_SIZE];
  int fileArray[MAX_ARRAY_SIZE];

  // Variable for Array counters
  int fileArrayCounter = 0;
  int calculatedArrayCounter = 0;

  // Variable for Array Averages
  double fileArrayAverage;
  double calculatedArrayAverage;

  // Variable for Greatest Values of Arrays
  int greatestFileArray;
  int greatestCalculatedArray;

  // Declaring Files
  FILE* pInputFile = fopen("Lab7_Data.txt", "r");
  FILE* pOutputFile = fopen("Lab7_Output.txt", "w");


  // 1. Print Header
  PrintHeader(pOutputFile, SCHOOL, LAB, PROGRAMMER);
  // 2. Fill File Array
  FillFileArray(pInputFile, MAX_ARRAY_SIZE, &fileArrayCounter, fileArray);
  // 3. Fille Calculate Array
  FillCalculateArray(calculatedArray, MAX_ARRAY_SIZE, &calculatedArrayCounter);
  // 4. Print Array Twice
  PrintArray(pOutputFile, fileArray, fileArrayCounter, FILE_ARRAY_TITLE);
  PrintArray(pOutputFile, calculatedArray, calculatedArrayCounter, CALCULATED_ARRAY_TITLE);
  // 5. Calculate Averages
  fileArrayAverage = CalculateAverage(fileArray, fileArrayCounter);
  calculatedArrayAverage = CalculateAverage(calculatedArray, calculatedArrayCounter);
  // 6. Output Averages
  OutputAverages(pOutputFile, fileArrayAverage, calculatedArrayAverage, AVERAGES_TITLE);
  // 7. Calculate Highest Values
  greatestFileArray = CalculateHighest(fileArray, fileArrayCounter);
  greatestCalculatedArray = CalculateHighest(calculatedArray, calculatedArrayCounter);
  // 8. Output Highest Values
  OutputHighestData(pOutputFile, greatestFileArray, greatestCalculatedArray, GREATEST_VALUE_TITLE);
  // 9. Add Five
  AddFive(fileArray, fileArrayCounter);
  AddFive(calculatedArray, calculatedArrayCounter);
  // 10. Add Elements
  AddElements(fileArray, calculatedArray, calculatedArrayCounter);
  // 11. Print Array Twice Updated Values
  PrintArray(pOutputFile, fileArray, fileArrayCounter, ADD_ELEMENTS_FILE_ARRAY_TITLE);
  PrintArray(pOutputFile, calculatedArray, calculatedArrayCounter, ADD_FIVE_CALCULATED_ARRAY_TITLE);
  // 12. Calculate Average Updated Values
  fileArrayAverage = CalculateAverage(fileArray, fileArrayCounter);
  calculatedArrayAverage = CalculateAverage(calculatedArray, calculatedArrayCounter);
  // 13. Output Averages Updated Values
  OutputAverages(pOutputFile, fileArrayAverage, calculatedArrayAverage, UPDATED_AVERAGES_TITLE);
  // 14. Calculate Highest Values Updated
  greatestFileArray = CalculateHighest(fileArray, fileArrayCounter);
  greatestCalculatedArray = CalculateHighest(calculatedArray, calculatedArrayCounter);
  // 15. Output Highest Data Updated
  OutputHighestData(pOutputFile, greatestFileArray, greatestCalculatedArray, UPDATED_GREATEST_VALUE_TITLE);  
   
  return 0;
}