#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2SHex         i2s_hex1;       //xy=106,155
AudioSynthWaveformSine   sine1;          //xy=246,378
AudioSynthWaveformSine   sine2;          //xy=251,419
AudioMixer4              mixer2;         //xy=289,290
AudioMixer4              mixer1;         //xy=291,217
AudioMixer4              mixer3;         //xy=501,274
AudioAmplifier           amp1;           //xy=694,277
AudioAnalyzePeak         peak1;          //xy=700,212
AudioOutputI2SQuad       i2s_quad1;      //xy=1021,285
AudioConnection          patchCord1(i2s_hex1, 0, mixer1, 0);
AudioConnection          patchCord2(i2s_hex1, 1, mixer1, 1);
AudioConnection          patchCord3(i2s_hex1, 2, mixer1, 2);
AudioConnection          patchCord4(i2s_hex1, 3, mixer1, 3);
AudioConnection          patchCord5(i2s_hex1, 4, mixer2, 0);
AudioConnection          patchCord6(i2s_hex1, 5, mixer2, 1);
AudioConnection          patchCord7(sine1, 0, i2s_quad1, 2);
AudioConnection          patchCord8(sine2, 0, i2s_quad1, 3);
AudioConnection          patchCord9(mixer2, 0, mixer3, 1);
AudioConnection          patchCord10(mixer1, 0, mixer3, 0);
AudioConnection          patchCord11(mixer3, peak1);
AudioConnection          patchCord12(mixer3, amp1);
AudioConnection          patchCord13(amp1, 0, i2s_quad1, 0);
AudioConnection          patchCord14(amp1, 0, i2s_quad1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=448,30
// GUItool: end automatically generated code


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  AudioMemory(18);
  Serial.begin(9600);

  Wire.beginTransmission(0x70);
  Wire.write(1<<0);
  Wire.endTransmission();

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.7);

  Wire.beginTransmission(0x70);
  Wire.write(1<<1);
  Wire.endTransmission();

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.45);

  Wire.beginTransmission(0x70);
  Wire.write(1<<2);
  Wire.endTransmission();

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.45);

  sine1.amplitude(0.5);
  sine2.amplitude(0.5);
  sine1.frequency(200);
  sine2.frequency(300);

  mixer1.gain(0, 1.0);
  mixer1.gain(1, 1.0);
  mixer1.gain(2, 1.0);
  mixer1.gain(3, 1.0);
  mixer2.gain(0, 1.0);
  mixer2.gain(1, 1.0);
  mixer3.gain(0, 1.0);
  mixer3.gain(1, 1.0);
  amp1.gain(4.0);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  Serial.println(peak1.readPeakToPeak());
}
