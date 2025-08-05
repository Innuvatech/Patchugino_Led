/**
* File: patchugino_led.h
* Created on: 2025-08-05 at 16:23
* Author: Andrea Rantin
* Description: //TODO
*/

#pragma once

#include "patchugo_core.h"
#include "internal/patchugino_led_types.h"

using namespace PatchuginoLed;

namespace PatchuginoLed {

    class Patchugino_Led {
        private:
            Patchugo_Logger* logger = nullptr; /*<! Logger instance used for logging of this library*/
            uint32_t redPin; /*!< Red PWM control pin*/
            uint32_t greenPin; /*!< Green PWM control pin*/
            uint32_t bluePin; /*!< Blue PWM control pin*/
            uint32_t ch1Pin; /*!< Channel 1 PWM pin*/
            uint32_t ch2Pin; /*!< Channel 2 PWM pin*/
            uint32_t ch3Pin; /*!< Channel 3 PWM pin*/
            uint32_t ch4Pin; /*!< Channel 4 PWM pin*/
            /**
             * @brief Returns the PWM pin corresponding to the given channel
             * 
             * @param channel Channel to use
             * @return uint32_t Pin corresponding to the channel
             */
            uint32_t GetPin_FromChannel(LedChannel channel);
        public:
            void Init(
                LedChannel1Sel ch1Sel = LED_CHANNEL_1_SEL_1, 
                LedChannel2Sel ch2Sel = LED_CHANNEL_2_SEL_1, 
                LedChannel3Sel ch3Sel = LED_CHANNEL_3_SEL_1, 
                LedChannel4Sel ch4Sel = LED_CHANNEL_4_SEL_1,
                HardwareSerial& serial = Serial,
                PatchugoLogLevel logLevel = LOG_LEVEL_VERBOSE);

            /**
            * @brief Writes a PWM value to the given channel
            * 
            * @param channel Channel to write
            * @param val PWM value to write
            */
            void WriteChannel(LedChannel channel, uint8_t val);

            /**
            * @brief Sets the PWM channels for RGB
            * 
            * @param redCh Red channel
            * @param grCh Green channel
            * @param blCh Blue channel
            */
            void SetRGBChannel(
                LedChannel redCh = LED_CHANNEL_1, 
                LedChannel grCh = LED_CHANNEL_2, 
                LedChannel blCh = LED_CHANNEL_3
            );

            /**
            * @brief Writes an RGB color to the channels
            * 
            * @param red Red value
            * @param green Green value
            * @param blue Blue value
            */
            void WriteRGB(uint8_t red, uint8_t green, uint8_t blue);

            /**
            * @brief Writes an RGB color to the channels
            * 
            * @param rgbBuf Buffer with the 3 color values(R, G, B)
            */
            void WriteRGB(const uint8_t *rgbBuf);
    };
}

