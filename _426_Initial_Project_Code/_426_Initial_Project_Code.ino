const int direct_pin_1 = 12;
const int direct_pin_2 = 13;
const int pwm_pin_1 = 3;
const int pwm_pin_2 = 11;
const int brake_pin_1 = 9;
const int brake_pin_2 = 8;

void setup() {
  
  //Setup Channel A
  pinMode(direct_pin_1, OUTPUT); //Initiates Motor Channel A pin
  pinMode(brake_pin_1, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(direct_pin_2, OUTPUT); //Initiates Motor Channel A pin
  pinMode(brake_pin_2, OUTPUT);  //Initiates Brake Channel A pin
  
}

void loop(){
  
  AforwardBbackward();
  runAndbrake();

  AbackwardBforward();
  runAndbrake();
  
  allForward();   
  runAndbrake();

  allBackward();
  runAndbrake();

  AForwardOnly();
  runAndbrake();

  BForwardOnly();
  runAndbrake();

  ABackwardOnly();
  runAndbrake();

  BBackwardOnly();
  runAndbrake();

  
}

void AforwardBbackward()
{
  //Motor A forward @ full speed
  digitalWrite(direct_pin_1, HIGH); //Establishes forward direction of Channel A
  digitalWrite(brake_pin_1, LOW);   //Disengage the Brake for Channel A
  analogWrite(pwm_pin_1, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ full speed
  digitalWrite(direct_pin_2, LOW);  //Establishes backward direction of Channel B
  digitalWrite(brake_pin_2, LOW);   //Disengage the Brake for Channel B
  analogWrite(pwm_pin_2, 255);    //Spins the motor on Channel B at full speed
}

void AbackwardBforward()
{
  //Motor A backward @ full speed
  digitalWrite(direct_pin_1, LOW); //Establishes forward direction of Channel A
  digitalWrite(brake_pin_1, LOW);   //Disengage the Brake for Channel A
  analogWrite(pwm_pin_1, 255);   //Spins the motor on Channel A at full speed

  //Motor B forward @ full speed
  digitalWrite(direct_pin_2, HIGH);  //Establishes backward direction of Channel B
  digitalWrite(brake_pin_2, LOW);   //Disengage the Brake for Channel B
  analogWrite(pwm_pin_2, 255);    //Spins the motor on Channel B at full speed
}

void allForward()
{
  //Motor A forward @ full speed
  digitalWrite(direct_pin_1, HIGH);  //Establishes backward direction of Channel A
  digitalWrite(brake_pin_1, LOW);   //Disengage the Brake for Channel A
  analogWrite(pwm_pin_1, 255);    //Spins the motor on Channel A at half speed
  
  //Motor B forward @ full speed
  digitalWrite(direct_pin_2, HIGH); //Establishes forward direction of Channel B
  digitalWrite(brake_pin_2, LOW);   //Disengage the Brake for Channel B
  analogWrite(pwm_pin_2, 255);   //Spins the motor on Channel B at full speed
}

void allBackward()
{
  //Motor A backward @ full speed
  digitalWrite(direct_pin_1, LOW);  //Establishes backward direction of Channel A
  digitalWrite(brake_pin_1, LOW);   //Disengage the Brake for Channel A
  analogWrite(pwm_pin_1, 255);    //Spins the motor on Channel A at half speed
  
  //Motor B backward @ full speed
  digitalWrite(direct_pin_2, LOW); //Establishes forward direction of Channel B
  digitalWrite(brake_pin_2, LOW);   //Disengage the Brake for Channel B
  analogWrite(pwm_pin_2, 255);   //Spins the motor on Channel B at full speed
}

void AForwardOnly()
{
  //Motor A forward @ full speed
  digitalWrite(direct_pin_1, HIGH);  //Establishes backward direction of Channel A
  digitalWrite(brake_pin_1, LOW);   //Disengage the Brake for Channel A
  analogWrite(pwm_pin_1, 255);    //Spins the motor on Channel A at half speed
  
  //Motor B stopped
  digitalWrite(direct_pin_2, LOW); //Establishes forward direction of Channel B
  digitalWrite(brake_pin_2, LOW);   //Disengage the Brake for Channel B
  analogWrite(pwm_pin_2, 0);   //Spins the motor on Channel B at full speed
}

void BForwardOnly()
{
  //Motor A stopped
  digitalWrite(direct_pin_1, LOW);  //Establishes backward direction of Channel A
  digitalWrite(brake_pin_1, LOW);   //Disengage the Brake for Channel A
  analogWrite(pwm_pin_1, 0);    //Spins the motor on Channel A at half speed
  
  //Motor B forward @ full speed
  digitalWrite(direct_pin_2, HIGH); //Establishes forward direction of Channel B
  digitalWrite(brake_pin_2, LOW);   //Disengage the Brake for Channel B
  analogWrite(pwm_pin_2, 255);   //Spins the motor on Channel B at full speed
}

void ABackwardOnly()
{
  //Motor A backward @ full speed
  digitalWrite(direct_pin_1, LOW);  //Establishes backward direction of Channel A
  digitalWrite(brake_pin_1, LOW);   //Disengage the Brake for Channel A
  analogWrite(pwm_pin_1, 255);    //Spins the motor on Channel A at half speed
  
  //Motor B stopped
  digitalWrite(direct_pin_2, LOW); //Establishes forward direction of Channel B
  digitalWrite(brake_pin_2, LOW);   //Disengage the Brake for Channel B
  analogWrite(pwm_pin_2, 0);   //Spins the motor on Channel B at full speed
}

void BBackwardOnly()
{
  //Motor A stopped
  digitalWrite(direct_pin_1, LOW);  //Establishes backward direction of Channel A
  digitalWrite(brake_pin_1, LOW);   //Disengage the Brake for Channel A
  analogWrite(pwm_pin_1, 0);    //Spins the motor on Channel A at half speed
  
  //Motor B backward @ full speed
  digitalWrite(direct_pin_2, LOW); //Establishes forward direction of Channel B
  digitalWrite(brake_pin_2, LOW);   //Disengage the Brake for Channel B
  analogWrite(pwm_pin_2, 255);   //Spins the motor on Channel B at full speed
}

void brake()
{
  digitalWrite(brake_pin_1, HIGH);  //Engage the Brake for Channel A
  digitalWrite(brake_pin_2, HIGH);  //Engage the Brake for Channel B
}

void runAndbrake()
{
  delay(3000);
  brake();
}

