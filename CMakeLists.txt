CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
PROJECT( Events )

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic" )

ADD_EXECUTABLE( observer_demo
  Connection.cc
  Demo.cc
  DemoEvent.cc
  Dispatcher.cc
  Event.cc
)
