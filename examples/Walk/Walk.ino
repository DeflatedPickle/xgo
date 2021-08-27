#include <Dog.h>

Dog* dog = new Dog();

void setup() {
  dog->setup();
}

void loop() {
  dog->controller->walk(Axis::X, 255);
  delay(1);
  dog->controller->walk(Axis::X, 0);
  delay(1);
  dog->controller->walk(Axis::X, 255);
  delay(1);
  dog->controller->walk(Axis::X, 0);
  delay(1);
}
