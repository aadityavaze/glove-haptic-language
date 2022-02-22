#define INDEX_FINGER    2
#define MIDDLE_FINGER   3
#define RING_FINGER     4
#define PINKY_FINGER    5
#define GAP_PALM   6

bool isCurrentTimeShowing = false
long long int deltaTime = 0;
long long int startTime;

void deltaTimeInMilliSeconds(int hours, int minutes){

  deltaTime  = hours*60*60*1000 + minutes*60*1000;
  
  }


void getCurrentTime(){
    currentHourToShow = ((deltaTime + millis()) / (1000 * 60 * 60)).toFixed(1);
    currentMinuteToShow = ((deltaTime + millis()) / (1000 * 60)).toFixed(1);
    currentMinuteToShow /= 5;
  }

void showGap(){
    vibrate(GAP_PALM);
  }

void vibrate(int VIB){

     analogWrite(VIB, 180);
     delay(100);
     analogWrite(VIB, 0);
  
  }


void showCurrentTime(int x){

  if(x==1){vibrate(INDEX_FINGER);}
  if(x==2){vibrate(INDEX_FINGER);vibrate(INDEX_FINGER);}
  if(x==3){vibrate(INDEX_FINGER);vibrate(INDEX_FINGER);vibrate(INDEX_FINGER);}
  if(x==4){vibrate(MIDDLE_FINGER);}
  if(x==5){vibrate(MIDDLE_FINGER);vibrate(MIDDLE_FINGER);}
  if(x==6){vibrate(MIDDLE_FINGER);vibrate(MIDDLE_FINGER);vibrate(MIDDLE_FINGER);}
  if(x==7){vibrate(RING_FINGER);}
  if(x==8){vibrate(RING_FINGER);vibrate(RING_FINGER);}
  if(x==9){vibrate(RING_FINGER);vibrate(RING_FINGER);vibrate(RING_FINGER);}
  if(x==10){vibrate(PINKY_FINGER);}
  if(x==11){vibrate(PINKY_FINGER);vibrate(PINKY_FINGER);}
  if(x==12){vibrate(PINKY_FINGER);vibrate(PINKY_FINGER);vibrate(PINKY_FINGER);}
 
  }



  
void setup() {

  startTime = 0;

  deltaTimeInMilliSeconds(7,30);
  // put your setup code here, to run once:
  pinMode(1, OUTPUT)
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop() {

  if(millis()-startTime >= 5000){

    getCurrentTime();
    showCurrentTime(currentHourToShow);
    showGap();
    showCurrentTime(currentMinuteToShow);

    startTime = millis();
    }
  
  

}
