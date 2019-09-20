int c3=130, cs3=138, d3=146, ds3=155, e3=164, f3=174, fs3=184, g3=195, gs3=207, a3=220, as3=233, b3=246;
int c4=261, cs4=277, d4=293, ds4=311, e4=329, f4=349, fs4=369, g4=391, gs4=415, a4=440, as4=466, b4=493;
int c5=523, cs5=554, d5=587, ds5=622, e5=659, f5=698, fs5=739, g5=783, gs5=830, a5=880, as5=932, b5=987;
//  도      도#      레       레#      미       파      파#      솔      솔#      라       라#      시        

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int cnt=1;

  
  //난 숨쉬고 싶어
  tone(11, d4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, a4, 300); delay(300);
  tone(11, g4, 500); delay(500);
  tone(11, d4, 300); delay(300);
  Serial.println(cnt++); delay(150); 
  //이 밤이 싫어
  tone(11, d4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, a4, 300); delay(300);
  tone(11, g4, 500); delay(500);
  Serial.println(cnt++); delay(200); 

  //이젠 꺠고 싶어
  tone(11, d4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, a4, 300); delay(300);
  tone(11, g4, 500); delay(500);
  tone(11, d4, 300); delay(300);
  Serial.println(cnt++); delay(150);
  //꿈속이 싫어
  tone(11, d4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, a4, 300); delay(300);
  tone(11, g4, 500); delay(500);
  Serial.println(cnt++); delay(200);

  //내 않에 갇혀서
  tone(11, d4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, a4, 300); delay(300);
  tone(11, g4, 500); delay(500);
  tone(11, d4, 300); delay(300);
  Serial.println(cnt++); delay(150);
  //난 죽어있어
  tone(11, d4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, a4, 300); delay(300);
  tone(11, g4, 500); delay(500);
  Serial.println(cnt++); delay(200);

  //Don’t wanna be lonely
  tone(11, d4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, a4, 300); delay(300);
  tone(11, g4, 500); delay(500);
  tone(11, d4, 300); delay(300);
  Serial.println(cnt++); delay(150);
  //Just wanna be yours 
  tone(11, d4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, a4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, d4, 500); delay(500);
  Serial.println(cnt++); delay(200);


  //왜 이리 깜깜한건지
  tone(11, a4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, f4, 300); delay(300);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, a4, 300); delay(200);
  Serial.println(cnt++); delay(200);
  
  //니가 없는 이곳은
  tone(11, d4, 300); delay(300);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, a4, 200); delay(200);
  tone(11, f4, 200); delay(200);
  Serial.println(cnt++); delay(150);

  //위험하잖아
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, a4, 200); delay(200);
  Serial.println(cnt++); delay(200);
  
  //망가진 내모습
  tone(11, g4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, g4, 300); delay(300);
  tone(11, g4, 200); delay(200);
  tone(11, a4, 200); delay(200);
  tone(11, d4, 200); delay(200);
  tone(11, c4, 200); delay(200);
  Serial.println(cnt++); delay(150);

  //구해줘 날
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, a4, 300); delay(300);
  Serial.println(cnt++); delay(200);

  //나도 날 잡을수 없어
  tone(11, d4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, a4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  tone(11, g4, 200); delay(200);
  delay(700);
  tone(11, g4, 200); delay(200);
  tone(11, f4, 200); delay(200);
  tone(11, f4, 200); delay(200);
  Serial.println(cnt++); delay(150);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  //
  Serial.println(cnt++); delay(0);

  
}


/*
난 숨 쉬 고 싶 어 이 밤 이 싫 어        

d4 f4 g4 a4 g4 d4  d4 f4 g4 a4 g4 



이 젠 깨 고 싶 어  꿈  속 이 싫 어

d4 f4 g4 a4 g4 d4  d4 f4 g4 a4 g4



내 안 에 갇 혀 서 난 죽 어 있 어

d4 f4 g4 a4 g4 d4 d4 f4 g4 a4 g4


Don’t wanna be lonely

d4    f4 g4  a4 g4 d4 


Just wanna be yours 

d4    f4 g4  a4 g4f4d4



왜 이  리 깜 깜 한 건 지

a4 g4 f4 g4 g4 g4 g4 a4



니 가 없 는 이 곳 은

d4 g4 g4 g4 g4 a4 f4




위 험 하 잖 아

g4 g4 g4 g4 a4




망 가 진 내 모 습-

g4 g4 g4 g4 a4 d4c4



구 해 줘 날

g4 g4 g4 a4

-----------------------------------

나 도 날 잡 을 수 없 어 

d4 g4 g4 g4 g4 a4 g4 g4 (g4 f4 f4)

​


내 심 장 소 릴 들 어 봐

d4 f4 a4 d5 c5 d5 f3 a4



제  멋 대 로 널 부 르 잖 아

as4 a4 g4 f4 g4 f4 g4 a4 d4

​


이 까 만 어 둠 속 에   서

d4 f4 a4 d5 c5 d5 f3 d5 


너  는 이 렇 게 빛 나 니 까 

as4 a4 g4 f4 g4 f4 g4 a4 d4



그 손 을 내 밀 어 줘  

a4 a4 a4 a4 g4 f4 g4



save me save me

g4    d4   g4  d4 



I  need your love before  I  fall, fall

a4  a4   a4   a4  g4 f4  g4  g4 f4



그 손 을 내 밀 어 줘  

a4 a4 a4 a4 g4 f4 g4


save me save me

g4    d4   g4  d4 



I  need your love before  I  fall, fall

a4  a4   a4   a4  g4 f4  g4  g4 f4



그 손 을 내 밀 어 줘  

a4 a4 a4 a4 g4 f4 g4



save me save me  save me  

g4    d4   g4  d4   a4    c5 c5 c5 



그 손 을 내 밀 어 줘  

a4 a4 a4 a4 g4 f4 g4



save me save me  save me  

g4    d4   g4  d4   a4    c5 c5 c5 
*/
