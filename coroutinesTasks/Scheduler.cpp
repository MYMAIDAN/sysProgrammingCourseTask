#include "Scheduler.h"

CoroScheduler::CoroScheduler():
  mSchedulerBuff( std::make_shared<jmp_buf>() )
{
}

CoroScheduler::~CoroScheduler()
{

}

std::shared_ptr<CoroTask> CoroScheduler::getCoroTask()
{
  mCoroTaskArray.emplace_back( std::make_shared<CoroTask>( mSchedulerBuff ) );
  return mCoroTaskArray[mCoroTaskArray.size() - 1];
}

void CoroScheduler::Run( std::vector<CoroFunction>& coroFunctionVector )
{
  for( auto& function: coroFunctionVector )
  {
    function();
  }

}
