float temp;
float vout;
float vout1;
int LED=13;
int gassensor;
int piezo=7;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  vout=analogRead(A1);
  vout1=(vout/1023)*5000;
  temp=(vout1-500)/10;
  gassensor=analogRead(A0);
  if(temp>=80)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
  if(gassensor>=100)
    digitalWrite(piezo, HIGH);
  else
    digitalWrite(piezo, LOW);
  Serial.print("In Degree= ");
  Serial.print(" ");
  Serial.print(temp);
  Serial.print("\t");
  Serial.print("Gas Sensor= ");
  Serial.print(" ");
  Serial.print(gassensor);
  Serial.println();
  delay(1000);
}