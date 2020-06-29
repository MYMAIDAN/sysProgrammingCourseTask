#include <setjmp.h>
#include <map>
#include <functional>
#include <iostream>
#include <vector>
class CoroFunction
{
public:
  template<class FuncType>
  CoroFunction( FuncType function ):
    mFunctionWrapper( new FunctionWrapperImpl<FuncType>( function ) )
  {
  }

  void operator()()
  {
    mFunctionWrapper->operator()();
  }

  class FunctionBase
  {
  public:
    virtual void operator()() = 0;
  };

  template <class T>
  class FunctionWrapperImpl: public FunctionBase
  {
  public:
    FunctionWrapperImpl( T function ):
      mFunction( function )
    {
    }

    void operator()() override
    {
      mFunction();
    }
  private:
    T mFunction;
  };


private:
  FunctionBase * mFunctionWrapper{ nullptr };
};


void testFunction()
{
  std::cout<< "Hello from test function" << std::endl;
}

int main()
{

  CoroFunction fmap( testFunction );
  fmap();
  return 0;
}
