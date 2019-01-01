
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long next_roll = 1000;

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.


}

void print_sanity(int sanity){
  
  int mythos = 100-sanity;
  
  display.clearDisplay();

  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner

  display.print(F("Sanity:"));
  display.print(String(sanity,DEC));
  display.print(F("\n"));
  display.print(F("Mythos:"));
  display.print(String(mythos,DEC));
  //display.println(String("Mythos:")+mythos);

  display.display();
  delay(100);
}

void fuck_with_ppl(void){
   
  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner

  next_roll += 10000;

  int die = random(1, 37);
  
  switch (die){
  case 1:
  display.println(F("Mary had a little lamb"));//1
    break;
  case 2:
  display.println(F("kill them all"));
    break;
  case 3:
display.println(F(  "how about a game?"));
    break;
    case 4:
display.println(F("Ia, ia, Cthulu ftagn!"));
    break;
  case 5:
  display.println(F("penguin"));//5
    break;
  case 6:
  display.println(F("42"));
    break;
  case 7:
  display.println(F("1,1,2,3,5,8,13,21,34,"));
    break;
  case 8:
  display.println(F("3.141592653589793238462"));
    break;
  case 9:
  display.println(F("2.7182818284590452353602874"));
    break;
  case 10:
  display.println(F("Give the cats treats"));//10
    break;
  case 11:
  display.println(F("Feed me"));
    break;
  case 12:
  display.println(F("Hello?"));
    break;
  case 13:
  display.println(F("Is this working?"));
    break;
  case 14:
  display.println(F("It's dangerous to go alone"));
    break;
  case 15:
  display.println(F("you are likely to be eaten")); //15
    break;
  case 16:
  display.println(F("Don't panic!")); 
    break;
  case 17:
  display.println(F("Relax"));
    break;
  case 18:
  display.println(F("Relax, don't do it"));
    break;
  case 19:
  display.println(F("Blood type: A+"));
    break;
  case 20:
  display.println(F("Let me out")); //20
    break;
  case 21:
  display.println(F("Error 101"));
    break;
  case 22:
  display.println(F("File not found"));
    break;
  case 23:
  display.println(F("Heart not found"));
    break;
  case 24:
  display.println(F("Game over"));
    break;
  case 25:
  case 26:
  display.println(F("Abort, retry, fail?")); //25
    break;
  case 27:
  display.println(F("Prepare the sacrifice"));
    break;
  case 28:
  display.println(F("By the power of magic"));
    break;
  case 29:
  display.println(F("Where is the catnip?"));
    break;
  case 30:
  display.println(F("Release the kraken"));
    break;
  case 31:
  display.println(F("Beam me up")); //30
    break;
  case 32:
  display.println(F("2B|!2B"));
    break;
    case 33:
display.println(F("I've got a feeling"));
    break;
  case 34:
  display.println(F("Where's my towel?"));
    break;
  case 35:
  display.println(F("Hail Satan!"));
    break;
  case 36:
    display.println(F("Mythos:99"));
    display.println(F("Sanity:99"));
    break;
  }
  display.display();
  
  delay(5000);
}

void loop() {

  unsigned long seconds = millis()/1000;
  
  int san = 100 - seconds/21;
  san = constrain(san, 1, 99);

  

  print_sanity(san);

  if(millis() > next_roll){
    next_roll +=1000;
    if(random(-100,100)>san){
      fuck_with_ppl();
    }
  }    
}
