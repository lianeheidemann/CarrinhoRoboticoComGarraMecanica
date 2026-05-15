#include <Servo.h>

// ================= SERVOS =================
Servo myservo1; // Garra
Servo myservo2; // Braço

int servo1 = 100;
int servo2 = 80;

// ================= MOTORES =================
int Pin4 = 4;
int Pin5 = 5;
int Pin6 = 6;
int Pin7 = 7;

// ================= BLUETOOTH =================
char val;

void setup() {

    Serial.begin(9600);

    pinMode(Pin4, OUTPUT);
    pinMode(Pin5, OUTPUT);
    pinMode(Pin6, OUTPUT);
    pinMode(Pin7, OUTPUT);

    // Motores desligados
    digitalWrite(Pin4, LOW);
    digitalWrite(Pin5, LOW);
    digitalWrite(Pin6, LOW);
    digitalWrite(Pin7, LOW);

    // Servos
    myservo1.attach(9);
    myservo2.attach(8);

    myservo1.write(servo1);
    myservo2.write(servo2);
}

void loop() {

    if (Serial.available() > 0) {

        val = Serial.read();

        // ================= FRENTE =================
        if (val == 'G') {

            digitalWrite(Pin4, LOW);
            digitalWrite(Pin5, HIGH);
            digitalWrite(Pin6, LOW);
            digitalWrite(Pin7, HIGH);
        }

        // ================= TRÁS =================
        else if (val == 'F') {

            digitalWrite(Pin4, HIGH);
            digitalWrite(Pin5, LOW);
            digitalWrite(Pin6, HIGH);
            digitalWrite(Pin7, LOW);
        }

        // ================= PARAR =================
        else if (val == 'S') {

            digitalWrite(Pin4, LOW);
            digitalWrite(Pin5, LOW);
            digitalWrite(Pin6, LOW);
            digitalWrite(Pin7, LOW);
        }

        // ================= ESQUERDA =================
        else if (val == 'R') {

            digitalWrite(Pin4, HIGH);
            digitalWrite(Pin5, LOW);
            digitalWrite(Pin6, LOW);
            digitalWrite(Pin7, LOW);
        }

        // ================= DIREITA =================
        else if (val == 'L') {

            digitalWrite(Pin4, LOW);
            digitalWrite(Pin5, LOW);
            digitalWrite(Pin6, HIGH);
            digitalWrite(Pin7, LOW);
        }

        // ================= FECHAR GARRA =================
        else if (val == '8') {

            for (servo1 = 100; servo1 <= 130; servo1++) {

                myservo1.write(servo1);
                delay(20);
            }

            for (servo2 = 80; servo2 >= 60; servo2--) {

                myservo2.write(servo2);
                delay(20);
            }
        }

        // ================= ABRIR GARRA =================
        else if (val == '7') {

            for (servo2 = 60; servo2 <= 80; servo2++) {

                myservo2.write(servo2);
                delay(20);
            }

            for (servo1 = 130; servo1 >= 100; servo1--) {

                myservo1.write(servo1);
                delay(20);
            }
        }
    }
}
