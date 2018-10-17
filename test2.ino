//1.流水灯测试程序
//@author hyw
//@data   2018/08/28
/*unsigned int i=0,j=2,k=2;
void setup(){
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(A0,OUTPUT);
    pinMode(A1,OUTPUT);
    pinMode(A2,OUTPUT);

    Serial.begin(9600);
}
void loop(){
    for(i=0;i<3;i++){
        digitalWrite(j,HIGH);
        delay(100);
        j++;
        Serial.println(j);
    }
    j=2;
    for(i=0;i<3;i++){
        digitalWrite(k,LOW);
        delay(100);
        k++;
        Serial.println(k);
    }
    k=2;
   

}*/

//2.超声波测试程序
//@author hyw
//@data   2018/08/28
const int TrigPin = 3;//发射超声波
const int EchoPin = 2;//收到反射回来的超声波
const int SparkPin = 4;
const int LightPin = 13;
float cm;
void setup()
{
    Serial.begin(9600);
    pinMode(EchoPin,INPUT);
    pinMode(TrigPin,OUTPUT);
    pinMode(SparkPin,OUTPUT);
    pinMode(LightPin,OUTPUT);
}
void loop()
{
    digitalWrite(TrigPin,LOW);//低高低电平发一个短时间脉冲去TrigPin
    delayMicroseconds(2);     // delayMicroseconds在更小的时间内延时准确
    digitalWrite(TrigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin,LOW);

    cm = pulseIn(EchoPin,HIGH)/58.0;
    cm = (int(cm*100.0))/100,0;
    Serial.print("Distance");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    
    if(cm<25.0)
    {digitalWrite(SparkPin,LOW);
    digitalWrite(LightPin,HIGH);
    delay(100);
    digitalWrite(LightPin,LOW);
    delay(100);
    
    }
    else
    {digitalWrite(SparkPin,HIGH);
    digitalWrite(LightPin,LOW);
    }
    
}

//3.继电器测试程序
//@author hyw
//@data   2018/08/28
/*const int ContralPin = 3;
const int D0 = 4;
const int D1 = 5;
const int D2 = 6;
const int D3 = 7;
void setup(){

    pinMode(ContralPin,OUTPUT);
    pinMode(D0,OUTPUT);
    pinMode(D1,OUTPUT);
    pinMode(D2,OUTPUT);
    pinMode(D3,OUTPUT);
}
void loop(){
    if(digitalRead(D0) == HIGH)
    {
    digitalWrite(ContralPin,HIGH);
    }
    if(digitalRead(D1) == HIGH)
    {
    digitalWrite(ContralPin,LOW);
    }
}*/