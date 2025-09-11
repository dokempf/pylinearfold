#include "pylinearfold/pylinearfold.hpp"
#include <iostream>

int
main()
{
  int result = pylinearfold::add_one(1);
  std::cout << "1 + 1 = " << result << std::endl;
}
