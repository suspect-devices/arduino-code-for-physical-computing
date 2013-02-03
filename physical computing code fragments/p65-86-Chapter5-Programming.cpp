/*Programming

Chapter 5 is a lot of good grounding but its all written in dialects of basic. Here we have to do a little explaining as well as translating the code. I am splitting the chapter in half for this reason.
Loops (p66)

The event loop that the book refers to is hidden by  the Arduino IDE but the actual event loop used by the  current arduino core (1.0.3)  uses a “for” loop.
*/

for (;;) {
    loop();
    if (serialEventRun) serialEventRun();
        }

//This could also be written as

while(true)
loop();
if (serialEventRun) serialEventRun();
}

If Statements (p67)

if (in6 == 1) {
    /*Statement1*/;
}
/*Statement2*/

//Please note the == to indicate testing for equality. The statement

if (in6 = 1)

/* would set the value of  in6 to 1 and return 1 which would be true.
The brackets above are optional if only one statement is part of the condition as you can see in the Code examples above however they do remove any potential ambiguity and I highly suggest you use them

 Variables (p69).

In c variables must be declared with a type. They can be initialized and declared at the same time. In straight c they must be declared at the top of a function or, if global, outside of the function. In cpp which the arduino used they can be inserted as needed.
*/
int Date=12;
int ticketValue = 250;
int Fare=125
/*
Variable type sizes can be different between machines. In general an int is a short int which is usually 16 bits and a character is 8 bits but this is not guaranteed. Also integers can be either signed or unsigned. The arduino provides some types that help you specify exactly what you mean.
*/
uint8_t Sensor; // an 8 bit unsigned variable
uint8_t Ticket
uint16_t Bigger; // this is a 16 bit unsigned variable

//And the code on page71 could be written.

uint8_t ticketsSubmitted=0;
uint8_t ticketSensor=0;

loop {
    if (ticketSensor==1) {
        ticketsSubmitted++;
    }
    if (ticketSubmitted ==3) {
        OpenGate();
        ticketsSubmitted=0;
    }
}
/*
Built-in Routines: Subroutines and Functions.

In ‘c’ subroutines are functions which return void as a result. The arduino “core” provides a rich set of built in functions to interact easily with pins. In addition the underlying gcc provides defines allowing you to interact directly with the processors registers.
*/
digitalWrite(13,HIGH);
PORTB |= _BV(0);
/*
Both of the above set pin 0 of port b on the arduino to high.
Constants (p73)

Constants in c are handled by the pre processor which replaces the value before compiling the code. Unlike using variables, using preprocessor macroes does not cost you any memory to store the values. C Convention has macros in all caps.
*/
#define MIN_PULSE 100
PulseWidth = MIN_PULSE + angle;
/*
Which would expand to
*/
PulseWidth = 100 + angle;
/*
(p74)
*/
#define MY_FAVORITE_PIN_NO 14
#define MY_FAVORITE_PINS PINB
#define MY_FAVORITE_PIN PINB0
printState=digitalRead(MY_FAVORITE_PIN_NO);
printState=MY_FAVORITE_PINS & _BV(MY_FAVORITE_PIN); // does more or less the same as the above.
/*
C values are passed to routines through a stack and they become local to the function and go away when it exits. To get a function to modify a value like the examples at the bottom of page 74 you would pass the address of  the value that needs to be changed. This is called “passed by reference”
*/
int sensor;
rctime(5,1,&sensor); // the and here means "the memory address of sensor"

//Tomorrow we will go through Home Made Routines, Advanced Loops, Pseudo code, Comments, and Debugging”;