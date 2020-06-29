#include "Scheduler.h"

CoroScheduler::CoroScheduler()
{
}

CoroScheduler::~CoroScheduler()
{

}

std::shared_ptr<CoroTask> CoroScheduler::getCoroTask()
{
  mCoroTaskArray.emplace_back();
  return mCoroTaskArray[mCoroTaskArray.size() - 1];
}

void CoroScheduler::Run( std::vector<CoroFunction>& coroFunctionVector )
{
  for( auto& function: coroFunctionVector )
  {
    function();
  }

}
