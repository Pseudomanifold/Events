#ifndef DEMO_EVENT_HH__
#define DEMO_EVENT_HH__

#include "Event.hh"

class DemoEvent : public Event
{
public:
  DemoEvent();
  virtual ~DemoEvent();

  static constexpr DescriptorType descriptor = "DemoEvent";

  virtual DescriptorType type() const;
};

#endif
