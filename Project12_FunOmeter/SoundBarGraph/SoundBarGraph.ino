
const int MICPIN = 0;

void setup()
{}

void loop()
{
  int volume,x;
  static int highest = 0;
  float percent;
  
  volume = measureVolume(200);

  if (volume > highest) highest = volume;
  
  percent = (volume / highest)*10;

  for (x=0; x<percent; x++)
    Serial.print("#");
  Serial.println();
}

int measureVolume(int numsamples)
// Because sound travels in waves, you can't figure out
// how loud it is from a single sample. This function
// takes a bunch of samples (numsamples) of the waveform,
// keeping track of the largest and smallest values it finds.
// The volume is the difference between the highest and
// lowest values.

// To get the high and low values, you want to take enough
// samples to measure at least one full waveform cycle.
// A very low frequency noise (20Hz) will take about 50ms
// for a full cycle. An Arduino running at 16MHz can take
// about 10,000 samples per second. So you should take at
// least 200 samples for low-frequency noises.
{
  // Initialize high and low to the opposite max numbers.
  // They will set themselves to the real high and low
  // once you start taking samples:
  
  int lowest = 255;
  int highest = 0;
  int n, sample;
  
  // Take our samples:
 
  for (n = 0; n <= numsamples; n++)
  {
    sample = analogRead(MICPIN);
    
    // Reset the high and low values as necessary:

    if (sample > highest)
    {
      highest = sample;  
    }
    
    if (sample < lowest)
   {
     lowest = sample;
   } 
  }

  // The volume is the amplitude of the waveform,
  // which is the difference between the highest and lowest
  // values.
  
  return highest-lowest;
}
