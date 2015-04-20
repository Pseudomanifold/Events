#include "Subject.hh"
#include "Event.hh"

void Subject::registerObserver( const EventType& type, function_type&& function )
{
  _observers[type].push_back( function );
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
