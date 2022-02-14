#include <iostream>
#define var auto
#define function []
#define const const auto
using namespace std;

class {
  public:
    template < typename type >
    void log( type data ) {
       cout << data << endl;
    }
} console;

int main( ) {

  const a = function ( ) {
    console.log( "hello World" );
  };

  var b = 1;
  console.log( b );
  a( );
    
}
