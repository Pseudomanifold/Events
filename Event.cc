#include "Event.hh"

Event::Event( const EventType& type )
  : _type( type )
{
}

Event::~Event()
{
}

const EventType& Event::type() const
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
