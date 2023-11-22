#ifndef MAKI_LAB7_H
#define MAKI_LAB7_H

#include <string.h>
#include <stdio.h>

// Macros
#define DIVIDER_LENGTH 110
#define STAR '*'
#define DASH '-'
#define SCHOOL "Binghamton University\n"
#define LAB "Lab 7 - Numeric Arrays\n"
#define PROGRAMMER "Program Written by: Isaac Mak\n"

#define MAX_ARRAY_SIZE 20
#define FILE_ARRAY_TITLE "File Array\n"
#define CALCULATED_ARRAY_TITLE "Calculated Array\n"
#define AVERAGES_TITLE "Averages\n"
#define GREATEST_VALUE_TITLE "Highest Data Values\n"
#define ADD_ELEMENTS_FILE_ARRAY_TITLE "File Array With Added Elements\n"
#define ADD_FIVE_CALCULATED_ARRAY_TITLE "Calculated Array With Add Five\n"
#define UPDATED_AVERAGES_TITLE "Updated Averages\n"
#define UPDATED_GREATEST_VALUE_TITLE "Updated Highest Data Values\n"


// Function Prototypes
void PrintHeader(FILE *outputFile, char school[], char lab[], char programmer[]);

void PrintDivider(FILE *outputFile, char symbol, int numberOf);

void CenterString(FILE *outputFile, char string[], int lengthToCenterAcross);

void FillFileArray(FILE* pInputFile, int maxArraySize, int* counter, int fileArray[]);

void FillCalculateArray(int calculatedArray[], int maxArraysize, int* counter);

void PrintArray(FILE* outputFile, int array[], int counter, char title[]);

double CalculateAverage(int array[], int counter);

void OutputAverages(FILE* outputFile, double fileAverage, double calculatedAverage, char title[]);

int CalculateHighest(int array[], int counter);

void OutputHighestData(FILE* outputFile, int greatestFileArray, int greatestCalculatedArray, char title[]);

void AddFive(int* array, int counter);

void AddElements(int* fileArray, int calculatedArray[], int counter);

#endif