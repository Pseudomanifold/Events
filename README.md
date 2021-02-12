# Events

This repository contains a simple implementation of an event dispatcher.
Its design is inspired by the venerable [Observer
pattern](http://en.wikipedia.org/wiki/Observer_pattern), but it differs
in several ways:

* The event dispatcher offers a public interface for notifying
  observers. An event may thus be triggered externally. The client
  does not need to know anything about the observers.
* All participants in the event system are very loosely coupled. The
  dispatcher only knows about a base event class. Observers only need to
  provide a slot with a pre-defined interface.
* Observers may subscribe and unsubscribe from receiving events.

## Technical details

This implementation works using pure C++11 features. At the heart of the
event processing are arbitrary function objects. Each observer needs to
implement a slot with a certain interface. These function objects are
then stored in a map, which is indexed by an event descriptor.
~~Currently, the event descriptor is simply a `const char*`. This seemed
straightforward to implement.~~ The event descriptor has been updated to
handle arbitrary types, but the `map` idea is still being kept in place.
Upon posting new events, the dispatcher only needs to traverse the map
and call all correspond slots.

Please see the file `Demo.cc` for a simple demonstration.

## Limitations

Currently, I am assuming that everything runs in a single thread. The
processing gets slightly more complicated once observers are permitted
to receive objects in another thread. In this case, I would suggest
using `std::shared_ptr` to ensure that an event is not prematurely
destroyed. Maybe I will implement this someday...

## Criticism

I would welcome any critical comments regarding the design. I think that
the system is relatively small, efficient, and decoupled. Please help me
improve the code if you beg to differ!

## License

The code is released under the MIT license.
