#ifndef _CORO_FUNCTION_H_
#define _CORO_FUNCTION_H_


class CoroFunction
{
public:
  template <class FuncType>
  CoroFunction( FuncType function ):
    mFunctionWrapper( new FunctionWrapperImpl<FuncType>( function ) )
  {
  }
  void operator()()
  {
    mFunctionWrapper->operator()();
  }

private:
  class FunctionBase
  {
  public:
    virtual void operator()() = 0;
  };

  template <class Type>
  class FunctionWrapperImpl : public FunctionBase
  {
  public:
   FunctionWrapperImpl( Type func ):
      mFunction( func )
    {
    }

    void operator()() override
    {
      mFunction();
    }
  private:
    Type mFunction;
  };

FunctionBase* mFunctionWrapper{ nullptr  };
};

#endif // _CORO_FUNCTION_H__
