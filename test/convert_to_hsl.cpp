#include <gmock/gmock.h>

#include <color.h>

TEST (ConvertHSVToHSL, BlackConvertsToBlack)
{
    ASSERT_EQ (color::convert::to_hsl(color::hsv::black()), color::hsl::black());
}

TEST (ConvertHSVToHSL, GrayConvertsToGray)
{
    ASSERT_EQ (color::convert::to_hsl(color::hsv::gray()), color::hsl::gray());
}

TEST (ConvertHSVToHSL, WhiteConvertsToWhite)
{
    ASSERT_EQ (color::convert::to_hsl(color::hsv::white()), color::hsl::white());
}

TEST (ConvertHSVToHSL, RedConvertsToRed)
{
    ASSERT_EQ (color::convert::to_hsl(color::hsv::red()), color::hsl::red());
}

TEST (ConvertHSVToHSL, YellowConvertsToYellow)
{
    ASSERT_EQ (color::convert::to_hsl(color::hsv::yellow()), color::hsl::yellow());
}

TEST (ConvertHSVToHSL, GreenConvertsToGreen)
{
    ASSERT_EQ (color::convert::to_hsl(color::hsv::green()), color::hsl::green());
}

TEST (ConvertHSVToHSL, CyanConvertsToCyan)
{
    ASSERT_EQ (color::convert::to_hsl(color::hsv::cyan()), color::hsl::cyan());
}

TEST (ConvertHSVToHSL, BlueConvertsToBlue)
{
    ASSERT_EQ (color::convert::to_hsl(color::hsv::blue()), color::hsl::blue());
}

TEST (ConvertHSVToHSL, MagentaConvertsToMagenta)
{
    ASSERT_EQ (color::convert::to_hsl(color::hsv::magenta()), color::hsl::magenta());
}

TEST (ConvertRGBToHSL, BlackConvertsToBlack)
{
    ASSERT_EQ (color::convert::to_hsl(color::rgb::black()), color::hsl::black());
}

TEST (ConvertRGBToHSL, GrayConvertsToGray)
{
    ASSERT_EQ (color::convert::to_hsl(color::rgb::gray()), color::hsl::gray());
}

TEST (ConvertRGBToHSL, WhiteConvertsToWhite)
{
    ASSERT_EQ (color::convert::to_hsl(color::rgb::white()), color::hsl::white());
}

TEST (ConvertRGBToHSL, RedConvertsToRed)
{
    ASSERT_EQ (color::convert::to_hsl(color::rgb::red()), color::hsl::red());
}

TEST (ConvertRGBToHSL, YellowConvertsToYellow)
{
    ASSERT_EQ (color::convert::to_hsl(color::rgb::yellow()), color::hsl::yellow());
}

TEST (ConvertRGBToHSL, GreenConvertsToGreen)
{
    ASSERT_EQ (color::convert::to_hsl(color::rgb::green()), color::hsl::green());
}

TEST (ConvertRGBToHSL, CyanConvertsToCyan)
{
    ASSERT_EQ (color::convert::to_hsl(color::rgb::cyan()), color::hsl::cyan());
}

TEST (ConvertRGBToHSL, BlueConvertsToBlue)
{
    ASSERT_EQ (color::convert::to_hsl(color::rgb::blue()), color::hsl::blue());
}

TEST (ConvertRGBToHSL, MagentaConvertsToMagenta)
{
    ASSERT_EQ (color::convert::to_hsl(color::rgb::magenta()), color::hsl::magenta());
}
