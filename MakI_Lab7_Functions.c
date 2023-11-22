#include "MakI_Lab7.h"

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   Prints the Header to the screen
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE *outputFile, char school[], char lab[], char programmer[]) {
  PrintDivider(outputFile, STAR, DIVIDER_LENGTH);

  CenterString(outputFile, school, DIVIDER_LENGTH);
  CenterString(outputFile, lab, DIVIDER_LENGTH);
  CenterString(outputFile, programmer, DIVIDER_LENGTH);

  PrintDivider(outputFile, STAR, DIVIDER_LENGTH);
}

//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen.
//
//-----------------------------------------------------------------------------
void PrintDivider(FILE *outputFile, char symbol, int numberOf) {
  // Print a bunch of symbols across the screen
  for (int counter = 0; counter < numberOf; counter++) {
    // Print one character to the screen
    fprintf(outputFile, "%c", symbol);
  }

  // Move the cursor down to the next line
  fprintf(outputFile, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(FILE *outputFile, char string[], int lengthToCenterAcross) {
  // Capture how long the string is
  // Cast to an integer because strlen technically returns size_t
  int stringLength = (int)strlen(string);

  // Calculate the width to print the string in
  int width = (lengthToCenterAcross + stringLength) / 2;

  // Calculate how many blank spaces are needed before printing the string
  int numberOfBlankSpaces = width - stringLength;

  // Print the spaces needed to center the string
  for (int counter = 0; counter < numberOfBlankSpaces; counter++) {
    // Print one space
    fprintf(outputFile, " ");
  }

  // Print the string
  fprintf(outputFile, "%s", string);
}

//-----------------------------------------------------------------------------
// Function Name: FillFileArray
// Description:
//   Read in elements and fill array with read elements
//
//-----------------------------------------------------------------------------
void FillFileArray(FILE* pInputFile, int maxArraySize, int* counter, int fileArray[]) {
  int i = 0;
  int num;

  while (fscanf(pInputFile, "%d", &num) == 1 && i < maxArraySize) {
    fileArray[i++] = num;
  }

  *counter = i;
}

//-----------------------------------------------------------------------------
// Function Name: FillCalculateArray
// Description:
//   Make the first value of the array 75.
//   If the previous is even, divide it by 2
//   If the prvious value is odd, then calculate the next value with (3 * previous value) + 1
//   Continue loop until array is filled or the last value is 1
//
//-----------------------------------------------------------------------------
void FillCalculateArray(int calculatedArray[], int maxArraysize, int* counter) {
  calculatedArray[0] = 75;
  int i = 1;
  
  while (i < maxArraysize && calculatedArray [i-1] != 1) {
    if (calculatedArray[i - 1] % 2 == 0) // If element is even
    {
      calculatedArray[i] = calculatedArray[i - 1] / 2; // Divide by 2
    } 
    else // If element is odd
    {
      calculatedArray[i] = 3 * calculatedArray[i - 1] + 1; // (3 * previous value) + 1
    }
    i++;
    }
  *counter = i;
}

//-----------------------------------------------------------------------------
// Function Name: PrintArray
// Description:
//   Print a table with the title to the output file
//   Print elements in rows of 5
//
//-----------------------------------------------------------------------------
void PrintArray(FILE* outputFile, int array[], int counter, char title[]) {
    // Title
    PrintDivider(outputFile, DASH, DIVIDER_LENGTH);
    CenterString(outputFile, title, DIVIDER_LENGTH);
    PrintDivider(outputFile, DASH, DIVIDER_LENGTH);
  
    // Loop through array and print elements in rows of 5
    for (int i = 0; i < counter; i++) 
    {
      fprintf(outputFile, "%5d", array[i]);
      if ((i + 1) % 5 == 0) 
      {
        fprintf(outputFile, "\n");
      }
    }
    fprintf(outputFile, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: CalculateAverage
// Description:
//   Calculate the averages of an array and return it
//
//-----------------------------------------------------------------------------
double CalculateAverage(int array[], int counter) {
  double sum = 0.0;

  for (int i = 0; i < counter; i++) 
  {
    sum += array[i];
  }
  if (counter != 0)
  {
    return sum/counter;
  }
}

//-----------------------------------------------------------------------------
// Function Name: OutputAverages
// Description:
//   Print the Averages of both arrays with appropriate labels
//
//-----------------------------------------------------------------------------
void OutputAverages(FILE* outputFile, double fileAverage, double calculatedAverage, char title[]) {
  // Title
  PrintDivider(outputFile, DASH, DIVIDER_LENGTH);
  CenterString(outputFile, title, DIVIDER_LENGTH);
  PrintDivider(outputFile, DASH, DIVIDER_LENGTH);

  // Print Averages
  fprintf(outputFile, "File Array: %.2f\n", fileAverage);
  fprintf(outputFile, "Calculated Array: %.2f\n", calculatedAverage);
  fprintf(outputFile, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: CalculateHighest
// Description:
//   Traverse through the array and return highest value.
//
//-----------------------------------------------------------------------------
int CalculateHighest(int array[], int counter) {
  int greatest = array[0];

  for (int i = 1; i < counter; i++) {
      if (array[i] > greatest) {
          greatest = array[i];
      }
  }
  return greatest;
}

//-----------------------------------------------------------------------------
// Function Name: OutputHighestData
// Description:
//   Print both the highest data values with appropriate labels.
//
//-----------------------------------------------------------------------------
void OutputHighestData(FILE* outputFile, int greatestFileArray, int greatestCalculatedArray, char title[]) {
  // Title
  PrintDivider(outputFile, DASH, DIVIDER_LENGTH);
  CenterString(outputFile, title, DIVIDER_LENGTH);
  PrintDivider(outputFile, DASH, DIVIDER_LENGTH);

  // Print Greatest Values
  fprintf(outputFile, "Greatest File Array Value: %d\n", greatestFileArray);
  fprintf(outputFile, "Greatest Calculated Array Value: %d\n", greatestCalculatedArray);
  fprintf(outputFile, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: AddFive
// Description:
//   Add 5 to every element of the array.
//
//-----------------------------------------------------------------------------
void AddFive(int* array, int counter) {
  for (int i = 0; i < counter; i++) 
  {
    *(array+i) += 5;
  }
}

//-----------------------------------------------------------------------------
// Function Name: AddElements
// Description:
//   Add elements from calculated array to file array
//   Loops only as much times as shorter array
//   Uses Pointer Arithmetic
//
//-----------------------------------------------------------------------------
void AddElements(int* fileArray, int calculatedArray[], int counter) {
  for (int i = 0; i < counter; i++) 
  {
    *(fileArray+i) += calculatedArray[i];
  }
}