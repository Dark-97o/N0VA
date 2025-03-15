#include<Servo.h>

Servo head;
Servo l_hand;
Servo r_hand;


// received data
byte val = "";

void setup() {
  r_hand.attach(2);
  l_hand.attach(3);
  head.attach(4);

  Serial.begin(9600); // for communicating via serial port with Python
}

void standby(){
  head.write(90);
  int r_pos = 30;
  int l_pos = map(r_pos, 0, 180, 180, 0);
  
  l_hand.write(l_pos);
  r_hand.write(r_pos);
}

void hi(){
  head.write(90);

  int i = 0;
  for(i=30; i<= 170; i++){
    r_hand.write(i);
    delay(5);
  }

  for(i=170; i>= 100; i--){
    r_hand.write(i);
    delay(5);
  }

  for(i=100; i<= 170; i++){
    r_hand.write(i);
    delay(5);
  }

  for(i=170; i>= 30; i--){
    r_hand.write(i);
    delay(5);
  }

  standby();
}

void hands_up(){
  // do this on every command (nothing much just move hands a bit)

  //head.write(150);
  //delay(300);
  //head.write(90);
  
  int i = 0;
  for(i=30; i<= 170; i++){
    int r_pos = i;
    int l_pos = map(r_pos, 0, 180, 180, 0);
  
    l_hand.write(l_pos);
    r_hand.write(r_pos);
    delay(5);
  }

  delay(600);

  for(i=170; i>= 30; i--){
    int r_pos = i;
    int l_pos = map(r_pos, 0, 180, 180, 0);
  
    l_hand.write(l_pos);
    r_hand.write(r_pos);
    delay(5);
  }
  
}

void warn(){
  // lift weight using both hands
  int i = 0;
  for(i=30; i<= 170; i++){
    int r_pos = i;
    int l_pos = map(r_pos, 0, 180, 180, 0);
  
    l_hand.write(l_pos);
    r_hand.write(r_pos);
    delay(5);
  }

  for(int count=0; count<=4; count++){
    for(i=170; i>= 60; i--){
      int r_pos = i;
      int l_pos = map(r_pos, 0, 180, 180, 0);
  
      l_hand.write(l_pos);
      r_hand.write(r_pos);
      delay(5);
      }

    for(i=60; i<= 170; i++){
      int r_pos = i;
      int l_pos = map(r_pos, 0, 180, 180, 0);
  
      l_hand.write(l_pos);
      r_hand.write(r_pos);
      delay(5);
      }
    }

  for(i=170; i>= 30; i--){
    int r_pos = i;
    int l_pos = map(r_pos, 0, 180, 180, 0);
  
    l_hand.write(l_pos);
    r_hand.write(r_pos);
    delay(5);
  }
}

void excited(){
  return;
}

void look_left(){
  // rotate hed to left
  head.write(180);
}

void look(){
  // rotate hed to left
  head.write(180);
  delay(1000);
  head.write(0);
  delay(800);
  head.write(90);
  delay(500);
  standby();
}

void confused(){

  for(int count=0; count<=1; count++){
    head.write(30);
    r_hand.write(170);
    delay(700);
    r_hand.write(30);
    head.write(120);
    l_hand.write(30);
    delay(700);
    l_hand.write(160);
    }
  standby();
}

void double_punch(){
  // do a punch
  int i = 0;
  for(i=30; i>= 0; i--){
      int r_pos = i;
      int l_pos = map(r_pos, 0, 180, 180, 0);
  
      l_hand.write(l_pos);
      r_hand.write(r_pos);
      delay(5);
      }
  delay(2000);
  
  int r_pos = 80;
  int l_pos = map(r_pos, 0, 180, 180, 0);
  l_hand.write(l_pos);
  r_hand.write(r_pos);
  delay(500);
  standby();
}

void r_upper_cut(){
  // make right upper-cut
  int i = 0;
  for(i=30; i<= 170; i++){
    int r_pos = i;
    int l_pos = map(r_pos, 0, 180, 180, 0);
  
    l_hand.write(l_pos);
    r_hand.write(r_pos);
    delay(5);
  }

  for(int count=0; count<=4; count++){
    int i = 0;
    for(i=170; i>= 60; i--){
      r_hand.write(i);
      delay(1);
      }

    for(i=60; i<= 170; i++){
      r_hand.write(i);
      delay(1);
      }
    }
   standby();
   delay(100);
}

void smash(){
  // smash things
  int i = 0;
  for(i=30; i<= 170; i++){
    int r_pos = i;
    int l_pos = map(r_pos, 0, 180, 180, 0);
  
    l_hand.write(l_pos);
    r_hand.write(r_pos);
    delay(5);
  }
  delay(2000);
  for(i=170; i>= 0; i--){
    int r_pos = i;
    int l_pos = map(r_pos, 0, 180, 180, 0);
  
    l_hand.write(l_pos);
    r_hand.write(r_pos);
    delay(1);
  }
  delay(300);
  int r_pos = 180;
  int l_pos = map(r_pos, 0, 180, 180, 0);
  
  l_hand.write(l_pos);
  r_hand.write(r_pos);
  delay(1000);
  standby();
}

void eye_detect(){
  // do something if eye sensor detect motion
  return;
}

void dance(){
  // Dance loop
  // Move head left and right
  for (int pos = 60; pos <= 120; pos += 1) {
    head.write(pos);
    delay(15);  // Adjust speed of movement
  }
  for (int pos = 120; pos >= 60; pos -= 1) {
    head.write(pos);
    delay(15);
  }

  // Move left hand up and down
  for (int pos = 0; pos <= 90; pos += 1) {
    l_hand.write(pos);
    delay(20);
  }
  for (int pos = 90; pos >= 0; pos -= 1) {
    l_hand.write(pos);
    delay(20);
  }

  // Move right hand up and down
  for (int pos = 180; pos >= 90; pos -= 1) {
    r_hand.write(pos);
    delay(20);
  }
  for (int pos = 90; pos <= 180; pos += 1) {
    r_hand.write(pos);
    delay(20);
  }

  // You can add more patterns or combine the movements
  standby();
}

void loop() {
  // put your main code here, to run repeatedly:
  standby();

  while(Serial.available() > 0)  //look for serial data available or not
  {
    val = Serial.read();        //read the serial value

    if(val == 'h'){
      // do hi
       hi();
    }
    if(val == 'p'){
      // do hi
       double_punch();
    }
    if(val == 'u'){
      hands_up();
      delay(3000);
    }
    if(val == 'l'){
      standby();
      look_left();
      delay(2000);
    }
    if(val == 'U'){
      // uppercut
      r_upper_cut();
      delay(2000);
    }
    if(val == 's'){
      smash();
      delay(2000);
    }
    if(val == 'c'){
      confused();
      delay(2000);
    }
    if(val == 'i'){
      look();
      delay(2000);
    }
    if(val == 'w'){
      warn();
      delay(2000);
    }
    if(val == 'd'){
      dance();
      delay(2000);
    }
  }
}