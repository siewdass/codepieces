// sudo apt install libxdo-dev
// g++ xdo-events.cpp -lxdo -o xdo-events

extern "C" {
  #include <xdo.h>
}

xdo_t * xdo = xdo_new( NULL );

void mouse ( int x, int y, button ) {
  xdo_move_mouse( xdo, x, y, CURRENTWINDOW );
  xdo_mouse_down( xdo, CURRENTWINDOW, button );
  xdo_mouse_up( xdo, CURRENTWINDOW, button );
}

void keyboard ( const char* key ) {
  xdo_send_keysequence_window( xdo, CURRENTWINDOW, key, 0 );
}

int main( ) {

  sleep( 2 );
  mouse( 200, 200, 1 );
  sleep( 1 );
  keyboard( "a" );
  xdo_free( xdo );

  return 0;
}
