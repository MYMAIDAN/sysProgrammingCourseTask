#ifndef _CORO_TASK_H_
#define _CORO_TASK_H_

#include <setjmp.h>
#include <memory>

class CoroTask
{
public:
  CoroTask( std::shared_ptr<jmp_buf> schedulerStack );
  ~CoroTask();
  void task_yuield();

private:
  std::shared_ptr<jmp_buf> mScheduler;
  jmp_buf        mJmpBuf;
};

#endif // _CORO_TASK_H_
