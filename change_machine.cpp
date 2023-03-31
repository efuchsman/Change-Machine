#include <iostream>
#include <cmath>
#include <unordered_map>
#include <utility>

using std::make_pair;
using std::unordered_map;

class ChangeMachine
{
private:
  float amount;

public:
  void changeMaker() const
  {
    float amount;

    while (true)
    {
      std::cout << "Enter an amount as a floating-point number: ";
      if (std::cin >> amount && amount >= 0)
      {
        break;
      }
      else
      {
        std::cout << "Error please input a valid amount greater than zero" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }

    std::cout << "$" << amount << std::endl;

    int dollarAmount = static_cast<int>(amount);
    int changeAmount = static_cast<int>(round((amount - dollarAmount) * 100));

    unordered_map<int, int> dollarHash;
    dollarHash.insert(make_pair(100, 0));
    dollarHash.insert(make_pair(20, 0));
    dollarHash.insert(make_pair(10, 0));
    dollarHash.insert(make_pair(5, 0));
    dollarHash.insert(make_pair(1, 0));

    unordered_map<int, int> changeHash;
    changeHash.insert(make_pair(25, 0));
    changeHash.insert(make_pair(10, 0));
    changeHash.insert(make_pair(5, 0));
    changeHash.insert(make_pair(1, 0));

    int dollarArray[] = {100, 20, 10, 5, 1};
    int changeArray[] = {25, 10, 5, 1};

    for (int i = 0; i < 5; i++)
    {
      int index = dollarArray[i];
      while (dollarAmount >= index)
      {
        dollarAmount -= index;
        dollarHash[index]++;
      }
    }

    for (int i = 0; i < 4; i++)
    {
      int index = changeArray[i];
      while (changeAmount >= index)
      {
        changeAmount -= index;
        changeHash[index]++;
      }
    }

    std::cout << "Hundreds: " << dollarHash[100] << std::endl;
    std::cout << "Twenties: " << dollarHash[20] << std::endl;
    std::cout << "Tens: " << dollarHash[10] << std::endl;
    std::cout << "Fives: " << dollarHash[5] << std::endl;
    std::cout << "Singles: " << dollarHash[1] << std::endl;

    std::cout << "Quarters: " << changeHash[25] << std::endl;
    std::cout << "Dimes: " << changeHash[10] << std::endl;
    std::cout << "Nickels: " << changeHash[5] << std::endl;
    std::cout << "Pennies: " << changeHash[1] << std::endl;
  }
};

int main()
{
  ChangeMachine machine;
  machine.changeMaker();
  return 0;
}
