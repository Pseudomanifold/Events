#ifndef CONNECTION_HH__
#define CONNECTION_HH__

// Forward declaration is sufficient here because we only store reference to
// the dispatcher.
class Dispatcher; 

/**
  @class Connection
  @brief Describes connections to observer slots
*/

class Connection
{

public:
  /**
    Sets up an invalid connection, i.e. one that is not connected to a
    dispatcher. This constructor is required to be able to store connections in
    a container member variable of class, for example.
  */

  Connection();

  /** @returns ID of the connection */
  unsigned int id() const;

  /** Attempts to disconnect the connection from the dispatcher. */
  void disconnect();

private:
 
  /**
    Sets up a valid connection that belongs to a dispatcher and is identified
    by some ID.
  */
  
  Connection( Dispatcher* dispatcher, unsigned int id ); 

  /** Dispatcher that created this connection */
  Dispatcher* _dispatcher = nullptr;

  /** Identifier for this connection */
  unsigned int _id = 0;

  /**
    Since the constructor that yields a valid connection is private, this
    ensures that the dispatcher is the only class that is capable of creating
    a valid connection object.
  */
  
  friend class Dispatcher;
};

#endif
