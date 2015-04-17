class Listener {

protected:
  virtual void on_Interval() = 0;
  virtual void on_Timer() = 0;
  
public:
  virtual void execute() = 0;  
};

class Scheduler {
private:
  // std::Vector<Listener> *_listeners;
public:
  // void addListener(Listener *pListener)
  // {
  //   _listener = pListener;
  // }
  
  // void tick()
  // {
  //   _listener->execute();
  // }
};

Scheduler scheduler;
Listener listener;

void setup() {
  Serial.begin(9600);
  scheduler.addListener(&listener);
}

void loop() {
  scheduler.tick();
}
