/* Protodrama 2020 */

/* button mode selector pins */
#define buttonMode 9

/* RGB pins */
#define BLUE 3
#define GREEN 5
#define RED 6

/* mode seleccion */
int mode = 0;
int maxmode = 14;
/*
 * mode 0 = party rgb;
 * mode 1 = fixed green;
 * mode 2 = glow green;
 * mode 3 = fixed blue;
 * mode 4 = glow blue;
 * mode 5 = fixed cyan;
 * mode 6 = glow cyan;
 * mode 7 = fixed purple;
 * mode 8 = glow purple;
 * mode 9 = fixed red;
 * mode 10 = glow red;
 * mode 11 = fixed yellow;
 * mode 12 = glow yellow;
 * mode 13 = rainbow;
 */

/* data for party color mode */
const unsigned long eventTime_Party_ColorChange = 500;
unsigned long previousTime_Party_ColorChange = 0;

/* data for glow mode */
unsigned int glow_brightness = 100;
bool increasing = false;
const unsigned long eventTime_Glow_Brightness_Change = 50;
unsigned long previousTime_Glow_Brightness_ColorChange = 0;

/* data for rainbow mode */
unsigned int colortransition = 0; /* To select transtition between green, cyan, blue, purple, red, yellow */
unsigned int green_rainbow_value = 100; /* 100 to be used as first color when mode is selected */
unsigned int blue_rainbow_value = 0;
unsigned int red_rainbow_value = 0;
const unsigned long eventTime_Rainbow_Change = 50;
unsigned long previousTime_Rainbow_ColorChange = 0;

/***************************/

void setup() {

 /* Initialice serial transmission */
 Serial.begin(9600);

 /* button mode selector initialization */
 pinMode(buttonMode, INPUT_PULLUP);

 /* LED pins initialization */
 pinMode(BLUE,OUTPUT);
 pinMode(RED,OUTPUT);
 pinMode(GREEN,OUTPUT);

}

