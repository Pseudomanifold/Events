#include "Event.hh"
#include "Connection.hh"
#include "Subject.hh"

#include <functional>
#include <iostream>

void freeObserver( const Event& event )
{
  if( event.type() == CreationEvent::getType() )
    std::cout << __PRETTY_FUNCTION__ << ": Creation" << std::endl;
  else if( event.type() == DestructionEvent::getType() )
    std::cout << __PRETTY_FUNCTION__ << ": Destruction" << std::endl;
}

class ClassObserver
{
public:
  void handleCreation( const Event& )
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  void handleDestruction( const Event& e )
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if( dynamic_cast<const DestructionEvent*>( &e ) )
      std::cout << __PRETTY_FUNCTION__ << ": Dynamic cast worked" << std::endl;
  }
};

int main( int, char** )
{
  ClassObserver classObserver;

  Subject s;
  s.registerObserver( CreationEvent::getType(),    freeObserver );
  s.registerObserver( DestructionEvent::getType(), freeObserver );
  auto handle = s.registerObserver( CreationEvent::getType(),    std::bind( &ClassObserver::handleCreation, &classObserver, std::placeholders::_1 ) );
  s.registerObserver( DestructionEvent::getType(), std::bind( &ClassObserver::handleDestruction, &classObserver, std::placeholders::_1 ) );

  CreationEvent creation;
  DestructionEvent destruction;

  s.notify( creation );
  s.notify( destruction );

  handle.disconnect();

  s.notify( creation );
  s.notify( destruction );

  return 0;
}
