#include <iostream>
using namespace std;

int main() {
  int y = 2024, x;
  std::cout << "Age Calculator \n";
  std::cout << "To when were you given birth?" << std::endl ;
  std::cin >> x;
  std::cout << "You age is: " << y - x;
  return 0;
}