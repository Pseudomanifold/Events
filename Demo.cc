#include "Connection.hh"
#include "DemoEvent.hh"
#include "Dispatcher.hh"

#include <functional>
#include <iostream>

void freeObserver( const Event& event )
{
  if( event.type() == DemoEvent::descriptor )
    std::cout << __PRETTY_FUNCTION__ << ": DemoEvent" << std::endl;
}

class ClassObserver
{
public:
  void handle( const Event& e )
  {
    if( e.type() == DemoEvent::descriptor )
    {
      // This demonstrates how to obtain the underlying event type in case a
      // slot is set up to handle multiple events of different types.
      const DemoEvent& demoEvent = static_cast<const DemoEvent&>( e );
      std::cout << __PRETTY_FUNCTION__ << ": " << demoEvent.type() << std::endl;
    }
  }
};

int main( int, char** )
{
  ClassObserver classObserver;

  Dispatcher dispatcher;

  auto connection1 = dispatcher.subscribe( DemoEvent::descriptor, freeObserver );
  auto connection2 = dispatcher.subscribe( DemoEvent::descriptor,
                                           std::bind( &ClassObserver::handle, 
                                                      classObserver,
                                                      std::placeholders::_1 ) );

  std::cout << "#\n"
            << "# Posting a demo event. This should trigger two observers\n"
            << "#\n";

  dispatcher.post( DemoEvent() );

  connection1.disconnect();

  std::cout << "#\n"
            << "# Posting a demo event. This should trigger one observer\n"
            << "#\n";

  dispatcher.post( DemoEvent() );

  connection2.disconnect();

  std::cout << "#\n"
            << "# Posting a demo event. This should trigger no observers\n"
            << "#\n";

  dispatcher.post( DemoEvent() );

  // Multiple disconnects are not harmful
  connection1.disconnect();
  connection2.disconnect();

  return 0;
}
