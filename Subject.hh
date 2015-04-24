#ifndef SUBJECT_HH__
#define SUBJECT_HH__

#include "Event.hh"

#include <functional>
#include <map>
#include <vector>

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
  Connection registerObserver( Event::EventType type, function_type&& function );
  void unregisterObserver( const Connection& connection );

  void notify( const Event& event ) const;

private:
  unsigned int _nextID = 0;
  std::map<Event::EventType, std::vector<FunctionHandle> > _observers;
};

#endif
