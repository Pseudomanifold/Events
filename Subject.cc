#include "Connection.hh"
#include "Subject.hh"
#include "Event.hh"

#include <iostream>

void Subject::registerObserver( const EventType& type, function_type&& function )
{
  _observers[type].push_back( function );
}

void Subject::unregisterObserver( const Connection& connection )
{
  std::cout << __PRETTY_FUNCTION__ << std::endl
            << "  ID = " << connection.id() << std::endl;
}

void Subject::notify( const Event& event ) const
{
  auto type = event.type();

  if( _observers.find( type ) == _observers.end() )
    return;

  const auto& observers = _observers.at( type );

  for( auto&& observer : observers )
    observer( event );
}
