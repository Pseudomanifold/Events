#include "Subject.hh"
#include "Event.hh"

#include <functional>
#include <iostream>

void freeObserver( const Event& event )
{
  if( event.type() == EventType::Creation )
    std::cout << __PRETTY_FUNCTION__ << ": Creation" << std::endl;
  else if( event.type() == EventType::Destruction )
    std::cout << __PRETTY_FUNCTION__ << ": Destruction" << std::endl;
}

class ClassObserver
{
public:
  void handleCreation( const Event& )
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  void handleDestruction( const Event& )
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
};

int main( int, char** )
{
  ClassObserver classObserver;

  Subject s;
  s.registerObserver( EventType::Creation,    freeObserver );
  s.registerObserver( EventType::Destruction, freeObserver );
  //s.registerObserver( EventType::Creation,    std::bind( &classObserver.handleCreation, &classObserver ) );

  CreationEvent creation;
  DestructionEvent destruction;

  s.notify( creation );
  s.notify( destruction );

  return 0;
}
