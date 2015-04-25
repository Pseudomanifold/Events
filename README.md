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
