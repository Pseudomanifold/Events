#include "Connection.hh"
#include "Subject.hh"

Connection::Connection( Subject& subject, unsigned int id )
  : _subject( subject )
  , _id( id )
{
}

Connection::~Connection()
{
  _subject.unregisterObserver( *this );
}

unsigned int Connection::id() const
{
  return _id;
}
