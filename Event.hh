#ifndef EVENT_HH__
#define EVENT_HH__

enum class EventType
{
  Creation,
  Destruction
};

class Event
{
public:
  EventType type() const;

protected:
  Event( const EventType& type );

private:
  const EventType& _type;
};

class CreationEvent : public Event
{
public:
  CreationEvent();
};

class DestructionEvent : public Event
{
public:
  DestructionEvent();
};

#endif
