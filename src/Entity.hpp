#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Utils.hpp"

#include <functional>

class Entity {
public:
  Position realPos;
  Position gridPos;
  Size size;
  virtual void onClick() {}
  virtual void init() {}
  virtual void update() {}
  
  void checkClick() {
    
  }
};

#endif