#ifndef _POLLER_HPP_
#define _POLLER_HPP_

#include "main.h"

enum ActionState {
  STARTED = 0,
  CUSTOM1 = 1, // CUSTOM are for defined points along the action
  CUSTOM2 = 2,
  CUSTOM3 = 3,
  SETTLING = 4,
  DONE = 5
};

class Poller {
  std::function<bool(ActionState)> isDone;
  public:
    Poller(std::function<bool(ActionState)> isDone);

    ActionState getActionState();

    ActionState wait(ActionState actionState);
};

#endif //_POLLER_HPP_
