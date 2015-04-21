#ifndef SUBJECT_HH__
#define SUBJECT_HH__

#include <functional>
#include <map>
#include <vector>

// FIXME: Should be forwarded in a header or something
enum class EventType;
class Event;
class Connection;

class Subject
{
public:
  typedef std::function< void( const Event& ) > function_type;

private:
  struct FunctionHandle
  {
    unsigned int id;
    function_type f;
  };

public:
  Connection registerObserver( const EventType& type, function_type&& function );
  void unregisterObserver( const Connection& connection );

  void notify( const Event& event ) const;

private:
  unsigned int _nextID = 0;
  std::map<EventType, std::vector<FunctionHandle> > _observers;
};

#endif
