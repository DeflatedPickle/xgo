#include <Dog>

Dog dog = new Dog();

void setup() {
  dog.setup();
}

void loop() {
  dog.controller.walk(Axis.X, Direction.FORWARD, 100);
  delay(1);
  dog.controller.walk(Axis.X, Direction.FORWARD, 0);
  delay(1);
  dog.controller.walk(Axis.X, Direction.BACKWARD, 100);
  delay(1);
  dog.controller.walk(Axis.X, Direction.FORWARD, 0);
  delay(1);
}
