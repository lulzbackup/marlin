#ifndef CONFIGURATION_LULZBOT
#define CONFIGURATION_LULZBOT

#if !defined(TOOLHEAD_Single) && \
    !defined(TOOLHEAD_Flexy) && \
    !defined(TOOLHEAD_Moar) && \
    !defined(TOOLHEAD_Dually) && \
    !defined(TOOLHEAD_YellowfinDual)
#error Must specify toolhead to build:
#error
#error   make clean
#error   make TOOLHEAD=<toolhead>
#error
#error   Choices:
#error      Single
#error      Flexy
#error      Moar
#error      Dually
#error      YellowfinDual
#endif

/* We define the LULZBOT_ values based on which print head or printer variants we are compiling for,
 * these constants are then placed where appropriate in the following files:
 *
 *    - Configuration.h
 *    - Configuration_adv.h
 *    - pins.h
 *    - Default_Version.h
 *
 * Using our own set of constants make it easier to keep track of changes from upstream.
 */

// Shared values
#define LULZBOT_DEFAULT_ACCELERATION          500
#define LULZBOT_FAN_PIN                       8
#define LULZBOT_EXTRUDERS                     1
#define LULZBOT_EXTRUDER_OFFSET_X             {0.0, 0.00}
#define LULZBOT_EXTRUDER_OFFSET_Y             {0.0, -52.00}
#define LULZBOT_Z_SAFE_HOMING_X_POINT         (-19)
#define LULZBOT_Z_SAFE_HOMING_Y_POINT         (258)
#define LULZBOT_Z_RAISE_BEFORE_HOMING         5
#define LULZBOT_Z_RAISE_BEFORE_PROBING        5
#define LULZBOT_Z_RAISE_BETWEEN_PROBINGS      5
#define LULZBOT_Z_RAISE_AFTER_HOMING          5
#define LULZBOT_LCD_LINE_1                    u8g.setFont(u8g_font_6x10_marlin); \
                                              u8g.drawStr(61,17,"TAZ 6");
#define LULZBOT_LCD_LINE_2                    u8g.setFont(u8g_font_5x8); \
                                              u8g.drawStr(95,17,"Single");
#define LULZBOT_LCD_LINE_3                    u8g.setFont(u8g_font_6x10_marlin); \
                                              u8g.drawStr(62,28,"3D Printer");
#define LULZBOT_LEFT_PROBE_BED_POSITION       -9
#define LULZBOT_RIGHT_PROBE_BED_POSITION     288
#define LULZBOT_BACK_PROBE_BED_POSITION      289
#define LULZBOT_FRONT_PROBE_BED_POSITION      -9
#define LULZBOT_REWIPE_X_POSITION            -16
#define LULZBOT_REWIPE_BACK_POSITION          95
#define LULZBOT_REWIPE_FRONT_POSITION         25

#if defined(TOOLHEAD_Single)
    #define LULZBOT_TOOLHEAD_VER               VERSION_STRING
    #define LULZBOT_BUILD_VERSION              " LulzBot"
    #define LULZBOT_DIGIPOT_MOTOR_CURRENT      {175,175,200,135,135} // Values 0-255 (RAMBO 135 = ~0.75A, 185 = ~1A)
    #define LULZBOT_UUID                       "845f003c-aebd-4e53-a6b9-7d0984fde609"
    #define LULZBOT_X_MAX_ENDSTOP_INVERTING    false
    #define LULZBOT_X_MAX_POS                  300     // Travel limits after homing
    #define LULZBOT_X_MIN_POS                  -20     // Travel limits after homing
    #define LULZBOT_Y_MAX_POS                  303     // Travel limits after homing
    #define LULZBOT_Y_MIN_POS                  -20     // Travel limits after homing
    #define LULZBOT_Z_MAX_POS                  270     // Travel limits after homing
    #define LULZBOT_Z_MIN_POS                    0     // Travel limits after homing
    #define LULZBOT_AO_Hexagon
#endif /* TOOLHEAD_Single */

