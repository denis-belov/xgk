struct Loop {
	bool indicator;
  uint8_t state;
  void (*switch_array[2]) ();


  Loop ();

  void run (
    void (*) ());

  void stop ();
};
