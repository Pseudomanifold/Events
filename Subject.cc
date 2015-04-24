#include "Connection.hh"
#include "Subject.hh"
#include "Event.hh"

#include <algorithm>
#include <iostream>

Connection Subject::registerObserver( Event::EventType type, function_type&& function )
{
  FunctionHandle handle = {
    _nextID,
    function
  };

  _observers[type].push_back( handle );


  ++_nextID;
  return Connection( *this, _nextID - 1 );
}

void Subject::unregisterObserver( const Connection& connection )
{
  std::cout << __PRETTY_FUNCTION__ << std::endl
            << "  ID = " << connection.id() << std::endl;

  for( auto&& observer : _observers )
  {
    auto&& handles = observer.second;

    for( auto it = handles.begin(); it != handles.end(); )
    {
      if( it->id == connection.id() )
        it = handles.erase( it );
      else
        ++it;
    }
  }
}

void Subject::notify( const Event& event ) const
{
  auto type = event.type();

  if( _observers.find( type ) == _observers.end() )
    return;

  const auto& observers = _observers.at( type );

  for( auto&& observer : observers )
    observer.f( event );
}
