# wavegen

Four simple classes that will generate four types of waveforms:
* Sine wave
* Triangle wave
* Sawtooth wave
* Pulse wave (includes Square wave)

You can specify the frequency, amplitude, and sample rate for each type.  The pulse wave adds the ability to specify the duty cycle (use 50% for square wave).
The unamplified output sample values are 128-bit values between 1.0 and -1.0 that will need to be adjusted for PCM-based playback.

You can use these for any C++ project you wish as only very small parts of the STL are required which are easy to replace if needed.
