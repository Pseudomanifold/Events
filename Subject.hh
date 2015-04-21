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

  void registerObserver( const EventType& type, function_type&& function );
  void unregisterObserver( const Connection& connection );

  void notify( const Event& event ) const;

private:
  std::map< EventType, std::vector<function_type> > _observers;
};

#endif
