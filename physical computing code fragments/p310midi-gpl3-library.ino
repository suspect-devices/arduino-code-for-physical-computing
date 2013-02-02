/* Page 310 Advanced Methods -- Midi 

Pseudocode:

loop:
    read sensor
    convert sensor value to a note
    play MIDI note
    pause a quarter second
    stop MIDI note
end loop

This sample uses the arduino midi library  midi data.

*/

#include <Midi.h>
void setup() {
  MIDI.begin(0);            	// input channel is set to 0
}

void loop() {
  int value=analogRead(sensor);
  note = map(value, 1, 750/65, 60, 71); 
  MIDI.sendNoteOn(note,40,0); 
  delay(250); // Wait for a bit
  MIDI.sendNoteOff(note,0,0); 
}