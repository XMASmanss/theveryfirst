#include <bits/stdc++.h>
using namespace std;

  string concatenated;
  string character;
  string input;
  vector<string> raw;
  vector<string> sorted;
  vector<double> number;
  vector<string> op; 
  int times = 0, timesam = 0;
  bool negative;
  double x = 0, y = 0, result;

void header (double result) {
    cout << " _______________ \n|Caculator      |\n";
    cout << "|"<< result;
    return;
}

void footer(int size) {
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
      case 11:
        cout << "    |";
        break;
      case 12:
        cout << "   |";
        break;
      case 13:
        cout << "  |";
        break;
      case 14:
        cout << " |";
        break;
      case 15:
        cout << "|";
        break;
      default:
      break;
    }
    cout << "\n| + | - | * | / |";
    cout << "\n| 7 | 8 | 9 | C |";
    cout << "\n| 4 | 5 | 6 | √ |";
    cout << "\n| 1 | 2 | 3 | . |";
    cout << "\n| [ | 0 | ] | = |";
    cout << "\n|_______________|";
    return;
}

double calculate () {

  for (string i : op) {
    
    // Prioritizing multiplication and division
    if (i == "*") {
      x = number[times] * number[times + 1];
      number.erase(number.begin() + times, number.begin() + times + 2);
      number.insert(number.begin() + times, x);
      times--;
    } else if (i == "/") {
      y = number[times] / number[times + 1];
      number.erase(number.begin() + times, number.begin() + times + 2);
      number.insert(number.begin() + times, y);
      times--;
    }
    times++;
  }

  // Removing "*" and "/" 
  op.erase( remove( op.begin(), op.end(), "*" ), op.end() );
  op.erase( remove( op.begin(), op.end(), "/" ), op.end() );
  


  // Calculating the final result
  if (op.size() > 0) {
    result = number[0];
    for (string i : op) {
      if (i == "+") {
        result += number[timesam + 1];
      } else if (i == "-") {
        result -= number[timesam + 1];
      }
      timesam++;
    }
  } else {
    result = number[0];
  }
  return result;
}

int main() {
    header(0);
    footer(1);
    cout << "\n(Type \"quit\" to quit)" "\nCalculate: ";
    bool yes = true; 
  do {
    if (yes != true) {
    cout << "\n(Type \"quit\" to quit)" "\nCalculate: ";  
    }

    getline (cin, input);
    
      // Adding each character of input into a vector
    for (int i = 0; i <= input.size(); i++) {
    character = input[i];
    raw.push_back (character);
    }
        
    if (input != "quit") {

    // Sorting out unrelated elements of the vector
    for (string cleaner : raw) {
      if (cleaner == "." || cleaner == "," || cleaner == "0" || cleaner == "1" || cleaner == "2" || cleaner == "3" || cleaner == "4" || cleaner == "5" || cleaner == "6" || cleaner == "7" || cleaner == "8" || cleaner == "9" || cleaner == "+" || cleaner == "-" || cleaner == "*" || cleaner == "/") {
      sorted.push_back(cleaner);
      }
    }
        
    while (sorted[sorted.size() - 1] == "+" || sorted[sorted.size() - 1] == "-" || sorted[sorted.size() - 1] == "*" || sorted[sorted.size() - 1] == "/") {
      sorted.pop_back();
    } 
        
    while (sorted[0] == "+" || sorted[0] == "*" || sorted[0] == "/") {
      sorted.erase(sorted.begin());
    }
    
    // Alowing negative number at the beginning
    while (sorted[0] == "-") {
      sorted.erase(sorted.begin());
      negative = true;
    }
    
    // Changing "," to "."
    replace(sorted.begin(), sorted.end(), ",", ".");

    // Concatenating strings
    for (string strnum : sorted) {      //23.42+12.31  
      if (strnum != "+" && strnum != "-" && strnum != "*" && strnum != "/") {
        concatenated += strnum;
      }
            
       else {     

        // Collecting operators
        op.push_back(strnum);

        // Converting into numbers and adding to another vector
        number.push_back(stod(concatenated));
        concatenated.clear();
      }
    } number.push_back(stod(concatenated));

    if (negative == true) {
      number[0] -= number[0] * 2;
    }

    calculate();
   
   // Just don't care about these
    string size = to_string(result); 
    vector<string> num;
    string characterr;
    for (int i = 0; i <= size.size(); i++) {
      characterr = size[i];
      num.push_back(characterr);
      while (num[num.size() - 1] == "0" || num[num.size() - 1] == ".") {
        num.pop_back();
      }
    }
    size.clear();
    for (string i : num) {
      size += i;
    }
    int numsize = size.size();

    header(result);
    footer(numsize);

    // Clearing data
    op.clear();
    number.clear();
    raw.clear();
    sorted.clear();
    concatenated.clear();
    character.clear();
    size.clear();
    num.clear();
    times = 0;
    timesam = 0;
    negative = false;
    yes = false;
    }
  } while (input != "quit");
}






