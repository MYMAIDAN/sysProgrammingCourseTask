#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include <setjmp.h>
#include <vector>


class CoroScheduler
{
public:
  CoroScheduler();
  ~CoroScheduler();

  void pushTask( jmp_buf* buf );

private:
  std::vector<jmp_buf*> mTaskBuff;
  jmp_buf               mSchedulerBuff;
};

#endif // _SCHEDULER_H_
