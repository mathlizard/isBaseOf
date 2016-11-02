#include <iostream>

template< typename A, typename B >
class isEqual{
 public: 
  static const bool value = false;  
};

template< typename A >
class isEqual<A,A>{
 public:
  static const bool value = true;
};


template< typename A, typename B >
class isBaseOf{
 private:
  class No{ bool x[2]; };
  static bool const test(A*); // { return true; }
  static No test(...); // { return false; }
 public:
  static bool value(){ return (sizeof(test(static_cast<B*>(0))) == sizeof(bool)) && !(isEqual<A,B>::value); }
}; 


class A {};

class B : public A {};

int main(){
 std::cout << isBaseOf<A,B>::value() << std::endl;
 return 0;
}
