#include <gmock/gmock.h>

#include <color.h>

TEST (ConvertHSLToHSV, BlackConvertsToBlack)
{
    ASSERT_EQ (color::convert::to_hsv(color::hsl::black()), color::hsv::black());
}

TEST (ConvertHSLToHSV, GrayConvertsToGray)
{
    ASSERT_EQ (color::convert::to_hsv(color::hsl::gray()), color::hsv::gray());
}

TEST (ConvertHSLToHSV, WhiteConvertsToWhite)
{
    ASSERT_EQ (color::convert::to_hsv(color::hsl::white()), color::hsv::white());
}

TEST (ConvertHSLToHSV, RedConvertsToRed)
{
    ASSERT_EQ (color::convert::to_hsv(color::hsl::red()), color::hsv::red());
}

TEST (ConvertHSLToHSV, YellowConvertsToYellow)
{
    ASSERT_EQ (color::convert::to_hsv(color::hsl::yellow()), color::hsv::yellow());
}

TEST (ConvertHSLToHSV, GreenConvertsToGreen)
{
    ASSERT_EQ (color::convert::to_hsv(color::hsl::green()), color::hsv::green());
}

TEST (ConvertHSLToHSV, CyanConvertsToCyan)
{
    ASSERT_EQ (color::convert::to_hsv(color::hsl::cyan()), color::hsv::cyan());
}

TEST (ConvertHSLToHSV, BlueConvertsToBlue)
{
    ASSERT_EQ (color::convert::to_hsv(color::hsl::blue()), color::hsv::blue());
}

TEST (ConvertHSLToHSV, MagentaConvertsToMagenta)
{
    ASSERT_EQ (color::convert::to_hsv(color::hsl::magenta()), color::hsv::magenta());
}

TEST (ConvertRGBToHSV, BlackConvertsToBlack)
{
    ASSERT_EQ (color::convert::to_hsv(color::rgb::black()), color::hsv::black());
}

TEST (ConvertRGBToHSV, GrayConvertsToGray)
{
    ASSERT_EQ (color::convert::to_hsv(color::rgb::gray()), color::hsv::gray());
}

TEST (ConvertRGBToHSV, WhiteConvertsToWhite)
{
    ASSERT_EQ (color::convert::to_hsv(color::rgb::white()), color::hsv::white());
}

TEST (ConvertRGBToHSV, RedConvertsToRed)
{
    ASSERT_EQ (color::convert::to_hsv(color::rgb::red()), color::hsv::red());
}

TEST (ConvertRGBToHSV, YellowConvertsToYellow)
{
    ASSERT_EQ (color::convert::to_hsv(color::rgb::yellow()), color::hsv::yellow());
}

TEST (ConvertRGBToHSV, GreenConvertsToGreen)
{
    ASSERT_EQ (color::convert::to_hsv(color::rgb::green()), color::hsv::green());
}

TEST (ConvertRGBToHSV, CyanConvertsToCyan)
{
    ASSERT_EQ (color::convert::to_hsv(color::rgb::cyan()), color::hsv::cyan());
}

TEST (ConvertRGBToHSV, BlueConvertsToBlue)
{
    ASSERT_EQ (color::convert::to_hsv(color::rgb::blue()), color::hsv::blue());
}

TEST (ConvertRGBToHSV, MagentaConvertsToMagenta)
{
    ASSERT_EQ (color::convert::to_hsv(color::rgb::magenta()), color::hsv::magenta());
}
