int c3=130, cs3=138, d3=146, ds3=155, e3=164, f3=174, fs3=184, g3=195, gs3=207, a3=220, as3=233, b3=246;
int c4=261, cs4=277, d4=293, ds4=311, e4=329, f4=349, fs4=369, g4=391, gs4=415, a4=440, as4=466, b4=493;
int c5=523, cs5=554, d5=587, ds5=622, e5=659, f5=698, fs5=739, g5=783, gs5=830, a5=880, as5=932, b5=987;
//  도      도#      레       레#      미       파      파#      솔      솔#      라       라#      시  

void f(int t, int d)
{
  tone(11, t, d);
  delay(d);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);

  //난 숨쉬고 싶어
  f(d4, 150);
  f(f4, 150);
  f(g4, 150);
  f(a4, 150);
  f(g4, 300);
  f(d4, 600);

  //이 밤이 싫어
  f(d4, 150);
  f(f4, 150);
  f(g4, 150);
  f(a4, 150);
  f(g4, 600);

  //이젠 깨고 싶어
  f(d4, 150);
  f(f4, 150);
  f(g4, 150);
  f(a4, 150);
  f(g4, 300);
  f(d4, 600);

  //꿈 속이 싫어
  f(d4, 150);
  f(f4, 150);
  f(g4, 150);
  f(a4, 150);
  f(g4, 600);

  //내 안에 갇혀서
  f(d4, 150);
  f(f4, 150);
  f(g4, 150);
  f(a4, 150);
  f(g4, 300);
  f(d4, 600);

  //난 죽어 있어
  f(d4, 150);
  f(f4, 150);
  f(g4, 150);
  f(a4, 150);
  f(g4, 600);

  //Don't wanna be lonely
  f(d4, 150);
  f(f4, 150);
  f(g4, 150);
  f(a4, 150);
  f(g4, 300);
  f(d4, 600);

  //Just wanna be yours
  f(d4, 150);
  f(f4, 150);
  f(g4, 150);
  f(a4, 150);
  f(g4, 300);
  f(f4, 150);
  f(d4, 300);
  delay(300);

  //왜 이리 깜깜한건지
  f(a4, 300);
  f(g4, 300);
  f(f4, 150);
  f(g4, 150);
  f(g4, 150);
  f(g4, 300);
  f(g4, 150);
  f(a4, 450);

  //니가 없는 이곳은
  f(d4, 300);
  f(g4, 150);
  f(g4, 150);
  f(g4, 150);
  f(g4, 300);
  f(a4, 300);
  f(f4, 450);

  //위험하잖아
  f(g4, 300);
  f(g4, 150);
  f(g4, 150);
  f(g4, 150);
  f(a4, 450);

  //망가진 내 모습-
  f(g4, 300);
  f(g4, 150);
  f(g4, 300);
  f(g4, 150);
  f(a4, 300);
  f(d4, 300);

  //구해줘 날
  f(g4, 300);
  f(g4, 300);
  f(g4, 300);
  f(a4, 450);

  //나도 날 잡을 수 없어
  f(d4, 300);
  f(g4, 150);
  f(g4, 150);
  f(g4, 150);
  f(g4, 300);
  f(a4, 150);
  f(g4, 150);
  f(g4, 450);
  delay(150);
   
  //수없어
  f(g4, 150);
  f(f4, 300);
  f(f4, 300);
  delay(300);

  //그 손을 내밀어줘
  f(a4, 150);
  f(a4, 150);
  f(a4, 150);
  f(a4, 150);
  f(g4, 150);
  f(f4, 150);
  f(g4, 150);

  //Save me Save me
  f(g4, 150);
  f(d4, 300);
  delay(300);
  f(g4, 150);
  f(d4, 300);
  delay(300);
  
  //I need your love before I fall, fall
  f(a4, 150);
  f(a4, 150);
  f(a4, 150);
  f(a4, 150);
  f(g4, 150);
  f(f4, 150);
  f(g4, 150);
  f(g4, 300);
  delay(300);
  f(f4, 300);
  delay(300);

  //그 손을 내밀어줘
  f(a4, 150);
  f(a4, 150);
  f(a4, 150);
  f(a4, 150);
  f(g4, 150);
  f(f4, 150);
  f(g4, 150);

  //Save me Save me
  f(g4, 150);
  f(d4, 300);
  delay(300);
  f(g4, 150);
  f(d4, 300);
  delay(300);
  
  //I need your love before I fall, fall
  f(a4, 150);
  f(a4, 150);
  f(a4, 150);
  f(a4, 150);
  f(g4, 150);
  f(f4, 150);
  f(g4, 150);
  f(g4, 450);
  delay(450);
  f(f4, 450);
  delay(450);
}

void loop() {
  // put your main code here, to run repeatedly:
  
} 
