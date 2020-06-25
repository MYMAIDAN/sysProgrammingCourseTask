#include "scheduler.h"

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
