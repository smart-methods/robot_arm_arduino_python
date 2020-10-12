#include <Servo.h> 
Servo gripper;
Servo wrist;
Servo elbow;
Servo shoulder;
Servo base;

double base_angle=90;
double shoulder_angle=90;
double elbow_angle=90;
double wrist_angle=90;
double gripper_angle=0;

double prev_base_angle=90;
double prev_shoulder_angle=90;
double prev_elbow_angle=90;
double prev_wrist_angle=90;

int gripperState = 0;
int pos = 0;

String data;
String data1;
String data2;
String data3;

double angle1;
double angle2;
double angle3;
double angle4;
 
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  base.attach(8);
  shoulder.attach(9);
  elbow.attach(10);
  wrist.attach(11);
  gripper.attach(12); 

  base.write(90);
  shoulder.write(90);
  elbow.write(90);
  wrist.write(90); 
  gripper.write(0);
}

void loop() {
  // use this text format to enter the angles by using the serial monitor:
  // 0.0,0.0,0.0,0.0
  // notice that all the angles in radian on ranges -1.57 to 1.57
  if (Serial.available() > 0) {
    data = Serial.readString(); //occupies 4 angels
    Serial.print(data);
    angle1 = data.substring(0, data.indexOf(",")).toDouble();
    Serial.print("base angle: ");
    Serial.println(angle1);
    data1 = data.substring(data.indexOf(",")+1, data.indexOf("\n")); //occupies last 3 angels
    angle2 = data1.substring(0, data1.indexOf(",")).toDouble();
    Serial.print("shoulder angle: ");
    Serial.println(angle2);
    data2 = data1.substring(data1.indexOf(",")+1, data1.indexOf("\n")); //occupies last 2 angels
    angle3 = data2.substring(0, data2.indexOf(",")).toDouble();
    Serial.print("elbow angle: ");
    Serial.println(angle3);
    data3 = data2.substring(data2.indexOf(",")+1, data2.indexOf("\n")); //occupies the last angel
    angle4 = data3.substring(0, data3.indexOf(",")).toDouble();
    Serial.print("wrist angle: ");
    Serial.println(angle4);
    
    base_angle=radiansToDegrees(angle1); 
    shoulder_angle=radiansToDegrees(angle2);
    elbow_angle=radiansToDegrees(angle3);
    wrist_angle=radiansToDegrees(angle4);
  
    //wrist
    if (wrist_angle < prev_wrist_angle)
    {
      for (pos = prev_wrist_angle; pos >= wrist_angle; pos -= 1) { 
        wrist.write(pos);              // tell servo to go to position in variable 'pos'
        delay(25);                       // waits 15ms for the servo to reach the position
      }
    }
    else if (wrist_angle > prev_wrist_angle)
    {
      for (pos = prev_wrist_angle; pos <= wrist_angle; pos += 1) { 
        wrist.write(pos);              // tell servo to go to position in variable 'pos'
        delay(25);                       // waits 15ms for the servo to reach the position
      }
    }
  
    //elbow
    if (elbow_angle < prev_elbow_angle)
    {
      for (pos = prev_elbow_angle; pos >= elbow_angle; pos -= 1) { 
        elbow.write(pos);              // tell servo to go to position in variable 'pos'
        delay(25);                       // waits 15ms for the servo to reach the position
      }
    }
    else if (elbow_angle > prev_elbow_angle)
    {
      for (pos = prev_elbow_angle; pos <= elbow_angle; pos += 1) { 
        elbow.write(pos);              // tell servo to go to position in variable 'pos'
        delay(25);                       // waits 15ms for the servo to reach the position
      }
    }
    
    //shoulder
    if (shoulder_angle < prev_shoulder_angle)
    {
      for (pos = prev_shoulder_angle; pos >= shoulder_angle; pos -= 1) { 
        shoulder.write(pos);              // tell servo to go to position in variable 'pos'
        delay(25);                       // waits 15ms for the servo to reach the position
      }
    }
    else if (shoulder_angle > prev_shoulder_angle)
    {
      for (pos = prev_shoulder_angle; pos <= shoulder_angle; pos += 1) { 
        shoulder.write(pos);              // tell servo to go to position in variable 'pos'
        delay(25);                       // waits 15ms for the servo to reach the position
      }
    }
  
    //base
    if (base_angle < prev_base_angle)
    {
      for (pos = prev_base_angle; pos >= base_angle; pos -= 1) { 
        base.write(pos);              // tell servo to go to position in variable 'pos'
        delay(25);                       // waits 15ms for the servo to reach the position
      }
    }
    else if (base_angle > prev_base_angle)
    {
      for (pos = prev_base_angle; pos <= base_angle; pos += 1) { 
        base.write(pos);              // tell servo to go to position in variable 'pos'
        delay(25);                       // waits 15ms for the servo to reach the position
      }
    }
  
    prev_base_angle = base_angle;
    prev_shoulder_angle = shoulder_angle;
    prev_elbow_angle = elbow_angle;
    prev_wrist_angle = wrist_angle;

    if (gripperState==0)
    {
      gripper.write(60);
      gripperState = 1;
    }
    else if (gripperState==1)
    {
      gripper.write(0);
      gripperState = 0;
    }
    Serial.println("Done!");
    Serial.println();
  }
}

double radiansToDegrees(float position_radians)
{

  position_radians = position_radians + 1.6;

  return position_radians * 57.2958;

}
