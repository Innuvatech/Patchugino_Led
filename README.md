# Patchugino_Led
Arduino library for Patchugino_Led shield board

## Getting Started
This library allows to control the Patchugino_Led shield board which can be mounted on top of a PatchugoLite board. It is therefore necessary to have
the Patchugo Boards package installed from [Arduino Boards Manager](https://docs.arduino.cc/learn/starting-guide/cores/). 

If you have not done that already, add this link in the "_Additional Boards Managers URLs_" in Arduino preferences:

https://github.com/Innuvatech/BoardManagerFiles/raw/main/package_innuvatech_index.json

## Board Description
The Patchugino_Led board is a shield board that can be plugged on top of a PatchugoLite board. It allows to control up to 4 PWM channels or a single RGB led strip.
The PWM channels can be setup to be used by dirrent pins making it possible to stack up to 2 Pathcugino_Led boards together. The 4 PWM channels configuration is done trough H17, H18, H19 and H20 pin headers.


### Power Supply
The board needs to be powered from an external 24V supply on the CN8 connector. If a led strip is to be connected it must be wired to the CN11 connector

## Library Usage
The arduino library allows to control the board in a really simple and intuitive way with just a few lines of code. It allows to initialize the board by specifying the channels configuration that has been set with H17, H18, H19 and H20 pin headers. It comes with prebuilt functions to configure channels for RGB and to write colors.

### Initialization
The library provides and Initialization function called **Init** that allows to initialize everything that the board needs in order to work. The function takes the following parameters as input:
  - **ch1Sel**: Specifies which pin selected for channel 1 from the H17 pin header. If not provided this value defaults to LED_CHANNEL_1_SEL_1 which means that by default the board supposes there's a jumper to 1 on H17. This parameter can have the following values:
      - LED_CHANNEL1_SEL_1: Jumper to 1 on H17
      - LED_CHANNEL1_SEL_2: Jumper to 2 on H17  
  - **ch2Sel**: Specifies which pin selected for channel 2 from the H18 pin header. If not provided this value defaults to LED_CHANNEL_2_SEL_1 which means that by default the board supposes there's a jumper to 1 on H18. This parameter can have the following values:
      - LED_CHANNEL2_SEL_1: Jumper to 1 on H11
      - LED_CHANNEL2_SEL_2: Jumper to 2 on H11  
  - **ch3Sel**: Specifies which pin selected for channel 3 from the H19 pin header. If not provided this value defaults to LED_CHANNEL_3_SEL_1 which means that by default the board supposes there's a jumper to 1 on H19. This parameter can have the following values:
      - LED_CHANNEL3_SEL_1: Jumper to 1 on H19
      - LED_CHANNEL3_SEL_2: Jumper to 2 on H19  
  - **ch4Sel**: Specifies which pin selected for channel 4 from the H10 pin header. If not provided this value defaults to LED_CHANNEL_4_SEL_1 which means that by default the board supposes there's a jumper to 1 on H20. This parameter can have the following values:
      - LED_CHANNEL4_SEL_1: Jumper to 1 on H20
      - LED_CHANNEL4_SEL_2: Jumper to 1 on H20  
   -   **serial(optional)**: This is an optional parameter. It specifies the Serial instance used by the internal logs of the library. If not provided this parameter defaults to the default Serial instance of the                   PatchugoLite board
  -   **logLevel(optional)**: This specifies the logging level of the library. Setting a higher logging level means more logs from the library will be shown. Logs from the library can be disabled by setting this to                   **LOG_LEVEL_NONE**. For more information about logging please consult the [Patchugo_Core](https://github.com/Innuvatech/Patchugo_Core) repository

#### Minimal initialization

```
  /*
    IMPORTANT!!! Patchugino PT100 library needs
    Serial instance to be initialized before calling any function!
  */
  Serial.begin(115200);

  //Initialize the PT100 shield board and specify which CS it's using(CS0 in this case)
  //Since serial and logLevel are not specified this will default to using Serial with LOG_LEVEL_VERBOSE
  patchuginoPt100.Init(PT100_CS_0);
```

#### Custom logging initialization
```
  /*
    IMPORTANT!!! Patchugino PT100 library needs
    Serial instance to be initialized before calling any function!
  */
  HardwareSerial mySerial(PA10, PA11);
  
  //Initialize the PT100 shield board and specify which CS it's using(CS0 in this case)
  //This will use mySerial as logs output channel and will only show DEBUG level logs or lower
  patchuginoPt100.Init(PT100_CS_0, mySerial, LOG_LEVEL_DEBUG);
```
#### No logging initialization
```
void setup() {
  /*
    IMPORTANT!!! Patchugino PT100 library needs
    Serial instance to be initialized before calling any function!
  */
  Serial.begin(115200);
  
  //Initialize the PT100 shield board and specify which CS it's using(CS0 in this case)
  //This will disable logs of the library. A valid Serial instance still needs to be provided
  patchuginoPt100.Init(PT100_CS_0, Serial, LOG_LEVEL_NONE);
```

### Writing to a channel
A function to write to any channel is provided and is called **WriteChannel**. It take the following parameters:
  - **channel**: Which channel is being controlled. This parameter can be assigned the following values:
    - CHANNEL_1
    - CHANNEL_2
    - CHANNEL_3
    - CHANNEL_4
  - **val**: PWM value to write to the channel(0 to 255)

An example is provided below
```
  //Writes 113 to channel 2
  patchuginoLed.WriteChannel(LED_CHANNEL_2, 113);
```

### Configuring channels for RGB
The library provides a function to set which channels should be used for RGB. By default if not configured the channel for RED is set to CHANNEL_1, the channel for GREEN is set to CHANNEL_2 and the channel for BLUE is set to CHANNEL_3. The function is called **SetRGBChannel** and takes the following parameters:
  - **redCh**: Channel to set for controlling RED
  - **grCh**: Channel to set for controlling GREEN
  - **blCh**: Channel to set for controlling BLUE

An example is provided below
```
  //Set RED channel to CHANNEL_4, GREEN channel to CHANNEL_3 and BLUE channel to CHANNEL_1
  patchuginoLed.SetRGBChannel(LED_CHANNEL_4,LED_CHANNEL_3,LED_CHANNEL_1);
```

### Writing RGB values
The library provid+es a function that lets the user write RGB values to the channels for colors. 2 overloads of the same function are available. The function is called **WriteRGB**. It can either take 3 uint8_t values as parameters for red, green and blue or it can take an uint8_t array of length 3 where 0 is red, 1 is green and 2 is blue. An example is provided below:

```
  //This is valid
  uint8_t myRed = 100;
  uint8_t myGreen = 0;
  uint8_t myBlue = 255;
  patchuginoLed.WriteRGB(myRed,myGreen,myBlue);

  //This is also valid
  uint8_t myColor[3] = {100, 12, 200};
  patchuginoLed.WriteRGB(myColor);
```

Some definitions are available for predefined colors. The full list can be found below:
  - RED
  - GREEN
  - BLUE
  - WHITE
  - YELLOW
  - AQUA
  - MAGENTA
  - SILVER
  - GRAY
  - MAROON
  - OLIVE
  - PURPLE
  - TEAL
  - NAVY
