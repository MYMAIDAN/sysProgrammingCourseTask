#include <iostream>
#include "CoroTask.h"

int test( int value  )
{
  std::cout << "Hello from test function:" << value <<  std::endl;
  return 0;
}

int main()
{

  std::shared_ptr<jmp_buf> buf = std::make_shared<jmp_buf>();
  CoroTask task( buf );
  auto te = std::bind( test, 123 );
  task.setFunction( te );
  return 0;
}
