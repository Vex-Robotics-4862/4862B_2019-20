#ifndef _STATE_MACHINE_HPP_
#define _STATE_MACHINE_HPP_

#include "main.h"

class StateMachine{
  State states[];

  public:
    StateMachine(State states[]);
    Poller handle();
};

class State{
  std::function<Poller(int)> stateAction;

  public:
    State(std::function<Poller(int)> stateAction);
    Poller do();
}

#endif //_STATE_MACHINE_HPP_
