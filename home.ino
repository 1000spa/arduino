#include <Servo.h>
Servo window;  // 창문에 설치괸 서브 모터

void setup(){
    window.attach(10);  // 서브모터 시작 
    Serial.begin(9600);
    pinMode(4,INPUT);
    pinMode(8,INPUT);
    pinMode(5,OUTPUT);
    pinMode(13,OUTPUT);
    pinMode(7,OUTPUT);  // 핀모터
    pinMode(6,OUTPUT); // 핀모터
}

int led5 = 0;              // 디지털 5번 핀에 led
int led13 = 0;             // 디지털 13번 핀에 led
int servo10 = 0;           // 10번에 연결된 서브 모터 상태
void loop(){
    int bt4 = digitalRead(4);
    int bt8 = digitalRead(8);
    Serial.print("bt4 : ");
    Serial.print(bt4);
    Serial.print(" bt8 : ");
    Serial.println(bt8);
    if(bt4 == 0){  // 내가 4번 버튼을 누를 떄
        if (led5 == 0) led5 = 1;     // 
        else if (led5 == 1) led5 = 0 ;  
        delay(200);
    }
    if(led5 == 1) digitalWrite(5,HIGH);
    else digitalWrite(5,LOW);
    
    // 8번 버튼 사용해서 13번에 연결된 led 위와 동일 하게 제어 하세요
    if(bt8 == 0){  // 내가 8번 버튼을 누를 떄
        if (led13 == 0) led13 = 1;     // 
        else if (led13 == 1) led13 = 0 ;  
        delay(200);
    }
    if(led13 == 1) digitalWrite(13,HIGH);
    else digitalWrite(13,LOW);

    int gas = analogRead(A0);
    Serial.print("gas : ");
    Serial.println(gas);
    if(gas > 100) {
        Serial.println("경보");
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        delay(2000);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        delay(1000);
    }
    
    // 서브 모터 동작 확인 
    if(led5 == 1) window.write(180);
    if(led5 == 0) window.write(30);
    delay(300);
}