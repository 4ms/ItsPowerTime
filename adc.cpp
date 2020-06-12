#include "mbed.h"

AnalogIn adc12V(PA_5); //CH5
AnalogIn adc5V(PA_1); //CH1
AnalogIn adcN12V(PA_7); //CH7
AnalogIn adc12A(PC_4); //CH14
AnalogIn adc5A(PA_2); //CH2
AnalogIn adcN12A(PF_6); //CH4


//            float adc12V_involts = adc12V.read() * 24.0f;
//            sprintf((char*)text, "+12V = %.2f", adc12V_involts);
//            lcd.DisplayStringAt(0, LINE(8), (uint8_t *)&text, LEFT_MODE);
//            
//            float adcN12V_involts = adcN12V.read() * 24.0f;
//            sprintf((char*)text, "-12V = %.2f", adcN12V_involts);
//            lcd.DisplayStringAt(0, LINE(9), (uint8_t *)&text, LEFT_MODE);
//            
//            float adc5V_involts = adc5V.read() * 10.0f;
//            sprintf((char*)text, "+5V = %.2f", adc5V_involts);
//            lcd.DisplayStringAt(0, LINE(10), (uint8_t *)&text, LEFT_MODE);
