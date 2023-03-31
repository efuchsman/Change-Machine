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
    float changeArray[] = {25, 10, 5, 1};

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
      float index = changeArray[i];
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
  float amount1 = 127.45;
  ChangeMachine machine1(amount1);
  machine1.changeMaker();

  std::cout << "-----------" << std::endl;

  float amount2 = 1202.85;
  ChangeMachine machine2(amount2);
  machine2.changeMaker();

  std::cout << "-----------" << std::endl;

  float amount3 = 0.78;
  ChangeMachine machine3(amount3);
  machine3.changeMaker();

  std::cout << "-----------" << std::endl;

  float amount4 = 77.00;
  ChangeMachine machine4(amount4);
  machine4.changeMaker();

  std::cout << "-----------" << std::endl;

  float amount5 = 112.15;
  ChangeMachine machine5(amount5);
  machine5.changeMaker();

  std::cout << "-----------" << std::endl;

  return 0;
}
