#include <gmock/gmock.h>

#include <color.h>

TEST (RGBConstructorDefault, DefaultsToBlack)
{
    auto const color = color::rgb {};
    ASSERT_EQ (color.r, 0);
    ASSERT_EQ (color.g, 0);
    ASSERT_EQ (color.b, 0);
}

TEST (RGBConstructorValues, InitializesFromList)
{
    auto const color = color::rgb {0.25, 0.50, 0.75};
    ASSERT_EQ (color.r, 0.25);
    ASSERT_EQ (color.g, 0.50);
    ASSERT_EQ (color.b, 0.75);
}

TEST (RGBOperatorEquals, TrueWhenAllSame)
{
    auto const color_l = color::rgb {0.25, 0.50, 0.75};
    auto const color_r = color::rgb {0.25, 0.50, 0.75};
    ASSERT_EQ (color_l, color_r);
}

TEST (RGBOperatorEquals, FalseWhenRedDifferent)
{
    auto const color_l = color::rgb {0.25, 0.50, 0.75};
    auto const color_r = color::rgb {0, 0.50, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (RGBOperatorEquals, FalseWhenGreenDifferent)
{
    auto const color_l = color::rgb {0.25, 0.50, 0.75};
    auto const color_r = color::rgb {0.25, 0, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (RGBOperatorEquals, FalseWhenBlueDifferent)
{
    auto const color_l = color::rgb {0.25, 0.50, 0.75};
    auto const color_r = color::rgb {0.25, 0.50, 0};
    ASSERT_NE (color_l, color_r);
}

TEST (RGBBlack, InitializesCorrectly)
{
    auto const color_l = color::rgb::black();
    auto const color_r = color::rgb {0, 0, 0};
    ASSERT_EQ (color_l, color_r);
}

TEST (RGBGray, InitializesCorrectly)
{
    auto const color_l = color::rgb::gray();
    auto const color_r = color::rgb {0.5, 0.5, 0.5};
    ASSERT_EQ (color_l, color_r);
}

TEST (RGBWhite, InitializesCorrectly)
{
    auto const color_l = color::rgb::white();
    auto const color_r = color::rgb {1, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (RGBRed, InitializesCorrectly)
{
    auto const color_l = color::rgb::red();
    auto const color_r = color::rgb {1, 0, 0};
    ASSERT_EQ (color_l, color_r);
}

TEST (RGBYellow, InitializesCorrectly)
{
    auto const color_l = color::rgb::yellow();
    auto const color_r = color::rgb {1, 1, 0};
    ASSERT_EQ (color_l, color_r);
}

TEST (RGBGreen, InitializesCorrectly)
{
    auto const color_l = color::rgb::green();
    auto const color_r = color::rgb {0, 1, 0};
    ASSERT_EQ (color_l, color_r);
}

TEST (RGBCyan, InitializesCorrectly)
{
    auto const color_l = color::rgb::cyan();
    auto const color_r = color::rgb {0, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (RGBBlue, InitializesCorrectly)
{
    auto const color_l = color::rgb::blue();
    auto const color_r = color::rgb {0, 0, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (RGBMagenta, InitializesCorrectly)
{
    auto const color_l = color::rgb::magenta();
    auto const color_r = color::rgb {1, 0, 1};
    ASSERT_EQ (color_l, color_r);
}
