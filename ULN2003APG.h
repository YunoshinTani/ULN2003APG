#ifndef ULN2003APG_H
#define ULN2003APG_H

#include <mbed.h>

class ULN2003APG
{
public:
    ULN2003APG(PinName IN1, PinName IN2, PinName IN3, PinName IN4);

    void one_phase(int pulse_frequency);
    
    void two_phase(int pulse_frequency);
    
    void half_step(int pulse_frequency);

private:
    DigitalOut _IN1;
    DigitalOut _IN2;
    DigitalOut _IN3;
    DigitalOut _IN4;

    DigitalOut _step_in[4];

    int hz_to_ms(int frequency);
};

#endif // ULN2003APG_H