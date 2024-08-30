#include <cstdio>


enum class LetterCase {
  Upper,
  Lower
};

struct MyChars {
  
  //char upper[]={'A','B','C','?','E'};

  void printError(int length){
printf("Index out of bounds: Index value should be between 0 and %d\n",length-1);
  }

  void write_to(LetterCase lcase, unsigned int index, char a)  {

    char result[]{};
    auto len{0};
    switch (lcase)
    {
      case LetterCase::Upper/* constant-expression */:
        len = sizeof(upper)/sizeof(char);
        if (index < 0 || index > len){
           printError(len);
        }
        upper[index]=a;
        break;
      
      case LetterCase::Lower:
        len = sizeof(lower)/sizeof(char);
        if (index < 0 || index > len){
           printError(len);
        }
        lower[index]=a;
        break;
      default:
        break;
    }
  }

  char read_from(LetterCase lcase, unsigned int index){

    char result{' '};
    auto len{0};

    switch (lcase)
    {
      case LetterCase::Upper/* constant-expression */:
        len = sizeof(upper)/sizeof(char);
        if (index < 0 || index > len){
          printError(len);
          result='0';
          break;
         }
         result = upper[index];
        break;
      
      case LetterCase::Lower:
        len = sizeof(lower)/sizeof(char);
        if (index < 0 || index > len){
         printError(len);
          result='0';
          break;
         }
        result = lower[index];
        break;
      default:
        break;
    }

      return result;
  }

  private:
    char lower[5]{'a','b','c','?','e'};
    char upper[5]={'A','B','C','?','E'};
};

int main() {

  //char* upper_ptr = upper; // Equivalent: &upper[0]


  MyChars mychars{};

  char letter_d = mychars.read_from(LetterCase::Lower,3); // letter_d equals 'd'
  printf("%c\n",letter_d);
  char letter = mychars.read_from(LetterCase::Upper,100); // out of bound
  printf("%c\n",letter);
  //char letter_D = upper_ptr[3]; // letter_D equals 'D'

  //printf("lower: %s\nupper: %s", lower, upper);

  //lower[7] = 'g'; // Super bad. You must never do this.

  
}
