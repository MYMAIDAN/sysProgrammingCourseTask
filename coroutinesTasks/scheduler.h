#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include <setjmp.h>
#include <vector>
#include <memory>

#include "CoroTask.h"

class CoroScheduler
{
public:
  CoroScheduler();
  ~CoroScheduler();
  std::shared_ptr<CoroTask> getCoroTask();

private:
  std::vector<std::shared_ptr<CoroTask>> mCoroTaskArray;
  jmp_buf                                mSchedulerBuff;
};

#endif // _SCHEDULER_H_
