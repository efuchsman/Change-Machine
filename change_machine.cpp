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
  ChangeMachine(float amount)
  {
    this->amount = amount;
    std::cout << "$" << amount << std::endl;
  }

  void changeMaker() const
  {
    float changeAmount, dollarAmount;
    changeAmount = modf(amount, &dollarAmount);

    unordered_map<int, int> dollarHash;
    dollarHash.insert(make_pair(100, 0));
    dollarHash.insert(make_pair(20, 0));
    dollarHash.insert(make_pair(10, 0));
    dollarHash.insert(make_pair(5, 0));
    dollarHash.insert(make_pair(1, 0));

    unordered_map<double, int> changeHash;
    changeHash.insert(make_pair(0.25, 0));
    changeHash.insert(make_pair(0.10, 0));
    changeHash.insert(make_pair(0.05, 0));
    changeHash.insert(make_pair(0.01, 0));

    int dollarArray[] = {100, 20, 10, 5, 1};
    double changeArray[] = {0.25, 0.10, 0.05, 0.01};

    int dollarIndex = 0;
    int changeIndex = 0;

    while (dollarAmount > 0)
    {
      while (dollarAmount > dollarArray[dollarIndex])
      {
        dollarAmount -= dollarArray[dollarIndex];
        dollarHash[dollarArray[dollarIndex]]++;
      }
      dollarIndex++;
    }

    while (changeAmount > 0)
    {
      while (changeAmount > changeArray[changeIndex])
      {
        changeAmount -= changeArray[changeIndex];
        changeHash[changeArray[changeIndex]]++;
      }
      changeIndex++;
    }

    std::cout << "Hundreds: " << dollarHash[100] << std::endl;
    std::cout << "Twenties: " << dollarHash[20] << std::endl;
    std::cout << "Tens: " << dollarHash[10] << std::endl;
    std::cout << "Fives: " << dollarHash[5] << std::endl;
    std::cout << "Singles: " << dollarHash[1] << std::endl;

    std::cout << "Quarters: " << changeHash[0.25] << std::endl;
    std::cout << "Dimes: " << changeHash[0.10] << std::endl;
    std::cout << "Nickels: " << changeHash[0.05] << std::endl;
    std::cout << "Pennies: " << changeHash[0.01] << std::endl;
  }
};

int main()
{
  float amount = 123.45;
  ChangeMachine machine(amount);
  machine.changeMaker();
  return 0;
}
