#include "Connection.hh"
#include "Dispatcher.hh"

Connection::Connection()
{
}

unsigned int Connection::id() const
{
  return _id;
}

void Connection::disconnect()
{
  if( _dispatcher )
    _dispatcher->unsubscribe( *this );
}

Connection::Connection( Dispatcher* dispatcher, unsigned int id )
  : _dispatcher( dispatcher )
  , _id( id )
{
}
