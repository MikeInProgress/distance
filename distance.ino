#define trigPin 13
#define echoPin 11
#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 9, 8, 7, 6, 5);
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(12, OUTPUT); 
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0); 
  lcd.print("Distance : "); 
}
int Function_of_distance(){
  long czas;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  czas = pulseIn(echoPin, HIGH);
  delay(500);
  lcd.clear();
  
  int zm = czas/58;
  Serial.println(zm);
  lcd.print(zm);
  lcd.print(" cm.");
  return(zm);
}
void range(int a, int b) {
  int how_is_it_the_distance = Function_of_distance();
  if ((how_is_it_the_distance > a) && (how_is_it_the_distance < b)) {
      digitalWrite(12, HIGH); 
  } else {
      digitalWrite(12, LOW); 
  }
}
 
void loop() {
  range(5, 40);   
  delay(100);
 
  
}