void loop() {
  
  /* output for debuff purposes */
  Serial.println(mode);
  Serial.println(glow_brightness);

  int btnModeStatus = digitalRead(buttonMode);

  if (btnModeStatus == LOW)
  {
    Serial.println("mode changed");
    
    mode++;
    if(mode == maxmode){
      mode = 0;
    }
    delay(1000);
  }


  /* RGB party mode */
  if(mode == 0){
    /* Updates frequently with current time to calculate time difference*/
    unsigned long currentTime = millis();

    long redvalue = random(0,100);
    long greenvalue = random(0,100);
    long bluevalue = random(0,100);

    if(currentTime - previousTime_Party_ColorChange >= eventTime_Party_ColorChange){
      analogWrite(GREEN, greenvalue);
      analogWrite(RED, redvalue);
      analogWrite(BLUE, bluevalue);

      previousTime_Party_ColorChange = currentTime;
    }
  }

  /* Fixed green mode */
  if(mode == 1){
      analogWrite(GREEN, 100);
      analogWrite(RED, 0);
      analogWrite(BLUE, 0);
  }

  /* Glow green mode */
  if(mode == 2){
    
    /* Updates frequently with current time to calculate time difference*/
    unsigned long currentTime = millis();
    
    if(currentTime - previousTime_Glow_Brightness_ColorChange >= eventTime_Glow_Brightness_Change){
      analogWrite(GREEN, glow_brightness);
      analogWrite(RED, 0);
      analogWrite(BLUE, 0);

      previousTime_Glow_Brightness_ColorChange = currentTime;
      
      change_glow_brighness();
      change_glow_direction();
    }
  }

/* Fixed blue mode */
  if(mode == 3){
      analogWrite(GREEN, 0);
      analogWrite(RED, 0);
      analogWrite(BLUE, 100);
  }

/* Glow blue mode */
  if(mode == 4){
    
    /* Updates frequently with current time to calculate time difference*/
    unsigned long currentTime = millis();
    
    if(currentTime - previousTime_Glow_Brightness_ColorChange >= eventTime_Glow_Brightness_Change){
      analogWrite(GREEN, 0);
      analogWrite(RED, 0);
      analogWrite(BLUE, glow_brightness);

      previousTime_Glow_Brightness_ColorChange = currentTime;
      
      change_glow_brighness();
      change_glow_direction();
    }
  }

/* Fixed cyan mode */
  if(mode == 5){
      analogWrite(GREEN, 100);
      analogWrite(RED, 0);
      analogWrite(BLUE, 100);
  }

/* Glow cyan mode */
  if(mode == 6){
    
    /* Updates frequently with current time to calculate time difference*/
    unsigned long currentTime = millis();
    
    if(currentTime - previousTime_Glow_Brightness_ColorChange >= eventTime_Glow_Brightness_Change){
      analogWrite(GREEN, glow_brightness);
      analogWrite(RED, 0);
      analogWrite(BLUE, glow_brightness);

      previousTime_Glow_Brightness_ColorChange = currentTime;
      
      change_glow_brighness();
      change_glow_direction();
    }
  }

/* Fixed purple mode */
  if(mode == 7){
      analogWrite(GREEN, 0);
      analogWrite(RED, 100);
      analogWrite(BLUE, 100);
  }

/* Glow purple mode */
  if(mode == 8){
    
    /* Updates frequently with current time to calculate time difference*/
    unsigned long currentTime = millis();
    
    if(currentTime - previousTime_Glow_Brightness_ColorChange >= eventTime_Glow_Brightness_Change){
      analogWrite(GREEN, 0);
      analogWrite(RED, glow_brightness);
      analogWrite(BLUE, glow_brightness);

      previousTime_Glow_Brightness_ColorChange = currentTime;
      
      change_glow_brighness();
      change_glow_direction();
    }
  }

/* Fixed red mode */
  if(mode == 9){
      analogWrite(GREEN, 0);
      analogWrite(RED, 100);
      analogWrite(BLUE, 0);
  }

/* Glow red mode */
  if(mode == 10){
    
    /* Updates frequently with current time to calculate time difference*/
    unsigned long currentTime = millis();
    
    if(currentTime - previousTime_Glow_Brightness_ColorChange >= eventTime_Glow_Brightness_Change){
      analogWrite(GREEN, 0);
      analogWrite(RED, glow_brightness);
      analogWrite(BLUE, 0);

      previousTime_Glow_Brightness_ColorChange = currentTime;
      
      change_glow_brighness();
      change_glow_direction();
    }
  }

/* Fixed yellow mode */
  if(mode == 11){
      analogWrite(GREEN, 100);
      analogWrite(RED, 100);
      analogWrite(BLUE, 0);
  }

/* Glow yellow mode */
  if(mode == 12){
    
    /* Updates frequently with current time to calculate time difference*/
    unsigned long currentTime = millis();
    
    if(currentTime - previousTime_Glow_Brightness_ColorChange >= eventTime_Glow_Brightness_Change){
      analogWrite(GREEN, glow_brightness);
      analogWrite(RED, glow_brightness);
      analogWrite(BLUE, 0);

      previousTime_Glow_Brightness_ColorChange = currentTime;
      
      change_glow_brighness();
      change_glow_direction();
    }
  }


/* Rainbow mode */
  if(mode == 13){
    
    /* Updates frequently with current time to calculate time difference*/
    unsigned long currentTime = millis();

    Serial.println(green_rainbow_value + red_rainbow_value + blue_rainbow_value);
    
    if(currentTime - previousTime_Rainbow_ColorChange >= eventTime_Rainbow_Change){
      analogWrite(GREEN, green_rainbow_value);
      analogWrite(RED, red_rainbow_value);
      analogWrite(BLUE, blue_rainbow_value);

      previousTime_Rainbow_ColorChange = currentTime;

      switch(colortransition){
        /* Green to Cyan */
        case 0:
          if(green_rainbow_value >= 100 && blue_rainbow_value >= 100){
            colortransition++;
          }else{
            blue_rainbow_value++;
          }
        break;
        /* Cyan to Blue */
        case 1:          
          if(green_rainbow_value <= 0 && blue_rainbow_value >= 100){
            colortransition++;
          }
          else{
            green_rainbow_value--;
          }
        break;
        /* Blue to Purple */
        case 2:
          if(red_rainbow_value >= 100 && blue_rainbow_value >= 100){
            colortransition++;
          }
          else{
            red_rainbow_value++;
          }
        break;
        /* Purple to Red */
        case 3:
          if(blue_rainbow_value <= 0 && red_rainbow_value >= 100){
            colortransition++;
          }
          else{
            blue_rainbow_value--;
          }
        break;
        /* Red to Yellow */
        case 4:
          if(green_rainbow_value >= 100 && red_rainbow_value >= 100){
            colortransition++;
          }
          else{
            green_rainbow_value++;
          }
        break;
        /* Yellow to Green */
        case 5:
          if(red_rainbow_value <= 0 && green_rainbow_value >= 100){
            colortransition = 0;
          }
          else{
            red_rainbow_value--;
          }
        break;
        
      }      
    }
  }

}

int Brighnesspercentage(int scope){
  return glow_brightness / 100 * scope;
}

void change_glow_brighness(){
  if(increasing){
    glow_brightness++;
  }
  else{
    glow_brightness--;
  }
}
  
void change_glow_direction(){
  if(glow_brightness <= 0) {
      increasing = true;
  }
  else if(glow_brightness >= 100){
    increasing = false;
  }
}
