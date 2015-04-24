#ifndef EVENT_HH__
#define EVENT_HH__

#include <string>

class Event
{
public:
  virtual~ Event();

  typedef const char* EventType;

  virtual EventType type() const = 0;
};

class CreationEvent : public Event
{
public:
  static constexpr EventType eventType = "CreationEvent";

  virtual EventType type() const
  {
    return eventType;
  }
};

class DestructionEvent : public Event
{
public:
  static constexpr EventType eventType = "DestructionEvent";

  virtual EventType type() const
  {
    return eventType;
  }
};

#endif
