
int G = 3; 
int R = 5;
int B = 6;// the PWM pin the LED is attached to

int brightness_G = 255;
int brightness_R = 100; 
int brightness_B = 255; // how bright the LED is
String data;

// the setup routine runs once when you press reset:
void setup() 
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(50);
}

void loop() {
  // set the brightness of pin 9:
  if ( Serial.available () > 0 )
  {
    data = Serial.readString();
  }
  brightness_R = 255-((data[0]-48)*25.5);
  brightness_G = 255-((data[1]-48)*25.5);
  brightness_B = 255-((data[2]-48)*25.5);
  analogWrite(R, brightness_R);
  analogWrite(G, brightness_G);
  analogWrite(B, brightness_B);
  Serial.println(brightness_R, DEC);
  Serial.println(brightness_G, DEC);
  Serial.println(brightness_B, DEC);
  delay(100);
}
