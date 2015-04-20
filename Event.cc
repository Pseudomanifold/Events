#include "Event.hh"

Event::Event( const EventType& type )
  : _type( type )
{
}

EventType Event::type() const
{
  return _type;
}

CreationEvent::CreationEvent()
  : Event( EventType::Creation )
{
}

DestructionEvent::DestructionEvent()
  : Event( EventType::Destruction )
{
}
