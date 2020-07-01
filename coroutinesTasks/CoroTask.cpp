#include "CoroTask.h"

CoroTask::CoroTask( std::shared_ptr<jmp_buf> schedulerStack ) :
  mScheduler( schedulerStack )
{

}

CoroTask::~CoroTask()
{
  mScheduler.reset();
}

template <class ReturnType, class ... FunctionArgs>
void CoroTask::setFunction( std::function<ReturnType( const CoroTask& coroTask, FunctionArgs... )> function )
{
  function();
}

