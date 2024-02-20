const int Motor1Pin1 = 2; //заден ляв
const int Motor1Pin2 = 3; //заден ляв
const int Motor2Pin1 = 4; //преден ляв
const int Motor2Pin2 = 5; //преден ляв
const int Motor3Pin1 = 6; //заден десен
const int Motor3Pin2 = 7; //заден десен
const int Motor4Pin1 = 8; //преден десен
const int Motor4Pin2 = 9; //преден десен

void setup()
{
  Serial.begin(9600);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
  pinMode(Motor3Pin1, OUTPUT);   
  pinMode(Motor3Pin2, OUTPUT);   
  pinMode(Motor4Pin1, OUTPUT);   
  pinMode(Motor4Pin2, OUTPUT);
} 
  

void loop()
{
  if(Serial.available()>0)//Checking is Serial data available
  {
    char input = Serial.read();
    Serial.println(input);
    switch(input)
    {
     case 'F' : moveForward();
     break;
     case 'B' : moveBackward();
     break;
     case 'L' : moveLeft();
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
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
  digitalWrite(Motor3Pin1, LOW);
  digitalWrite(Motor3Pin2, HIGH);
  digitalWrite(Motor4Pin1, LOW);
  digitalWrite(Motor4Pin2, HIGH);
}

void moveForward(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
  digitalWrite(Motor3Pin1, HIGH);
  digitalWrite(Motor3Pin2, LOW);
  digitalWrite(Motor4Pin1, HIGH);
  digitalWrite(Motor4Pin2, LOW);
}

void moveRight(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void moveLeft(){
  digitalWrite(Motor3Pin1, HIGH);
  digitalWrite(Motor3Pin2, LOW);
  digitalWrite(Motor4Pin1, HIGH);
  digitalWrite(Motor4Pin2, LOW);
 
}

void Stop()
{
  Serial.println("Stop");
  digitalWrite(Motor1Pin1,LOW);
  digitalWrite(Motor1Pin2,LOW);
  digitalWrite(Motor2Pin1,LOW);
  digitalWrite(Motor2Pin2,LOW);
  digitalWrite(Motor3Pin1,LOW);
  digitalWrite(Motor3Pin2,LOW);
  digitalWrite(Motor4Pin1,LOW);
  digitalWrite(Motor4Pin2,LOW);
}
