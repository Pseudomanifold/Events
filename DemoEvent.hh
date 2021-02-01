#ifndef DEMO_EVENT_HH__
#define DEMO_EVENT_HH__

#include "Event.hh"

enum class EventType1 {
  TEST_EVENT,
  TEST_EVENT2,
  TEST_EVENT3
};

enum class EventType2 {
  TEST_EVENT,
  TEST_EVENT2,
  TEST_EVENT3
};

class DemoEvent : public Event<EventType1>
{
public:
  DemoEvent() : Event<EventType1>(EventType1::TEST_EVENT, "DemoEvent"){};
  virtual ~DemoEvent() = default;
};

class DemoEventAlt : public Event<EventType2>
{
private:
public:
  DemoEventAlt() : Event<EventType2>(EventType2::TEST_EVENT, "DemoEventAlt"){};
  virtual ~DemoEventAlt() = default;
};

#endif
