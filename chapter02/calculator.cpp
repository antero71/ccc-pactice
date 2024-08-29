// The code is compiled on a Mac with the following command: 
// clang++ --std=c++11 calculator.cpp -o calculator
 
#include <cstdio>
#include <cstddef>

enum class Operation {
  Add,
  Substract,
  Multiply,
  Divide
};

struct Calculator{

  Operation operation;

  Calculator(Operation operation){
    this->operation = operation;
  }

  int calculate(int a, int b){

    int result{0};

    switch (operation)
    {
    case Operation::Add: {
      result = {a + b};
    } break;
    case Operation::Substract: {
      result = {a - b};
    } break;
    case Operation::Multiply: {
      result = {a * b};
    } break;
    case Operation::Divide: {
      result = { a / b};
    } break;
      
  
    default:
      printf("Operation not implementet yet.\n");
      break;
    }
    return result;
  }
};

int main(){

  Calculator cal = Calculator{Operation::Add};

  int a{1};
  int b{3};

  int c = cal.calculate(a,b);
  printf("%d + %d = %d\n",a,b,c);

  cal = Calculator{Operation::Divide};

  c = cal.calculate(a,b);
  printf("%d / %d = %d\n",a,b,c);

  cal = Calculator{Operation::Substract};

  c = cal.calculate(a,b);
  printf("%d - %d = %d\n",a,b,c);

  cal = Calculator{Operation::Multiply};

  c = cal.calculate(a,b);
  printf("%d * %d = %d\n",a,b,c);

}