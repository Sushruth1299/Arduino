/* ********************************************************************** 
 * 7-SegmentDisplay - v1.0
 *   Uses Common cathode 7-segment display,
 *   Uses 74HC595 shift register IC
 *   
 * Inspired by Elegoo Lesson 27 www.elegoo.com
 *   modified by Ricardo Moreno
 *
 * Description:
 *   This sketch illustrates the controlling a 7-segment display with
 *   a 74HC595 shift register.
 *   
 *  History:
 *  5/04/2019 v1.0 - Initial release
 *  
 * define the LED digit patterns, from 0 - 9
 * 1 = LED on, 0 = LED off, common cathode, in this order:
 *           74HC595 pin     Q7,Q6,Q5,Q4,Q3,Q2,Q1,Q0 
 *           Mapping to      g,f,e,d,c,dp,a,b of Seven-Segment LED
 * ********************************************************* */
 /* ***********************************************************
 *                      Global Constants                     *
 *                    Hardware Definitions                   *
 * ********************************************************* */
int latchPin = 3; // connect to the ST_CP of 74HC595 (pin 3,latch pin)
int clockPin = 4;  // connect to the SH_CP of 74HC595 (pin 4, clock pin)
int dataPin = 2;  // connect to the DS of 74HC595 (pin 2)

byte sevenSegDigits[10] = { B00111111   ,  // = 0
                            B00000110   ,  // = 1
                            B01011011   ,  // = 2
                            B01001111   ,  // = 3
                            B01100110   ,  // = 4
                            B11101101   ,  // = 5
                            B01111101   ,  // = 6
                            B00000111   ,  // = 7
                            B01111111   ,  // = 8
                            B01101111      // = 9
                           };
byte sevenSegDP = B00000100;  // = DP


/* ***********************************************************
 *                      Global Variables                     *
 * ********************************************************* */
bool bAddDecimalPoint = true;            // display state of show decimal point

/* ***********************************************************
 *                         Void setup                        *
 * ********************************************************* */
void setup() {
    // Set latchPin, clockPin, dataPin as output
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

/* ***********************************************************
 *                         Functions                         *
 * ********************************************************* */ 
// display a alpha, binary value, or number on the digital segment display
void sevenSegWrite(byte digit, bool bDP = false, char switchValue='D') {
    /*       digit = array pointer or binary value, as a byte 
     *         bDP = true-include decimal point, as boolean
     * switchValue = 'A' alpha
     *               'B' binary
     *               'D' digits <default>, as char           */
    
    // set the latchPin to low potential, before sending data
    digitalWrite(latchPin, LOW);
     
    // the data (bit pattern)
    if (switchValue=='A'){
        // binary
        shiftOut(dataPin, clockPin, MSBFIRST, digit+(sevenSegDP*bDP));
    } else {
        // digits
        shiftOut(dataPin, clockPin, MSBFIRST, sevenSegDigits[digit]+(sevenSegDP*bDP));   
    }
 
    // set the latchPin to high potential, after sending data
    digitalWrite(latchPin, HIGH);
}

void sevenSegBlank(){
    // set the latchPin to low potential, before sending data
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B00000000);  
    // set the latchPin to high potential, after sending data
    digitalWrite(latchPin, HIGH);
}

/* ***********************************************************
 *                         Void Loop                         *
 * ********************************************************* */
void loop() {
  //Switch add decimal point states
  bAddDecimalPoint = !bAddDecimalPoint;       
  // count from 0 to 9
  // Change byte to int - byte doesn't have a negative number
  sevenSegWrite(5);
  delay(500);
  sevenSegBlank();
  delay(500);
}