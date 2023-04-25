#include "time.h"
#include <iostream>

int Time::getHour() const { return hour; }

void Time::setHour(int newHour) {
  if (newHour >= 0 && newHour <= 23)
    hour = newHour;
}

int Time::getMin() const { return min; }

void Time::setMin(int newMin) {
  if (newMin >= 0 && newMin <= 59)
    min = newMin;
}

int Time::getSec() const { return sec; }

void Time::setSec(int newSec) {
  if (newSec >= 0 && newSec <= 59)
    sec = newSec;
}

void Time::print24() {
  std::cout << hour << " годин " << min << " хвилин " << sec << " секунд"
            << std::endl;
}

void Time::print12() {
  if (hour >= 0 && hour <= 12)
    std::cout << hour << " a.m. ";
  else
    std::cout << hour - 12  << " p.m ";
  std::cout << min << " хвилин " << sec << " секунд" << std::endl;
}

Time::Time() {
  hour = 0;
  min = 0;
  sec = 0;
}

Time::Time(int h, int m, int s) {
  hour = h;
  min = m;
  sec = s;
}

