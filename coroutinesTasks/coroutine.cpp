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
    static_cast<FunctionWrapperImpl<FuncType>*>(mFunctionWrapper)->mFunction();
  }

  class FunctionBase
  {};

  template <class T>
  class FunctionWrapperImpl: public FunctionBase
  {
  public:
    FunctionWrapperImpl( T function ):
      mFunction( function )
    {
    }
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

  std::vector<CoroFunction> fmap;
  fmap.emplace_back( testFunction );
  fmap.emplace_back( testFunction );
  return 0;
}
