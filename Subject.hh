#ifndef SUBJECT_HH__
#define SUBJECT_HH__

#include <functional>
#include <map>
#include <vector>

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
  Connection registerObserver( std::size_t type, function_type&& function );
  void unregisterObserver( const Connection& connection );

  void notify( const Event& event ) const;

private:
  unsigned int _nextID = 0;
  std::map<std::size_t, std::vector<FunctionHandle> > _observers;
};

#endif
