#ifndef EVENT_HH__
#define EVENT_HH__

enum class EventType
{
  Creation = 0,
  Destruction
};

class Event
{
public:
  virtual~ Event();
  const EventType& type() const;

protected:
  Event( const EventType& type );

private:
  EventType _type;
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
