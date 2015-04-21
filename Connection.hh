#ifndef CONNECTION_HH__
#define CONNECTION_HH__

class Subject;

class Connection
{
public:
  Connection( Subject& subject, unsigned int id );

  unsigned int id() const;

  void disconnect();

private:
  Subject& _subject;
  unsigned int _id;
};

#endif
