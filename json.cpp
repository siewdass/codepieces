g++ j.cpp -ljsoncpp
 
#include <jsoncpp/json/json.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace Jsoncpp = Json;
#define Json _Json


class {
  public:
    template < typename type >
    void log( type data ) {
       cout << data << endl;
    }
} console;

class Json {
  public:

		Jsoncpp::Reader reader; 
		Jsoncpp::Value data; 
		const char* last;

    std::string str;
    string type;
    
    Json( ) {
    }
    
    Json operator = ( int a ) {
    	Json tmp;
    	return tmp;
    }
    
    void open( const char* f ) {
		  std::ifstream file ( f );
		    if ( file.is_open( ) ) {
		      string txt;
		      while ( getline ( file, txt ) ) {
		        str += txt;
		      }
		    }
		    file.close( );
		    reader.parse( str, data );
		}
		
		void save( const char* f ) {
			Jsoncpp::StyledWriter writer;
			string to = writer.write( data );
			ofstream save;
			save.open( f );
			save << to;
			save.close( );
		}

    int readInteger( const char* key ) {
      return data[ key ].asInt( );
    }

    bool readBoolean( const char* key ) {
      return data[ key ].asBool( );
    }
        
    string readString( const char* key ) {
      return data[ key ].asString( );
    }
    
    Json readObject( const char* key ) {
    	Json tmp;
    	tmp.data = data[ key ];
      return tmp;
    }
    
    vector < Json > readArray( const char* key ) {
    	vector < Json > vtmp;
    	
    	Json tmp;
    	tmp.data = data[ key ];
    	
    	for ( int i = 0; i < tmp.data.size( ); i++ ) { 
    		Json t;
    		t.data = tmp.data[ i ];
			  vtmp.push_back( t );
			}
			
      return vtmp;
    }
    
    void writeInteger( const char* key, int value ) {
    	last = key;
    	type = "integer";
			data[ key ] = value;
		}
    
    void writeBoolean( const char* key, bool value ) {
    	last = key;
    	type = "boolean";
			data[ key ] = value;
		}
		
    void writeString( const char* key, const char* value ) {
    	last = key;
    	type = "string";
			data[ key ] = value;
		}
		
		void writeObject( const char* key, Json value ) {
		  Jsoncpp::Value item; 
		  if ( value.type == "integer" ) {
		  	try {
					int v = value.readInteger( value.last );
					item[ value.last ] = v;
					data[ key ] = item;
				} catch ( exception &e ) {
				}
		  } else if ( value.type == "boolean" ) {
		  	try {
					bool v = value.readBoolean( value.last );
					item[ value.last ] = v;
					data[ key ] = item;
				} catch ( exception &e ) {
				}
		  } else if ( value.type == "string" ) {
		  	try {
					string v = value.readString( value.last );
					item[ value.last ] = v;
					data[ key ] = item;
				} catch ( exception &e ) {
				}
		  }
		}
		
		void writeArray( const char* key, Json value ) {
		  Jsoncpp::Value item; 
		  if ( value.type == "integer" ) {
		  	try {
					int v = value.readInteger( value.last );
					item[ value.last ] = v;
					data[ key ].append( item );
				} catch ( exception &e ) {
				}
		  } else if ( value.type == "boolean" ) {
		  	try {
					bool v = value.readBoolean( value.last );
					item[ value.last ] = v;
					data[ key ].append( item );
				} catch ( exception &e ) {
				}
		  } else if ( value.type == "string" ) {
		  	try {
					string v = value.readString( value.last );
					item[ value.last ] = v;
					data[ key ].append( item );
				} catch ( exception &e ) {
				}
		  }
		}
};

int main( ) {

	Json toSave;
	toSave.writeInteger( "monday", 1 );
	toSave.writeBoolean( "today", false );
	toSave.writeString( "weekend", "party" );
	
	for ( int i = 0; i < 2; i++ ) {
		Json item;
		item.writeInteger( "day", i );
		toSave.writeArray( "week", item );
	}
	
	Json item;
	item.writeBoolean( "night", true );
	toSave.writeObject( "saturday", item );
	toSave.save( "file.json" );

	Json toOpen;
	toOpen.open( "file.json" );
	toOpen.readInteger( "monday" );
	toOpen.readBoolean( "today" );
	toOpen.readString( "weekend" );

	for ( Json day : toOpen.readArray( "week" ) ) {
    	day.readInteger( "day" );
	}

	Json saturday = toOpen.readObject( "saturday" );
	saturday.readBoolean( "night" );

	return 0;
}
