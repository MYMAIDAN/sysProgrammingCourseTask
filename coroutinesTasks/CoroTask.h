#ifndef _CORO_TASK_H_
#define _CORO_TASK_H_

#include <setjmp.h>
#include <memory>
#include <functional>

class CoroTask
{
public:
  CoroTask( std::shared_ptr<jmp_buf> schedulerStack );
  ~CoroTask();
//  void task_yuield();
  template <class ReturnType, class ...FunctionArgs>
  void setFunction( std::function<ReturnType( const CoroTask& coroTask, FunctionArgs... )> function );

private:
  std::shared_ptr<jmp_buf> mScheduler;
  jmp_buf                  mJmpBuf;
};

#endif // _CORO_TASK_H_
