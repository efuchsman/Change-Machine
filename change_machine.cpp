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
    float dollarAmount = floor(amount);
    float changeAmount = round((amount - dollarAmount) * 100) / 100;
    std::cout << "$" << changeAmount << std::endl;

    unordered_map<int, int> dollarHash;
    dollarHash.insert(make_pair(100, 0));
    dollarHash.insert(make_pair(20, 0));
    dollarHash.insert(make_pair(10, 0));
    dollarHash.insert(make_pair(5, 0));
    dollarHash.insert(make_pair(1, 0));

    unordered_map<float, int> changeHash;
    changeHash.insert(make_pair(0.25f, 0));
    changeHash.insert(make_pair(0.10f, 0));
    changeHash.insert(make_pair(0.05f, 0));
    changeHash.insert(make_pair(0.01f, 0));

    int dollarArray[] = {100, 20, 10, 5, 1};
    float changeArray[] = {0.25f, 0.10f, 0.05f, 0.01f};

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

    std::cout << "Quarters: " << changeHash[0.25f] << std::endl;
    std::cout << "Dimes: " << changeHash[0.10f] << std::endl;
    std::cout << "Nickels: " << changeHash[0.05f] << std::endl;
    std::cout << "Pennies: " << changeHash[0.01f] << std::endl;
  }
};

int main()
{
  float amount = 127.45;
  ChangeMachine machine(amount);
  machine.changeMaker();
  return 0;
}
