#include <Servo.h>

class ServoMotor {
private:
    Servo servo;
    uint8_t pin;
    int currentAngle;

public:
    ServoMotor(uint8_t servoPin)
        : pin(servoPin), currentAngle(90) {}

    void begin(int initialAngle = 90) {
        servo.attach(pin);
        setAngle(initialAngle);
    }

    void setAngle(int angle) {
        angle = constrain(angle, 0, 180);
        servo.write(angle);
        currentAngle = angle;
    }

    int getAngle() const {
        return currentAngle;
    }

    void detach() {
        servo.detach();
    }

    void attach() {
        if (!servo.attached()) {
            servo.attach(pin);
            servo.write(currentAngle);
        }
    }

    bool isAttached() const {
        return servo.attached();
    }
};

ServoMotor motor(10);

void setup() {
    motor.begin(90);  // připojení na pin 9, počáteční úhel 90°
}

void loop() {
    motor.setAngle(0);
    delay(1000);

    motor.setAngle(90);
    delay(1000);

    motor.setAngle(180);
    delay(1000);
}