//*****************************************************************************
// Author: EX
// Assignment:
// Date:
// Description:
// Input:
// Output:
// Sources:
//*****************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

int readInt(string prompt);
void readScore(string prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double &midtermScore, double &finalExamScore); 
double calcFinalScore(double assignAvg, double midtermScore, double finalScore);
void calcLetterGrade(double finalScore, char &letter);

int main() {
  
  double assignAvg;
  double grades;
  double num = 0;
  double totalGrades;
  double midtermScore;
  double finalExamScore;
  double avgTotalGrade;
  double finalScore;
  char letter;

  cout << "Welcome to my Final Grade Calculator!" << endl;
  cout << "Please enter the following information and I will calculate your " << endl;
  cout << "Final Numerical Grade and Letter Grade for you! " << endl;
  cout << "The number of assignments must be between 0 and 10. " << endl;
  cout << "All scores entered must be between 0 and 4." << endl;
  cout << '\n';

  cout << "Enter the number of assignments (0 to 10): ";
  
  
  assignAvg = assignAverage(num);
  getInput(midtermScore, finalExamScore);
  avgTotalGrade = calcFinalScore(assignAvg, midtermScore, finalExamScore);
  
  cout << "Your Final Score is ";
  calcLetterGrade(avgTotalGrade, letter);
  cout << avgTotalGrade << endl;
  cout << "Your Final Grade is ";
  cout << letter;
  
  
}


int readInt(string prompt){
  double totalGrades;
  double numAssigns;
  
  cin >> numAssigns;

  if ((numAssigns > 10) || (numAssigns <0)){
    cout << "Invalid! Try again!" << endl; 
    cout << "Enter the number of assignments (0 to 10): ";
    cin >> numAssigns;
  }  
  return numAssigns;
}

void readScore(string prompt, double &num){
  cout << " " << endl;  
  cin >> num;
  if ((num > 4 ) || (num < 0)){
    cout << "Invalid! Try again!" << endl;
  }
}

double assignAverage(int numAssigns){
  double totalGrades;
  double nums;
  double avgGrade;
  int i;
  

  numAssigns = readInt("");
  /*
  cout << numAssigns << endl;
  cout << "Enter Grade:";
  readScore("", nums);
*/
  for (i=0; i < numAssigns; i++){
    cout << "Enter Grade: "; 
    readScore("", nums);
    totalGrades += nums;
  }

    avgGrade = static_cast<double>(totalGrades)/numAssigns;
    //test to see if avg is correct//
    cout << avgGrade << endl;
    return avgGrade;
    
}

void getInput(double &midtermScore, double &finalExamScore){
  cout << "Enter your midterm exam score: ";
  readScore("", midtermScore);
  cout << "Enter your final exam score: ";
  readScore("", finalExamScore);

}

 double calcFinalScore(double assignAvg, double midtermScore, double finalScore){
  double totalGrade;
   
  totalGrade = ((assignAvg * 60) + (midtermScore * 20) + (finalScore * 20))/100;
  return totalGrade;
 }

void calcLetterGrade(double finalScore, char &letter){
  
  

  if ((finalScore >=3.3) && (finalScore <= 4.0)){
    letter = 'A';
 
  }
    if ((finalScore >=2.8 ) && (finalScore < 3.3)){
    letter = 'B';
  
  }
    if ((finalScore >=2.0 ) && (finalScore < 2.8)){
    letter = 'C';
  
  }
    if ((finalScore >=1.2 ) && (finalScore < 2.0)){
    letter = 'D';
    
  }  
    if ((finalScore >=0.0 ) && (finalScore < 1.2)){
    letter = 'F';
    }
}
