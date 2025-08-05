/**
* File: patchugino_led_types.h
* Created on: 2025-08-05 at 16:23
* Author: Andrea Rantin
* Description: //TODO
*/

#pragma once

#include <Arduino.h>

namespace PatchuginoLed {

    static constexpr uint8_t RGB_DATA_LEN = 3; /*!< RGB is 3 bytes for colors*/

    static constexpr uint8_t RED[RGB_DATA_LEN] = {0xFF,0,0}; /*!< RGB Red color*/
    static constexpr uint8_t GREEN[RGB_DATA_LEN] = {0,0xFF,0}; /*!< RGB Green color*/
    static constexpr uint8_t BLUE[RGB_DATA_LEN] = {0,0,0xFF}; /*!< RGB Blue color*/
    static constexpr uint8_t WHITE[RGB_DATA_LEN] = {0xFF,0xFF,0xFF};
    static constexpr uint8_t YELLOW[RGB_DATA_LEN] = {0xFF,0xFF,0};
    static constexpr uint8_t AQUA[RGB_DATA_LEN] = {0,0xFF,0xFF};
    static constexpr uint8_t MAGENTA[RGB_DATA_LEN] = {0xFF,0,0xFF};
    static constexpr uint8_t SILVER[RGB_DATA_LEN] = {192,192,192};
    static constexpr uint8_t GRAY[RGB_DATA_LEN] = {128,128,128};
    static constexpr uint8_t MAROON[RGB_DATA_LEN] = {128,0,0};
    static constexpr uint8_t OLIVE[RGB_DATA_LEN] = {128,128,0};
    static constexpr uint8_t PURPLE[RGB_DATA_LEN] = {128,0,128};
    static constexpr uint8_t TEAL[RGB_DATA_LEN] = {0,128,128};
    static constexpr uint8_t NAVY[RGB_DATA_LEN] = {0,0,128};


    /**
    * @brief Channel 1 jumper selection on H7
    * 
    */
    enum class LedChannel1Sel {
        CHANNEL_1_SEL_1 = D5,
        CHANNEL_1_SEL_2 = A4,
    };

    //Utility constant expressions to ease use of enum class of LedChannel1Sel
    static constexpr LedChannel1Sel LED_CHANNEL_1_SEL_1 = LedChannel1Sel::CHANNEL_1_SEL_1;
    static constexpr LedChannel1Sel LED_CHANNEL_1_SEL_2 = LedChannel1Sel::CHANNEL_1_SEL_2;

    /**
    * @brief Channel 2 jumper selection on H8
    * 
    */
    enum class LedChannel2Sel {
        CHANNEL_2_SEL_1 = D4,
        CHANNEL_2_SEL_2 = D9,
    };

    //Utility constant expressions to ease use of enum class of LedChannel2Sel
    static constexpr LedChannel2Sel LED_CHANNEL_2_SEL_1 = LedChannel2Sel::CHANNEL_2_SEL_1;
    static constexpr LedChannel2Sel LED_CHANNEL_2_SEL_2 = LedChannel2Sel::CHANNEL_2_SEL_2;

    /**
    * @brief Channel 1 jumper selection on H9
    * 
    */
    enum class LedChannel3Sel {
        CHANNEL_3_SEL_1 = D3,
        CHANNEL_3_SEL_2 = D7,
    };

    //Utility constant expressions to ease use of enum class of LedChannel3Sel
    static constexpr LedChannel3Sel LED_CHANNEL_3_SEL_1 = LedChannel3Sel::CHANNEL_3_SEL_1;
    static constexpr LedChannel3Sel LED_CHANNEL_3_SEL_2 = LedChannel3Sel::CHANNEL_3_SEL_2;

    /**
    * @brief Channel 4 jumper selection on H10
    * 
    */
    enum class LedChannel4Sel {
        CHANNEL_4_SEL_1 = D2,
        CHANNEL_4_SEL_2 = D6,
    };

    //Utility constant expressions to ease use of enum class of LedChannel4Sel
    static constexpr LedChannel4Sel LED_CHANNEL_4_SEL_1 = LedChannel4Sel::CHANNEL_4_SEL_1;
    static constexpr LedChannel4Sel LED_CHANNEL_4_SEL_2 = LedChannel4Sel::CHANNEL_4_SEL_2;

    /**
    * @brief One of the 4 usable channels of the board
    * 
    */
    enum class LedChannel {
        CHANNEL_1,
        CHANNEL_2,
        CHANNEL_3,
        CHANNEL_4,
    };
    
    //Utility constant expressions to ease use of enum class of LedChannel
    static constexpr LedChannel LED_CHANNEL_1 = LedChannel::CHANNEL_1;
    static constexpr LedChannel LED_CHANNEL_2 = LedChannel::CHANNEL_2;
    static constexpr LedChannel LED_CHANNEL_3 = LedChannel::CHANNEL_3;
    static constexpr LedChannel LED_CHANNEL_4 = LedChannel::CHANNEL_4;
}


