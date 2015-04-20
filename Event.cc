#include "Event.hh"

Event::Event( const EventType& type )
  : _type( type )
{
}

CreationEvent::CreationEvent()
  : Event( EventType::Creation )
{
}

DestructionEvent::DestructionEvent()
  : Event( EventType::Destruction )
{
}
