#ifndef _CORO_TASK_H_
#define _CORO_TASK_H_

#include <setjmp.h>

#include "scheduler.h"

class CoroTask
{
public:
  CoroTask( const CoroScheduler& scheduler );
  ~CoroTask();
  void task_yuield();

private:
  CoroScheduler& mScheduler;
  jmp_buf        mJmpBuf;
};

#endif // _CORO_TASK_H_
