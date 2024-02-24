#pragma once
#include <stdint.h>
#include <vector>

namespace esphome
{
    namespace philips_coffee_machine
    {
#if defined(PHILIPS_EP2220) || defined(PHILIPS_EP2235)
#define USE_DEFAULT_PHILIPS_COMMAND_SET
#elif defined(PHILIPS_EP3243)
        // Note that the EP3243 and EP3246 are identical except for cosmetic differences
        const uint8_t message_header[2] = {0xD5, 0x55};
        const uint8_t led_off = 0x00;
        const uint8_t led_half = 0x03;
        const uint8_t led_on = 0x07;
        const uint8_t led_second = 0x38;
        const uint8_t led_third = 0x3F;

        const std::vector<uint8_t> command_pre_power_on =
            {0xD5, 0x55, 0x00, 0x01, 0x04, 0x02, 0x4, 0x00, 0x00, 0x00, 0x2F, 0x0D};
        const std::vector<uint8_t> command_power_with_cleaning =
            {0xD5, 0x55, 0x02, 0x01, 0x04, 0x02, 0x04, 0x00, 0x00, 0x00, 0x1C, 0x17};
        const std::vector<uint8_t> command_power_without_cleaning =
            {0xD5, 0x55, 0x01, 0x01, 0x04, 0x02, 0x04, 0x00, 0x00, 0x00, 0x1B, 0x1C};
        const std::vector<uint8_t> command_power_off =
            {0xD5, 0x55, 0x00, 0x01, 0x04, 0x02, 0x4, 0x00, 0x00, 0x00, 0x2F, 0x0D};
        const std::vector<uint8_t> command_press_play_pause =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x00, 0x00, 0x01, 0x3D, 0x30};
        /// @brief EP3243: Press Coffee Button
        const std::vector<uint8_t> command_press_1 =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x08, 0x00, 0x00, 0x1D, 0x1E};
        /// @brief EP3243: Press Espresso Button
        const std::vector<uint8_t> command_press_2 =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x02, 0x00, 0x00, 0x2D, 0x2F};
        /// @brief EP3243: Press Hot water Button
        const std::vector<uint8_t> command_press_3 =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x00, 0x01, 0x00, 0x39, 0x38};
        /// @brief EP3243: Press Latte Button
        const std::vector<uint8_t> command_press_4 =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x10, 0x00, 0x00, 0x2D, 0x24};
        /// @brief EP3243: Press Americano Button
        const std::vector<uint8_t> command_press_5 =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x20, 0x00, 0x00, 0x04, 0x15};
        /// @brief EP3243: Press cappuccino Button
        const std::vector<uint8_t> command_press_6 =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x04, 0x00, 0x00, 0x05, 0x03};
        const std::vector<uint8_t> command_press_bean =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x00, 0x02, 0x00, 0x2D, 0x2D};
        const std::vector<uint8_t> command_press_size =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x00, 0x04, 0x00, 0x04, 0x07};
        const std::vector<uint8_t> command_press_milk =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x00, 0x08, 0x00, 0x1F, 0x16};
        const std::vector<uint8_t> command_press_aqua_clean =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x00, 0x10, 0x00, 0x29, 0x34};
        const std::vector<uint8_t> command_press_calc_clean =
            {0xD5, 0x55, 0x00, 0x01, 0x03, 0x00, 0x0E, 0x00, 0x20, 0x00, 0x0C, 0x35};
#else
#define USE_DEFAULT_PHILIPS_COMMAND_SET
#endif

#ifdef USE_DEFAULT_PHILIPS_COMMAND_SET
        const uint8_t message_header[2] = {0xD5, 0x55};
        const uint8_t led_off = 0x00;
        const uint8_t led_half = 0x03;
        const uint8_t led_on = 0x07;
        const uint8_t led_second = 0x38;
        const uint8_t led_third = 0x3F;

        const std::vector<uint8_t> command_pre_power_on =
            {0xD5, 0x55, 0x0A, 0x01, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0E, 0x12};
        const std::vector<uint8_t> command_power_with_cleaning =
            {0xD5, 0x55, 0x02, 0x01, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x38, 0x15};
        const std::vector<uint8_t> command_power_without_cleaning =
            {0xD5, 0x55, 0x01, 0x01, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x25, 0x27};
        const std::vector<uint8_t> command_power_off =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x01, 0x00, 0x00, 0x1D, 0x3B};
        const std::vector<uint8_t> command_press_play_pause =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x00, 0x00, 0x01, 0x19, 0x32};
        /// @brief EP2220: Press Coffee Button
        const std::vector<uint8_t> command_press_1 =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x08, 0x00, 0x00, 0x39, 0x1C};
        /// @brief EP2220: Press Espresso Button
        const std::vector<uint8_t> command_press_2 =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x02, 0x00, 0x00, 0x09, 0x2D};
        /// @brief EP2220: Press Hot Water Button
        const std::vector<uint8_t> command_press_3 =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x04, 0x00, 0x00, 0x21, 0x01};
        /// @brief EP2220: Press Steam Button; EP2235 Press Cappuccino Button
        const std::vector<uint8_t> command_press_4 =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x10, 0x00, 0x00, 0x09, 0x26};
        const std::vector<uint8_t> command_press_bean =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x09, 0x2F};
        const std::vector<uint8_t> command_press_size =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x00, 0x04, 0x00, 0x20, 0x05};
        const std::vector<uint8_t> command_press_aqua_clean =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x00, 0x10, 0x00, 0x0D, 0x36};
        const std::vector<uint8_t> command_press_calc_clean =
            {0xD5, 0x55, 0x00, 0x01, 0x02, 0x00, 0x02, 0x00, 0x20, 0x00, 0x28, 0x37};
#endif
    } // namespace philips_coffee_machine
} // namespace esphome
