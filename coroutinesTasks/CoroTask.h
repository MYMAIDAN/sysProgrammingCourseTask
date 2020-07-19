#ifndef _CORO_TASK_H_
#define _CORO_TASK_H_

#include <setjmp.h>
#include <memory>
#include <functional>

#include "CoroFunction.h"

class CoroTask
{
public:
  CoroTask( std::shared_ptr<jmp_buf> schedulerStack );
  ~CoroTask();
//  void task_yuield();
  template <class Type>
  void setFunction( Type function )
  {
    mFunction = new CoroFunction( function );
    mFunction->operator()();
  }

private:
  std::shared_ptr<jmp_buf> mScheduler;
  jmp_buf                  mJmpBuf;
  CoroFunction*            mFunction;

};

#endif // _CORO_TASK_H_
