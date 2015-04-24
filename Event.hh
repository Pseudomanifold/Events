#ifndef EVENT_HH__
#define EVENT_HH__

#include <functional>
#include <string>

class Event
{
public:
  virtual~ Event();

  virtual std::size_t type() const = 0;
};

class CreationEvent : public Event
{
public:
  static std::size_t getType()
  {
    std::hash<std::string> hash;
    return hash( std::string("CreationEvent" ) );
  }

  virtual std::size_t type() const
  {
    return getType();
  }
};

class DestructionEvent : public Event
{
public:
  static std::size_t getType()
  {
    std::hash<std::string> hash;
    return hash( std::string("DestructionEvent" ) );
  }

  virtual std::size_t type() const
  {
    return getType();
  }
};

#endif
