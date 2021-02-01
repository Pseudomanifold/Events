#ifndef DISPATCHER_HH__
#define DISPATCHER_HH__

#include "Event.hh"

#include <functional>
#include <map>
#include <vector>
#include <algorithm>

// A forward declaration is sufficient here as the dispatcher does not store
// connections themselves.
// class Connection;

/**
  @class Dispatcher
  @brief Dispatches events to observers

  The dispatcher is the central class for event management. It offers clients
  the opportunity to use post() to submit a given event. Said event is then
  passed on to all observers that are listening to it. The dispatcher also
  handles new observers via subscribe() and permits the removal of observers
  via disconnect().
*/

template<typename T>
class Dispatcher{
private:
  using SlotType = std::function<void(const Event<T>&)>;
  std::map<T, std::vector<SlotType>> _observers;
public:

  /**
   * Subscribe an observer
   * @param type  The type of the function to listen to.
   * @param funct function of the observer
   */
  void subscribe(T type, const SlotType& funct){
    _observers[type].push_back(funct);
  };

  /**
   * Send the event to all the observers
   * @param event event to post
   */
  void post(Event<T>& event){
    if(_observers.find(event.type()) == _observers.end())
      return;

    //Loop though all observers. If the event is not handled yet we continue to process it.
    for(auto&& observer : _observers.at(event.type())){
      if(!event.isHandled()) observer(event);  
    }
  };
private:
};
#endif
