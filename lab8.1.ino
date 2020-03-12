 
#define LED_PIN 11
#define LED_PIN2 10
float brightness = 0;
String buff;
int LED;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  pinMode(LED_PIN2,OUTPUT);
}

void loop()
{
  if(Serial.available()>0)
  {
    char inByte = Serial.read();
    if(inByte == '1')
    LED = LED_PIN;
    if(inByte == '2')
    LED = LED_PIN2;
    if(inByte == 'B')
    {
    buff = ' ';
    }
    if(('0'<=inByte)&&(inByte<='9'))
    {
      buff += inByte;
    }
    if(inByte =='\n')
    {
    brightness = buff.toInt();
    Serial.println(brightness);
    analogWrite(LED,int(brightness*2.54));
    }
  }
}
