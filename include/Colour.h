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