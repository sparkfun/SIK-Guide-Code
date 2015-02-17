//description

void setup()
{
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
}

void loop()
{
//Green Light
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
delay();
//Yellow Light
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(11,LOW);
delay();
//Red Light
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,HIGH);
}