#if defined(TOOLHEAD_Flexy)
    #define LULZBOT_TOOLHEAD_VER               VERSION_STRING" Flexystruder"
    #define LULZBOT_BUILD_VERSION              " LulzBot Flexy"
    #define LULZBOT_DIGIPOT_MOTOR_CURRENT      {175,175,200,67,135}
    #undef  LULZBOT_LCD_LINE_2
    #define LULZBOT_LCD_LINE_2                 u8g.setFont(u8g_font_5x8); \
                                               u8g.drawStr(95,17,"Flexy");
    #define LULZBOT_UUID                       "564bab1c-704c-4225-b329-ac1a093d2638"
    #define LULZBOT_X_MAX_ENDSTOP_INVERTING    true
    #define LULZBOT_X_MAX_POS                  288
    #define LULZBOT_X_MIN_POS                  -27
    #define LULZBOT_Y_MAX_POS                  302
    #define LULZBOT_Y_MIN_POS                  -20
    #define LULZBOT_Z_MAX_POS                  270
    #define LULZBOT_Z_MIN_POS                    0
    #define LULZBOT_AO_Hexagon
#endif /* TOOLHEAD_Flexy */

#if defined(TOOLHEAD_Moar)
    #define LULZBOT_TOOLHEAD_VER               VERSION_STRING
    #define LULZBOT_BUILD_VERSION              " LulzBot MOAR"
    #undef  LULZBOT_DEFAULT_ACCELERATION
    #define LULZBOT_DEFAULT_ACCELERATION       250
    #define LULZBOT_DIGIPOT_MOTOR_CURRENT      {175,175,200,135,135} // Values 0-255 (RAMBO 135 = ~0.75A, 185 = ~1A)
    #undef  LULZBOT_LCD_LINE_3
    #define LULZBOT_LCD_LINE_3                 u8g.setFont(u8g_font_5x8); \
                                               u8g.drawStr(62,28,"MOARstruder");
    #define LULZBOT_UUID                       "d651819d-4a79-4b73-bc5b-ae1fe1aab36b"
    #define LULZBOT_X_MAX_ENDSTOP_INVERTING    true
    #define LULZBOT_X_MAX_POS                  290
    #define LULZBOT_X_MIN_POS                  -20     // Travel limits after homing
    #define LULZBOT_Y_MAX_POS                  303     // Travel limits after homing
    #define LULZBOT_Y_MIN_POS                  -20     // Travel limits after homing
    #define LULZBOT_Z_MAX_POS                  270     // Travel limits after homing
    #define LULZBOT_Z_MIN_POS                    0     // Travel limits after homing
    #define LULZBOT_Moarstruder
#endif /* TOOLHEAD_Moar */

#if defined(TOOLHEAD_Dually) || defined(TOOLHEAD_YellowfinDual)
    #define LULZBOT_TOOLHEAD_VER               VERSION_STRING" Dual"
    #define LULZBOT_BUILD_VERSION              " LulzBot Dual"
    #undef  LULZBOT_FAN_PIN
    #define LULZBOT_FAN_PIN                    6
    #define LULZBOT_DIGIPOT_MOTOR_CURRENT      {175,175,200,160,160} // Values 0-255 (RAMBO 135 = ~0.75A, 185 = ~1A)
    #undef  LULZBOT_EXTRUDERS
    #define LULZBOT_EXTRUDERS                  2
    #undef  LULZBOT_EXTRUDER_OFFSET_X
    #define LULZBOT_EXTRUDER_OFFSET_X          {0.0, 0.00}
    #undef  LULZBOT_EXTRUDER_OFFSET_Y
    #define LULZBOT_EXTRUDER_OFFSET_Y          {0.0, 0.00}
    #undef  LULZBOT_LCD_LINE_2
    #define LULZBOT_LCD_LINE_2                 u8g.setFont(u8g_font_5x8); \
                                               u8g.drawStr(95,17,"Dual");
    #define LULZBOT_UUID                       "c5077702-4ecd-4532-beaf-6acf94acc404"
    #define LULZBOT_X_MAX_ENDSTOP_INVERTING    true
    #define LULZBOT_X_MAX_POS                     288
    #define LULZBOT_X_MIN_POS                     -22
    #define LULZBOT_Y_MAX_POS                     303     // Travel limits after homing
    #define LULZBOT_Y_MIN_POS                     -20     // Travel limits after homing
    #define LULZBOT_Z_MAX_POS                     270     // Travel limits after homing
    #define LULZBOT_Z_MIN_POS                       0     // Travel limits after homing
    #define LULZBOT_AO_Hexagon
