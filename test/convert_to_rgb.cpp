#include <gmock/gmock.h>

#include <color.h>

TEST (ConvertHSLToRGB, BlackConvertsToBlack)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsl::black()), color::rgb::black());
}

TEST (ConvertHSLToRGB, GrayConvertsToGray)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsl::gray()), color::rgb::gray());
}

TEST (ConvertHSLToRGB, WhiteConvertsToWhite)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsl::white()), color::rgb::white());
}

TEST (ConvertHSLToRGB, RedConvertsToRed)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsl::red()), color::rgb::red());
}

TEST (ConvertHSLToRGB, YellowConvertsToYellow)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsl::yellow()), color::rgb::yellow());
}

TEST (ConvertHSLToRGB, GreenConvertsToGreen)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsl::green()), color::rgb::green());
}

TEST (ConvertHSLToRGB, CyanConvertsToCyan)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsl::cyan()), color::rgb::cyan());
}

TEST (ConvertHSLToRGB, BlueConvertsToBlue)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsl::blue()), color::rgb::blue());
}

TEST (ConvertHSLToRGB, MagentaConvertsToMagenta)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsl::magenta()), color::rgb::magenta());
}

TEST (ConvertHSVToRGB, BlackConvertsToBlack)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsv::black()), color::rgb::black());
}

TEST (ConvertHSVToRGB, GrayConvertsToGray)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsv::gray()), color::rgb::gray());
}

TEST (ConvertHSVToRGB, WhiteConvertsToWhite)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsv::white()), color::rgb::white());
}

TEST (ConvertHSVToRGB, RedConvertsToRed)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsv::red()), color::rgb::red());
}

TEST (ConvertHSVToRGB, YellowConvertsToYellow)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsv::yellow()), color::rgb::yellow());
}

TEST (ConvertHSVToRGB, GreenConvertsToGreen)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsv::green()), color::rgb::green());
}

TEST (ConvertHSVToRGB, CyanConvertsToCyan)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsv::cyan()), color::rgb::cyan());
}

TEST (ConvertHSVToRGB, BlueConvertsToBlue)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsv::blue()), color::rgb::blue());
}

TEST (ConvertHSVToRGB, MagentaConvertsToMagenta)
{
    ASSERT_EQ (color::convert::to_rgb(color::hsv::magenta()), color::rgb::magenta());
}
