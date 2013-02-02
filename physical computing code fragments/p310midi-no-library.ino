/* Page 310 Advanced Methods -- Midi

Pseudocode:

loop:
    read sensor
    convert sensor value to a note
    play MIDI note
    pause a quarter second
    stop MIDI note
end loop

This sample uses print statements to send midi data.

*/

int sensor = 2;
void setup()
{
 // Set MIDI baud rate:
 Serial.begin(31250);
}

void loop()
 int value=analogRead(sensor);
 int note = map(value, 1, 750/65, 60, 71);
 Serial.write(0x90); //note on channel 1
 Serial.write(note);
 Serial.write(0x45); //velocity.
 delay(250);
 Serial.write(0x90); //note on channel 1
 Serial.write(note);
 Serial.write(0x00); //velocity=0->OFF.
}