#endif /* TOOLHEAD_Dually || TOOLHEAD_YellowfinDual */

#if defined(TOOLHEAD_Dually)
    #undef  LULZBOT_REWIPE_FRONT_POSITION
    #define LULZBOT_REWIPE_FRONT_POSITION          73
#endif /* TOOLHEAD_Dually */

#if defined(TOOLHEAD_YellowfinDual)
    #define LULZBOT_FAN_PIN                         6
    #undef  LULZBOT_REWIPE_X_POSITION
    #define LULZBOT_REWIPE_X_POSITION             -18
    #define LULZBOT_X_MAX_ENDSTOP_INVERTING     false   // Yellowfin toolhead has a normally closed endstop
    #undef  LULZBOT_Z_RAISE_BEFORE_HOMING
    #define LULZBOT_Z_RAISE_BEFORE_HOMING          15
    #undef  LULZBOT_Z_RAISE_BEFORE_PROBING
    #define LULZBOT_Z_RAISE_BEFORE_PROBING         15
    #undef  LULZBOT_Z_RAISE_BETWEEN_PROBINGS
    #define LULZBOT_Z_RAISE_BETWEEN_PROBINGS       15
    #undef  LULZBOT_Z_RAISE_AFTER_HOMING
    #define LULZBOT_Z_RAISE_AFTER_HOMING           15
    #undef  LULZBOT_Z_SAFE_HOMING_X_POINT
    #undef  LULZBOT_Z_SAFE_HOMING_Y_POINT
    #define LULZBOT_Z_SAFE_HOMING_X_POINT        (-22)    // X point for Z homing when homing all axis (G28)
    #define LULZBOT_Z_SAFE_HOMING_Y_POINT        (260)    // Y point for Z homing when homing all axis (G28)
    #undef  LULZBOT_X_MAX_POS
    #define LULZBOT_X_MAX_POS                      290
    #define LULZBOT_AO_Hexagon
#endif /* TOOLHEAD_YellowfinDual */

/* HOTEND Variants */

#if defined(LULZBOT_Moarstruder)
    // LulzBot MOARstruder (40v)
    #define LULZBOT_DEFAULT_Kp 55.64
    #define LULZBOT_DEFAULT_Ki 6.79
    #define LULZBOT_DEFAULT_Kd 113.94
#endif /* LULZBOT_Moarstruder */

#if defined(LULZBOT_AO_Hexagon)
    // LulzBot AO-Hexagon (24v)
    #define LULZBOT_DEFAULT_Kp 28.79
    #define LULZBOT_DEFAULT_Ki 1.91
    #define LULZBOT_DEFAULT_Kd 108.51
#endif /* LULZBOT_AO_Hexagon */

// default steps per unit for LulzBot TAZ

#if LULZBOT_EXTRUDERS == 1
    #define LULZBOT_DEFAULT_AXIS_STEPS_PER_UNIT   {100.5,100.5,1600,830}
#elif LULZBOT_EXTRUDERS == 2
    #define LULZBOT_DEFAULT_AXIS_STEPS_PER_UNIT   {100.5,100.5,1600,830,830}
#elif LULZBOT_EXTRUDERS == 3
    #define LULZBOT_DEFAULT_AXIS_STEPS_PER_UNIT   {100.5,100.5,1600,830,830,830}
#elif LULZBOT_EXTRUDERS == 4
    #define LULZBOT_DEFAULT_AXIS_STEPS_PER_UNIT   {100.5,100.5,1600,830,830,830,830}
#endif

#endif /* CONFIGURATION_LULZBOT */
