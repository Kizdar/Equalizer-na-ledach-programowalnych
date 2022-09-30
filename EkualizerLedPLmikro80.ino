#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 66 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


#define mic 8
const int Sample_Time = 90;
unsigned long millisCurrent;
unsigned long millisCurrent2;
unsigned long millisLast =0;
unsigned long millisLast2 =0;
unsigned long millisLast3 =0;
unsigned long millisLast4 =0;
unsigned long millisLast5 =0;
unsigned long millisElapsed =0;

int sampleBufferValue = 0;
int i=0;
int Mikro[6];
int mapowanie=0;
int a=0;

  int pieslup[] = {0,1,2,3,4,5,6,7,8,9,10};
  int druslup[] = {21,20,19,18,17,16,15,14,13,12,11};
  int trzslup[] = {22,23,24,25,26,27,28,29,30,31,32};
  int czwslup[] = {43,42,41,40,39,38,37,36,35,34,33};
  int pioslup[] = {44,45,46,47,48,49,50,51,52,53,54};
  int szuslup[] = {65,64,63,62,61,60,59,58,57,56,55};

    int punktZerowy[] = {0,0,0};

int g=125;
  int r=125;
  int b=125;

  int gg=255;
  int rr=255;
  int bb=255;

void setup() {
  // put your setup code here, to run once:
pinMode(mic,INPUT);
Serial.begin(9600);
 pixels.begin();
}

void loop() {

  // put your main code here, to run repeatedly:
 

millisCurrent = millis();
 millisElapsed = millisCurrent - millisLast;
 if(digitalRead(mic) == LOW){
  sampleBufferValue++;
  }
  if(millisElapsed > Sample_Time){
//   Serial.println(sampleBufferValue);
    a=sampleBufferValue;
    sampleBufferValue = 0;
    millisLast = millisCurrent;
    }



//Serial.print(" ");
if(a>10){a=10;}
//if(a==1){a=0;}
//Serial.println(a);
ustawnienie(a, pieslup);
ustawnienie(a, druslup);
ustawnienie(a, trzslup);
ustawnienie(a, czwslup);
ustawnienie(a, pioslup);
ustawnienie(a, szuslup);

 
    

    
}

void ustawnienie(int num, int Tab[]){
  

    if(millisCurrent - millisLast3>=3000){  
   gg=random(0,255);
   rr=random(0,255);
   bb=random(0,255);
  millisLast3=millis();
  }
   
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
//  if(millisCurrent - millisLast5>=400){  
    if(g<gg){
      g=gg+b;
      }else{
         g=gg-r;
        }
    if(r<rr){
      r=rr+g;
      }else{
         r=rr-b;
        }
        if(b<bb){
      b=bb+r;
      }else{
         b=bb-g;
        }

        if (r<0) r=0;
         if (g<0) g=0;
          if (b<0) b=0;

        if (r>255) r=255;
        if (g>255) g=255;
        if (b>255) b=255; //na kazdym słupie inny kolor
          
//  millisLast5=millis();
//  }                       
//  Serial.print(rr);
//  Serial.print(" ");
//  Serial.print(gg);
//  Serial.print(" ");
//  Serial.println(bb);
//  Serial.print("      ");
//  Serial.print(r);
//  Serial.print(" ");
//  Serial.print(g);
//  Serial.print(" ");
//  Serial.println(b);
  for(int i=0; i<=num; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(Tab[i], pixels.Color(g,r,b));

    }
    for(int i=num+1; i<11; i++) {
         pixels.setPixelColor(Tab[i], pixels.Color(0,0,0));
        }


if(millisCurrent - millisLast4>=100){  
  // Send the updated pixel colors to the hardware.
     pixels.show(); 
  millisLast4=millis();
  }
       
  }
