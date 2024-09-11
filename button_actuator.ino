 #include <Servo.h>

String command;
Servo servoMotor1;
Servo servoMotor2;
Servo servoMotor3;
Servo servoMotor4;

void setup() {
    servoMotor1.attach(16); // GPIO16 (D0)
    servoMotor2.attach(5);  // GPIO5 (D1)
    servoMotor3.attach(4);  // GPIO4 (D2)
    servoMotor4.attach(0);  // GPIO0 (D3)
    Serial.begin(115200);
    
    // Initial positions (adjust as needed)
    servoMotor1.write(90);
    delay(200); 
    servoMotor2.write(90);
    delay(200);
    servoMotor3.write(90); 
    delay(200);
    servoMotor4.write(90); 
    delay(200);
}

void loop() {
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the command from Serial input

        // for power button press
        if (command == "p:") {
            servoMotor1.write(180);
            delay(200);
            servoMotor1.write(90);
            Serial.println("0");
        }
        
        //action button
        else if (command == "a:b:") {
            servoMotor4.write(160);
            delay(1000);
            servoMotor4.write(90);
            Serial.println("0");
        }

        // press and hold action button with duration
                else if (command.startsWith("ab:") && command.endsWith(":") && (command.length() == 5 || command.length() == 6)) {
            String durationString = command.substring(3, command.length() - 1);
            int duration = durationString.toInt();
            if (duration >= 0 && duration <= 999) { 
                duration *= 1000;
                servoMotor4.write(160);
                delay(duration);
                servoMotor4.write(90);
                Serial.println("0");  
            }
        }
        
        
        // for volume up
        else if (command == "v:u:") { 
            servoMotor2.write(0);  
            delay(200);
            servoMotor2.write(90);
            Serial.println("0"); 
        } 
        // for volume dowm
        else if (command == "v:d:") { 
            servoMotor3.write(10);  
            delay(200);
            servoMotor3.write(90);
            Serial.println("0");
        }
        // press power button for 2 sec // shortcut
        else if (command == "p:2:") { 
            servoMotor1.write(180);
            delay(2000);
            servoMotor1.write(90);
            Serial.println("0");  
 
            Serial.println("0");
        }
        // power menu
                else if (command == "p:vd:2:") { 
            servoMotor1.write(180);
            servoMotor3.write(10);
            delay(2000);
            servoMotor1.write(90);
            servoMotor3.write(90);
            Serial.println("0");
        }

        // screenshot
                else if (command == "p:vu:") { 
            servoMotor1.write(180);
            servoMotor2.write(0);
            delay(200);
            servoMotor1.write(90);
            servoMotor2.write(90);
            Serial.println("0");
        }
        // press and hold power with duration
        else if (command.startsWith("p:") && command.endsWith(":") && (command.length() == 4 || command.length() == 5)) {
            String durationString = command.substring(2, command.length() - 1);
            int duration = durationString.toInt();
            if (duration >= 0 && duration <= 999) { 
                duration *= 1000;
                servoMotor1.write(180);
                delay(duration);
                servoMotor1.write(90);
                Serial.println("0");  
            }
        }
        // press and hold volume down with duration
                else if (command.startsWith("vd:") && command.endsWith(":") && (command.length() == 5 || command.length() == 6)) {
            String durationString = command.substring(3, command.length() - 1);
            int duration = durationString.toInt();
            if (duration >= 0 && duration <= 999) { 
                duration *= 1000;
                servoMotor3.write(10);
                delay(duration);
                servoMotor3.write(90);
                Serial.println("0");  
            }
        }
        // press and hold volume up with duration
        else if (command.startsWith("vu:") && command.endsWith(":") && (command.length() == 5 || command.length() == 6)) {
            String durationString = command.substring(3, command.length() - 1);
            int duration = durationString.toInt();
            if (duration >= 0 && duration <= 999) { 
                duration *= 1000;
                servoMotor2.write(0);
                delay(duration);
                servoMotor2.write(90);
                Serial.println("0");  
            }
        }

        // press and hold power and vol. down with duration
        else if (command.startsWith("p:vd:") || command.startsWith("vd:p:") && command.endsWith(":") && (command.length() == 7 || command.length() == 8)) {
            String durationString = command.substring(5, command.length() - 1);
            int duration = durationString.toInt();
            if (duration >= 0 && duration <= 999) { 
                duration *= 1000;
            servoMotor1.write(180);
            servoMotor3.write(10);
            delay(duration);
            servoMotor1.write(90);
            servoMotor3.write(90);
            Serial.println("0");  
            }
        }
        // press and hold power and vol. up with duration
        else if (command.startsWith("p:vu:") || command.startsWith("vu:p:") && command.endsWith(":") && (command.length() == 7 || command.length() == 8)) {
            String durationString = command.substring(5, command.length() - 1);
            int duration = durationString.toInt();
            if (duration >= 0 && duration <= 999) { 
                duration *= 1000;
            servoMotor1.write(180);
            servoMotor2.write(0);
            delay(duration);
            servoMotor1.write(90);
            servoMotor2.write(90);
            Serial.println("0");  
            }
        }
        // press and hold vol. up and vol. up with duration
        else if (command.startsWith("vu:vd:") || command.startsWith("vd:vu:") && command.endsWith(":") && (command.length() == 8 || command.length() == 9)) {
            String durationString = command.substring(6, command.length() - 1);
            int duration = durationString.toInt();
            if (duration >= 0 && duration <= 999) { 
                duration *= 1000;
            servoMotor2.write(0);
            servoMotor3.write(10);
            delay(duration);
            servoMotor2.write(90);
            servoMotor3.write(90);
            Serial.println("0");  
            }
        }

                else if (command.startsWith("p:t:") && command.endsWith(":")) {
            String tapString = command.substring(4, command.length() - 1);
            int tap = tapString.toInt();
            if (tap >= 0 && tap <= 999) {
              for(int i=0; i<tap; i++) {
                servoMotor1.write(180);
                delay(100);
                servoMotor1.write(60);
                delay(100);
            }
            servoMotor1.write(90);
            Serial.println("0");
        }

       }

            else if (command.startsWith("vu:t:") && command.endsWith(":")) {
            String tapString = command.substring(5, command.length() - 1);
            int tap = tapString.toInt();
            if (tap >= 0 && tap <= 999) {
              for(int i=0; i<tap; i++) {
                servoMotor2.write(0);
                delay(100);
                servoMotor2.write(120);
                delay(100);
            }
            servoMotor2.write(90);
            Serial.println("0");
        }

       }


                   else if (command.startsWith("ab:t:") && command.endsWith(":")) {
            String tapString = command.substring(5, command.length() - 1);
            int tap = tapString.toInt();
            if (tap >= 0 && tap <= 999) {
              for(int i=0; i<tap; i++) {
                servoMotor4.write(160);
                delay(100);
                servoMotor4.write(120);
                delay(100);
            }
            servoMotor4.write(90);
            Serial.println("0");
        }

       }

            else if (command.startsWith("vd:t:") && command.endsWith(":")) {
            String tapString = command.substring(5, command.length() - 1);
            int tap = tapString.toInt();
            if (tap >= 0 && tap <= 999) {
              for(int i=0; i<tap; i++) {
                servoMotor3.write(10);
                delay(100);
                servoMotor3.write(60);
                delay(100);
            }
            servoMotor3.write(90);
            Serial.println("0");
        }

       }
       else if (Serial.println("13"));

        command = "";
    }
}
