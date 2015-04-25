#include "DemoEvent.hh"

#include <iostream>

// This definition is still required in order to comply with the ODR of C++.
constexpr DemoEvent::DescriptorType DemoEvent::descriptor;

DemoEvent::DemoEvent()
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

DemoEvent::~DemoEvent()
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Event::DescriptorType DemoEvent::type() const
{
  return descriptor;
}
