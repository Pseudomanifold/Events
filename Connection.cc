#include "Connection.hh"
#include "Subject.hh"

Connection::Connection( Subject& subject, unsigned int id )
  : _subject( subject )
  , _id( id )
{
}

unsigned int Connection::id() const
{
  return _id;
}

void Connection::disconnect()
{
  _subject.unregisterObserver( *this );
}
