
//###프로토 타입
#define ledRPin 3
#define ledGPin 4
#define ledBPin 5
#define buttonPin1 8
#define buttonPin2 9
#define buttonPin3 10
#define buttonPin4 11
#define buttonPin5 12
#define buttonPin6 13
float RGB[3];

void setup() {
    pinMode(ledRPin, OUTPUT);
    pinMode(ledGPin, OUTPUT);
    pinMode(ledBPin, OUTPUT);
    pinMode(buttonPin1 , INPUT);
    pinMode(buttonPin2 , INPUT);
    pinMode(buttonPin3 , INPUT);
    pinMode(buttonPin4 , INPUT);
    pinMode(buttonPin5 , INPUT);
    pinMode(buttonPin6 , INPUT);
    
}

int buttonCnt = 0;
int state = 0;
int num=0;

//void SetColor(int red, int green, int blue) {
//  analogWrite(ledRPin, red);
//  analogWrite(ledGPin, green);
//  analogWrite(ledBPin, blue); 
//}

void loop() {

   if (digitalRead(buttonPin1 ) == HIGH) {
            state = 1;
   }
   else if (digitalRead(buttonPin2 ) == HIGH) {
            state = 2;
   }
   else if (digitalRead(buttonPin3 ) == HIGH) {
            state = 3;
   }
   else if (digitalRead(buttonPin4 ) == HIGH) {
            state = 4;
   }
   else if (digitalRead(buttonPin5 ) == HIGH) {
            state = 5;
   }
   else if (digitalRead(buttonPin6 ) == HIGH) {
            state = 6;
   }         
   else{
    state = 0;
   }
   
    switch(state){
        case 0:                               //LED OFF
            digitalWrite(ledRPin, LOW);
            digitalWrite(ledGPin, LOW);
            digitalWrite(ledBPin, LOW);
            break;

        case 1:
            digitalWrite(ledRPin, HIGH); // LED Red
            digitalWrite(ledGPin, LOW);
            digitalWrite(ledBPin, LOW);
            break;
        case 2:
            digitalWrite(ledRPin, LOW); // LED Green
            digitalWrite(ledGPin, HIGH);
            digitalWrite(ledBPin, LOW);
            break;
        case 3:
            digitalWrite(ledRPin, LOW); // LED Blue
            digitalWrite(ledGPin, LOW);
            digitalWrite(ledBPin, HIGH);
            break;
            
        case 4:
            for (float x=1.3;x<PI;x=x+0.000003){
              if(digitalRead(buttonPin5) == HIGH) {
                break;
              }
            
              RGB[0]=255*abs(sin(x*(180/PI)));           
              RGB[1]=255*abs(sin((x+PI/3)*(180/PI)));    
              RGB[2]=255*abs(sin((x+(2*PI)/3)*(180/PI)));
 
              analogWrite(ledRPin,RGB[0]);
              analogWrite(ledGPin,RGB[1]);
              analogWrite(ledBPin,RGB[2]);
            }
        case 5:
            for (int x=0;x<100;x=x+1){
              RGB[0]=255*abs(sin(x*(180/PI)));          
              RGB[1]=255*abs(sin((x+PI/3)*(180/PI)));    
              RGB[2]=255*abs(sin((x+(2*PI)/3)*(180/PI)));
 
              analogWrite(ledRPin,RGB[0]);
              analogWrite(ledGPin,RGB[1]);
              analogWrite(ledBPin,RGB[2]);
            }
            break;

       case 6:
          analogWrite(ledRPin ,255);  //Orange
          analogWrite(ledGPin,0);
          analogWrite(ledBPin ,10 + random(15) );
          
          delay(100);
    }

}
