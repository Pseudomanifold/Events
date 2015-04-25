#ifndef EVENT_HH__
#define EVENT_HH__

#include <string>

/**
  @class Event
  @brief Base class for all events

  This class provides the interface that needs to be implemented by an event.
  Each dependent class is required to implement type() to uniquely identify
  events. As a convenience, each class should have a static descriptor so that
  clients may refer to it without having to create an instance.

  Unfortunately, I have no idea how to enforce the existence of this attribute.
*/

class Event
{
public:
  virtual~ Event();

  typedef const char* DescriptorType;

  /** @returns The descriptor type of this event */
  virtual DescriptorType type() const = 0;
};

#endif
