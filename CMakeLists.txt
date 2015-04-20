CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
PROJECT( Observer )

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic" )

ADD_EXECUTABLE( observer_demo
  Demo.cc
  Event.cc
  Observer.cc
)
