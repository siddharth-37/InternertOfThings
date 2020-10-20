#define ANALOG_IN_PIN A1
#define VIBRATION_SENSOR_PIN 3

float temp;
int tempPin = A0;

int sensorPin=4;
boolean val =0;


int motionDetected = HIGH;

int sensorVal = 0;

int LED_Pin=13;
int ledpin=5;
int Ledpin=12;
 
void setup() 
{
   pinMode(LED_Pin, OUTPUT);
   pinMode(ledpin, OUTPUT);
   pinMode(Ledpin,OUTPUT);
   pinMode(sensorPin, INPUT);
   Serial.begin(115200);
}
 
void loop() 
{
   Serial.println("vibration sensor detection");
   delay(1000);
   motionDetected = digitalRead(VIBRATION_SENSOR_PIN);
   sensorVal = analogRead(ANALOG_IN_PIN);
   Serial.print("Anaologue: ");
   Serial.print(sensorVal);
   delay(1000);
   Serial.print(" Digital :");
   Serial.println(motionDetected);
   delay(1000);
   if (sensorVal<1000)
   {
    Serial.println("led off");
    digitalWrite(LED_Pin, LOW);
  }
  else
  {
   Serial.println("led on");
   digitalWrite(LED_Pin, HIGH);
  }
  delay(2000);
  Serial.println("sound sensor detection");
  delay(1000);
    val =digitalRead(sensorPin);
    Serial.println (val);
   if (val==1)  
  {
    Serial.println ("led on");
    digitalWrite(ledpin, HIGH);
    delay(2000);
  }
  else 
  {
    Serial.println ("led off");
    digitalWrite(ledpin, LOW);
  }
  delay(2000);
   Serial.println("temperature detection");
   temp = analogRead(tempPin);
   temp = temp * 0.48828125;
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // display temperature value
   Serial.print("*C");
   Serial.println();
   if(temp>25)
   {
    Serial.println("led on");
   digitalWrite(Ledpin,HIGH);
   }
   else
   {
    Serial.println("led off");
    digitalWrite(Ledpin,LOW);
   }
   delay(1000);
 }
