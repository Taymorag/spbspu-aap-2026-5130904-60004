#include <iostream>
#include <stdexcept>

int DivRem();

int main()
{
  try {
    std::cerr << DivRem() << std::endl;
    return 0;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch (const std::logic_error& e) {
    std::cerr << e.what() << std::endl;
    return 2;
  }
}

int DivRem()
{
  int k = 0;
  int prev = 0;
  int num = 0;
  int now = 0;
  while (true) {
    if (!(std::cin >> now)) {
      throw std::invalid_argument("Not a number");
    }

    if (now == 0) {
      if (num < 2) {
        throw std::logic_error("Not enough numbers");
      }
      return k;
    }

    if (prev != 0 && (now % prev == 0)) {
      k++;
    }

    num++;
    prev = now;
  }
}
