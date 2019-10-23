void blank_func () {};

Loop::Loop () {
	indicator = true;
  state = 0;
  switch_array[0] = blank_func;
  switch_array[1] = nullptr;
};

void Loop::run (void (*on_state_change_func) ()) {
  switch_array[1] = on_state_change_func;

  while (indicator) {
    switch_array[state]();
  }
};

void Loop::stop () {
  indicator = false;
};
