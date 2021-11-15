// g++ threading.cpp -pthread -o threading

#include <iostream>
#include <thread>
#include <chrono>

void sleep( int time ) {
	std::this_thread::sleep_for(std::chrono::seconds( time ) );
}

void task1( const char * arg ) {
   while ( true ) {
      std::cout << arg << std::endl;
      sleep( 1 );
   }
}

void task2( const char * arg ) {
  while ( true ) {
     std::cout << arg << std::endl;
     sleep( 2 );
   }
}

int main( ) {
   std::thread t1( task1, "Hi I'm Task 1" );
   std::thread t2( task2, "Hi I'm Task 2" );

   t1.join( );
   t2.join( );
}
