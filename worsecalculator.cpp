#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string con;
double result = 0;
int main() {
  do {
  cout << " _______________ \n|Caculator      |\n";
  cout << "|"<< result;
  int size = result == 0 ? 1 : (result < 0 ? static_cast<int>(log10(std::abs(result))) + 1 : static_cast<int>(log10(result)) + 1);
  switch (size) {
      case 1:
        cout << "              |";
        break;
      case 2:
        cout << "             |";
        break;
      case 3:
        cout << "            |";
        break;
      case 4:
        cout << "           |";
        break;
      case 5:
        cout << "          |";
        break;
      case 6:
        cout << "         |";
        break;
      case 7:
        cout << "        |";
        break;
      case 8:
        cout << "       |";
        break;
      case 9:
        cout << "      |";
        break;
      case 10:
        cout << "     |";
        break;
      }

  cout << "\n| + | - | X | C |";
  cout << "\n| 7 | 8 | 9 | √ |";
  cout << "\n| 4 | 5 | 6 | ² |";
  cout << "\n| 1 | 2 | 3 | . |";
  cout << "\n| [ | 0 | ] | = |";
  cout << "\n|_______________|";
  cout << "\nDo you wish to continue? (Y/N)\n";
  cin >> con;
if (con == "Y") {
  cout << "Enter number: ";
  double x;
  cin >> x;
  cout << " _______________ \n|Caculator      |\n";
  cout << "|"<< x;
  int sizea = x == 0 ? 1 : (x < 0 ? static_cast<int>(log10(std::abs(x))) + 1 : static_cast<int>(log10(x)) + 1);
  switch (sizea) {
      case 1:
        cout << "              |";
        break;
      case 2:
        cout << "             |";
        break;
      case 3:
        cout << "            |";
        break;
      case 4:
        cout << "           |";
        break;
      case 5:
        cout << "          |";
        break;
      case 6:
        cout << "         |";
        break;
      case 7:
        cout << "        |";
        break;
      case 8:
        cout << "       |";
        break;
      case 9:
        cout << "      |";
        break;
      case 10:
        cout << "     |";
        break;
      }
  cout << "\n| + | - | X | C |";
  cout << "\n| 7 | 8 | 9 | √ |";
  cout << "\n| 4 | 5 | 6 | ² |";
  cout << "\n| 1 | 2 | 3 | . |";
  cout << "\n| [ | 0 | ] | = |";
  cout << "\n|_______________|";
  
  cout << endl << "Enter symbol: ";
  string sym;
  cin >> sym;
    cout << " _______________ \n|Caculator      |\n";
  cout << "|"<< sym << "              |";
 
  
  cout << "\n| + | - | X | C |";
  cout << "\n| 7 | 8 | 9 | √ |";
  cout << "\n| 4 | 5 | 6 | ² |";
  cout << "\n| 1 | 2 | 3 | . |";
  cout << "\n| [ | 0 | ] | = |";
  cout << "\n|_______________|";
  cout << "\nEnter number: ";
  double y;
  cin >> y;
    cout << " _______________ \n|Caculator      |\n";
  cout << "|"<< y;
  int sizec = y == 0 ? 1 : (y < 0 ? static_cast<int>(log10(std::abs(y))) + 1 : static_cast<int>(log10(y)) + 1);
  switch (sizec) {
      case 1:
        cout << "              |";
        break;
      case 2:
        cout << "             |";
        break;
      case 3:
        cout << "            |";
        break;
      case 4:
        cout << "           |";
        break;
      case 5:
        cout << "          |";
        break;
      case 6:
        cout << "         |";
        break;
      case 7:
        cout << "        |";
        break;
      case 8:
        cout << "       |";
        break;
      case 9:
        cout << "      |";
        break;
      case 10:
        cout << "     |";
        break;
      }
  
  cout << "\n| + | - | X | C |";
  cout << "\n| 7 | 8 | 9 | √ |";
  cout << "\n| 4 | 5 | 6 | ² |";
  cout << "\n| 1 | 2 | 3 | . |";
  cout << "\n| [ | 0 | ] | = |";
  cout << "\n|_______________|\n";
  if (sym == "+") {
    result = x + y;
  } else if (sym == "-") {
    result = x - y;
  } else if (sym == "x") {
    result = x * y;
  } else if (sym == "/") {
    result = x / y;
  } else {
    result = 0;
  }
} else {
  break;
}
 
  
  }
  while (con == "Y" && result <=2147483647);
  cout << "The calculator is closed since you either want to or the the result exceeds 2147483647.";
}