#pragma once

struct Colour {
    int m_red;
    int m_green;
    int m_blue;
};

constexpr Colour COLOUR_BLACK { 0, 0, 0 };
constexpr Colour COLOUR_WHITE { 255, 255, 255 };
constexpr Colour COLOUR_RED { 255, 0, 0 };
constexpr Colour COLOUR_GREEN { 0, 255, 0 };
constexpr Colour COLOUR_BLUE { 0, 0, 255 };
constexpr Colour COLOUR_YELLOW { 255, 255, 0 };

constexpr Colour COLOUR_SUN { 255, 236, 179 };
constexpr Colour COLOUR_MERCURY { 169, 165, 158 };
constexpr Colour COLOUR_VENUS { 221, 212, 187 };
constexpr Colour COLOUR_EARTH { 100, 149, 237 };
constexpr Colour COLOUR_MOON { 190, 190, 180 };
constexpr Colour COLOUR_MARS { 193, 105, 73 };
constexpr Colour COLOUR_JUPITER { 216, 189, 162 };
constexpr Colour COLOUR_SATURN { 229, 205, 156 };
constexpr Colour COLOUR_URANUS { 175, 238, 238 };
constexpr Colour COLOUR_NEPTUNE { 72, 61, 139 };