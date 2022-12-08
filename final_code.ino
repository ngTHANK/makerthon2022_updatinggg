#include <NewPing.h>
#include <LiquidCrystal.h>
#define min 50 // khoang cach toi thieu de xe khong trong diem mu
LiquidCrystal lcd(11,10, 7, 6, 5, 4);
//               (RS, E,D4,D5,D6,D7) 

// ham khai bao chan cho cam bien
NewPing sonar1(A0,A1,600);
NewPing sonar2(A2,A3,600);
NewPing sonar3(A4,A5,600);
NewPing sonar4(2,3,600);

// cac ham hien thi canh bao
void front_warn() {
    lcd.setCursor(5,0);
    lcd.print("FRONT");
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
}

void left_warn() {
    lcd.home();
    lcd.print("LEFT");
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
}

void right_warn() {
    lcd.setCursor(11,0);
    lcd.print("RIGHT");
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
}

void behind_warn() {
    lcd.setCursor(4,1);
    lcd.print("BEHIND");
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
}
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("UPDATING...");
  delay(500);
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int d1 = sonar1.ping_cm(); // khoang cach tu cam bien TRUOC toi vat the
  int d2 = sonar2.ping_cm(); // khoang cach tu cam bien TRAI toi vat the
  int d3 = sonar3.ping_cm(); // khoang cach tu cam bien PHAI toi vat the
  int d4 = sonar4.ping_cm(); // khoang cach tu cam bien SAU toi vat the
  
