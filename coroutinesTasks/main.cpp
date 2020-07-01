#include <iostream>
#include "CoroTask.h"

int main()
{

  std::shared_ptr<jmp_buf> buf = std::make_shared<jmp_buf>();
  CoroTask task( buf );
  return 0;
}
