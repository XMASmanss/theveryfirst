#include <iostream>
using namespace std;

int main(){
    
    string name;
    cout << "See if you are allowed to vote.\n\nWhat is your name?\n";
    getline (cin, name);
    cout << "Are you sure that your name is " << name << "? (Y/N)\n";
    string confirmation;
    cin >> confirmation;
   int con;
    if (confirmation == "Y") {
        con = 1;
    }   else if (confirmation == "N") {
        con = 2;
    }   else {
        con = 3;
    }
    switch(con) {
        case 1:
            cout << "Okay\n";
        case 2:
            cout << "Please retype\n";
        default:
            cout << "What do you mean?\n";
    }
    
    int x;
    cout << "Enter your age: ";
    cin >> x;
    cout << "Are you gay? (Y/N) \n";
    string gay;
    int ac;
    cin >> gay;
    if (x<0){
        cout << "Were you born?\n";
        ac = 0;
    }   else if (x>100) {
        cout << "Are you dead?\n";
        ac = 0;
    }       else {
        ac = 1;
    }
    int gc = (gay == "N")? 1:0;
    string result = (gc == 1 && ac == 1)? "You are allowed to vote." : "You are not allowed to vote.";
    cout << result;
}
