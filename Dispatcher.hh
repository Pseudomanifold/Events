#ifndef DISPATCHER_HH__
#define DISPATCHER_HH__

#include "Event.hh"

#include <functional>
#include <map>
#include <vector>

// A forward declaration is sufficient here as the dispatcher does not store
// connections themselves.
class Connection;

/**
  @class Dispatcher
  @brief Dispatches events to observers

  The dispatcher is the central class for event management. It offers clients
  the opportunity to use post() to submit a given event. Said event is then
  passed on to all observers that are listening to it. The dispatcher also
  handles new observers via subscribe() and permits the removal of observers
  via disconnect().
*/

class Dispatcher
{
public:

  /**
    Describes the slot an observer has to implement to be able to process
    events that are posted.
  */
    
  using SlotType = std::function< void( const Event& ) >;

  /**
    Subscribes a given slot to a certain event descriptor. The slot will be
    called whenever an event of the specified type has been posted. The order
    in which observers subscribe to certain events matters.

    @param descriptor Event to listen for
    @param slot       Slot to call in case such an event occurs

    @returns Connection handle to identify the observing slot
  */

  Connection subscribe( const Event::DescriptorType& descriptor,
                        SlotType&& slot );

  /**
    Unsubscribes an observer from receiving further events. The observer is
    identified by a connection object.

    @param connection Connection handle identifying the observer
  */

  void unsubscribe( const Connection& connection );

  /**
    Posts an event to all connected observers. This function has no way of
    knowing whether the event has been processed correctly. It will merely
    pass it on to anyone who might listen.

    @param event Event
  */

  void post( const Event& event ) const;

private:

  /** Internal ID to assign to the next function handle */
  unsigned int _nextID = 0;

  /**
    @struct SlotHandle
    @brief  Auxiliary data structure for managing slots
  */

  struct SlotHandle
  {
    unsigned int id;
    SlotType slot;
  };

  /**
    Maps event descriptors to a vector of slot handles. Each slot handle has a
    unique ID and a corresponding slot that is to be called when an event
    occurs.
  */
     
  std::map< Event::DescriptorType, std::vector<SlotHandle> > _observers;
};

#endif
