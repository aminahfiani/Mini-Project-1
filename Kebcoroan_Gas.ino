//Mendeteksi Kebocoran Gas

#define MQ2Pin 2
#define relayPin 10

int MQ2Val; //variable to store sensor value
const int Speaker = 7;

void setup() 
{
 pinMode(MQ2Pin, INPUT);
 pinMode(relayPin, OUTPUT);
 pinMode(Speaker, OUTPUT);
 Serial.begin(9600);
 Serial.println("Mendeteksi Gas Bocor");
 delay(1000); //allow the MQ-6 to warm up
}

void loop() 
{
  MQ2Val= digitalRead(MQ2Pin);
  Serial.print("Nilai Sensor : ");
  Serial.println(MQ2Val);

  if(MQ2Val == HIGH)
  {
    Serial.println("Ada Gas Bocor!!");
    digitalWrite(relayPin,HIGH);
    tone(7,1000);
  }
  else
  {
    Serial.println("Amann Tidak Ada Gas Bocor");
    digitalWrite(relayPin, LOW);
    noTone(7);
  }
  Serial.println("");
  delay(1000);
  }