//  Serial.print("S1 = ");
//  Serial.println(sonar1.ping_cm());
//  Serial.print("S2= ");
//  Serial.println(sonar2.ping_cm());
//  Serial.print("S3= ");
//  Serial.println(sonar3.ping_cm());
//  Serial.print("S4= ");
//  Serial.println(sonar4.ping_cm());
//  delay(200);

  // khong co vat the trong vung diem mu
  if (d1 > min & d2 > min & d3 > min & d4 > min || d1 == 0 & d2 == 0 & d3 == 0 & d4 == 0) {
    digitalWrite(12,LOW);
    digitalWrite(13,LOW); 
    lcd.clear();
  }

  // 1 vat the trong 1 phia cua diem mu
  if (d1 < min & d1 > 0 & d2 > min & d3 > min & d4 > min || d1 < min & d1 > 0 & d2 == 0 & d3 == 0 & d4 == 0 ) {
    lcd.clear();
    front_warn();
    lcd.setCursor(5,1);
    lcd.print("sF = ");
    lcd.print(d1);
  }
  if (d2 < min & d2 > 0 & d1 > min & d3 > min & d4 > min || d2 < min & d2 > 0 & d1 == 0 & d3 == 0 & d4 == 0 ) {
    lcd.clear();
    left_warn();
    lcd.setCursor(1,1);
    lcd.print("sL = ");
    lcd.print(d2);
  }
  if (d3 < min & d3 > 0 & d2 > min & d1 > min & d4 > min || d3 < min & d3 > 0 & d2 == 0 & d1 == 0 & d4 == 0 ) {
    lcd.clear();
    right_warn();
    lcd.setCursor(6,1);
    lcd.print("sR = ");
    lcd.print(d3);
  }
  if (d4 < 10 & d4 > 0 & d2 > min & d3 > min & d1 > min || d4 < min & d4 > 0 & d2 == 0 & d3 == 0 & d1 == 0 ) {
    lcd.clear();
    behind_warn();
    lcd.setCursor(5,0);
    lcd.print("sB = ");
    lcd.print(d4);
  }

  // two side (2 vat the o hai phia khac nhau cua diem mu
  if (d1 < min & d1 > 0 & d2 < min & d2 > 0 & d3 > min & d4 > min || d1 < min & d1 > 0 & d2 < min & d2 > 0 & d3 == 0 & d4 == 0 ) {
    lcd.clear();
    front_warn();
    left_warn();
    lcd.setCursor(6,1);
    lcd.print("sF=");
    lcd.print(d1);

    lcd.setCursor(0,1);
    lcd.print("sL=");
    lcd.print(d2);
    
  }

  if (d1 < min & d1 > 0 & d3 < min & d3 > 0 & d2 > min & d4 > min || d1 < min & d1 > 0 & d3 < min & d3 > 0 & d2 == 0 & d4 == 0 ) {
    lcd.clear();
    front_warn();
    right_warn();

    lcd.setCursor(4,1);
    lcd.print("sF=");
    lcd.print(d1);

    lcd.setCursor(11,1);
    lcd.print("sR=");
    lcd.print(d3);
  }

  if (d1 < min & d1 > 0 & d4 < min & d4 > 0 & d2 > min & d3 > min || d1 < min & d1 > 0 & d4 < min & d4 > 0 & d2 == 0 & d3 == 0 ) {
    lcd.clear();
    front_warn();
    behind_warn();

    lcd.setCursor(0,0);
    lcd.print("sF=");
    lcd.print(d1);

    lcd.setCursor(11,1);
    lcd.print("sB=");
    lcd.print(d4);
  }

  if (d3 < min & d3 > 0 & d2 < min & d2 > 0 & d1 > min & d4 > min || d3 < min & d3 > 0 & d2 < min & d2 > 0 & d1 == 0 & d4 == 0 ) {
    lcd.clear();
    right_warn();
    left_warn();

    lcd.setCursor(0,1);
    lcd.print("sL=");
    lcd.print(d2);

    lcd.setCursor(11,1);
    lcd.print("sR=");
    lcd.print(d3);
  }

  if (d4 < min & d4 > 0 & d2 < min & d2 > 0 & d3 > min & d1 > min || d4 < min & d4 > 0 & d2 < min & d2 > 0 & d3 == 0 & d1 == 0 ) {
    lcd.clear();
    behind_warn();
    left_warn();

    lcd.setCursor(11,0);
    lcd.print("sL=");
    lcd.print(d2);

    lcd.setCursor(11,1);
    lcd.print("sB=");
    lcd.print(d4);
  }

  if (d3 < min & d3 > 0 & d4 < min & d4 > 0 & d1 > min & d2 > min || d3 < min & d3 > 0 & d4 < min & d4 > 0 & d1 == 0 & d2 == 0 ) {
    lcd.clear();
    right_warn();
    behind_warn();
    
    lcd.setCursor(3,0);
    lcd.print("sR=");
    lcd.print(d3);

    lcd.setCursor(11,1);
    lcd.print("sL=");
    lcd.print(d4);
  }

  /// three side (3 vat the o 3 phia khac nhau cua diem mu

  if (d1 < min & d1 > 0 & d2 < min & d2 > 0 & d3 < min & d3 > 0 & d4 > min || d1 < min & d1 > 0 & d2 < min & d2 > 0 & d3 < min & d3 > 0 & d4 == 0 ) {
    lcd.clear();
    front_warn();
    left_warn();
    right_warn();
  }

  if (d1 < min & d1 > 0 & d2 < min & d2 > 0 & d4 < min & d4 > 0 & d3 > min || d1 < min & d1 > 0 & d2 < min & d2 > 0 & d4 < min & d4 > 0 & d3 == 0 ) {
    lcd.clear();
    front_warn();
    left_warn();
    behind_warn();
  }

  if (d1 < min & d1 > 0 & d3 < min & d3 > 0 & d4 < min & d4 > 0 & d2 > min || d1 < min & d1 > 0 & d3 < min & d3 > 0 & d4 < min & d4 > 0 & d2 == 0 ) {
    lcd.clear();
    front_warn();
    behind_warn();
    right_warn();
  }

  if (d4 < min & d4 > 0 & d2 < min & d2 > 0 & d3 < min & d3 > 0 & d1 > min || d4 < min & d4 > 0 & d2 < min & d2 > 0 & d3 < min & d3 > 0 & d1 == 0 ) {
    lcd.clear();
    behind_warn();
    left_warn();
    right_warn();
  }

  /// four side ( o ca 4 phia diem mu deu co vat the)

  if (d1 < min & d1 > 0 & d2 < min & d2 > 0 & d3 < min & d3 > 0 & d4 < min & d4 > 0) {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("All SIDE");
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
  }
  
}
