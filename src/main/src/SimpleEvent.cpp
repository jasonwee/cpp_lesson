#include <iostream>

class Condition
{
public:
  Condition() {}
  virtual ~Condition() {}
  virtual void log() = 0;
};

class Normal : public Condition
{
public:
  Normal() { log(); }
  virtual ~Normal() {}
  virtual void log()
      { std::cout << "Logging normal conditions ...\n"; }
};

class Error : public Condition
{
public:
  Error() { log(); }
  virtual ~Error() {}
  virtual void log() { std::cout << "Logging error!\n"; }
};

class Alarm : public Condition
{
public:
  Alarm();
  virtual ~Alarm() {}
  virtual void warn() { std::cout << "Warning!\n"; }
  virtual void log() { std::cout << "General alarm log\n"; }
  virtual void call() = 0;
};

Alarm::Alarm()
{
  log();
  warn();
}

class FireAlarm : public Alarm
{
public:
  FireAlarm() { log(); };
  virtual ~FireAlarm() {}
  virtual void call() { std::cout << "Calling fire department!\n"; }
  virtual void log() { std::cout << "Logging fire call\n"; }
};

int main()
{
  int input;
  int okay = 1;
  Condition *pCondition;
  while (okay)
  {
    std::cout << "(0) Quit (1) Normal (2) Fire: ";
    std::cin >> input;
    okay = input;
    switch(input)
    {
    case 0:
      break;
    case 1:
      pCondition = new Normal;
      delete pCondition;
      break;
    case 2:
      pCondition = new FireAlarm;
      delete pCondition;
      break;
    default:
      pCondition = new Error;
      delete pCondition;
      okay = 0;
      break;
    }
  }
  return 0;
}
