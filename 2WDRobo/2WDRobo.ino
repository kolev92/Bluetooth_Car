  
const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;
const int Motor2Pin1  = 10;
const int Motor2Pin2 = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
} 
  

void loop()
{
  if(Serial.available()>0)//Checking is Serial data available
  {
    char input = Serial.read(); //Storing value of read data into variable assigned
    
    switch(input)
    {
     case 'F' : moveForward(); //Calling respective functions if mathced with case label 
     break;
     case 'B' : moveBackward(); // here is it important to use '' as that stores the ASCII value is the letter in the variable
     break;
     case 'L' : moveLeft(); // and hence we can use the int keyword
     break;
     case 'R' : moveRight();
     break;
     case 'S' : Stop();
     break;
     default : break;
    }
  } 
  delay(50);
}

void moveBackward(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void moveForward(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void moveRight(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void moveLeft(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}

void Stop()
{
  Serial.println("<Robot Name> Stop");
  digitalWrite(Motor1Pin1,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
  digitalWrite(Motor1Pin2,LOW);
  digitalWrite(Motor2Pin1,LOW);
  digitalWrite(Motor2Pin2,LOW);
}
