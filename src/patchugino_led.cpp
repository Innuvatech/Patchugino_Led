/**
* File: patchugino_led.cpp
* Created on: 2025-08-05 at 16:42
* Author: Andrea Rantin
* Description: Implementation file for patchugino_led.h
*/

#include "patchugino_led.h"

uint32_t Patchugino_Led::GetPin_FromChannel(LedChannel channel) {
    switch(channel) {
        case LED_CHANNEL_1:
            return ch1Pin;
        case LED_CHANNEL_2:
            return ch2Pin;
        case LED_CHANNEL_3:
            return ch3Pin;
        case LED_CHANNEL_4:
            return ch4Pin;
        default:
            break;
    }

    return 0;
}

void Patchugino_Led::Init(LedChannel1Sel ch1Sel, LedChannel2Sel ch2Sel, LedChannel3Sel ch3Sel, LedChannel4Sel ch4Sel, HardwareSerial& serial, PatchugoLogLevel logLevel) {

    //Initialize logger
    static Patchugo_Logger localLogger(serial, logLevel);
    logger = &localLogger;

    logger->Log_Info("Patchugino Led initializing\n");

    ch1Pin = static_cast<uint32_t>(ch1Sel);
    ch2Pin = static_cast<uint32_t>(ch2Sel);
    ch3Pin = static_cast<uint32_t>(ch3Sel);
    ch4Pin = static_cast<uint32_t>(ch4Sel);

    pinMode(ch1Pin, OUTPUT);
    pinMode(ch2Pin, OUTPUT);
    pinMode(ch3Pin, OUTPUT);
    pinMode(ch4Pin, OUTPUT);

    SetRGBChannel();

    logger->Log_Info("Patchugino Led initialized\n");

}

void Patchugino_Led::WriteChannel(LedChannel channel, uint8_t val) {
    uint32_t channelPin = GetPin_FromChannel(channel);
    analogWrite(channelPin, val);
}

void Patchugino_Led::SetRGBChannel(LedChannel redCh, LedChannel grCh, LedChannel blCh) {
    redPin = GetPin_FromChannel(redCh);
    greenPin = GetPin_FromChannel(grCh);
    bluePin = GetPin_FromChannel(blCh);
}

void Patchugino_Led::WriteRGB(uint8_t red, uint8_t green, uint8_t blue) {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin , blue);
}

void Patchugino_Led::WriteRGB(const uint8_t *rgbBuf) {
    analogWrite(redPin, rgbBuf[0]);
    analogWrite(greenPin, rgbBuf[1]);
    analogWrite(bluePin, rgbBuf[2]);
}
