#include <gmock/gmock.h>

#include <color.h>

TEST (HSVConstructorDefault, DefaultsToBlack)
{
    auto const color = color::hsv {};
    ASSERT_EQ (color.h, -1);
    ASSERT_EQ (color.s, 0);
    ASSERT_EQ (color.v, 0);
}

TEST (HSVConstructorValues, InitializesFromList)
{
    auto const color = color::hsv {0.25, 0.50, 0.75};
    ASSERT_EQ (color.h, 0.25);
    ASSERT_EQ (color.s, 0.50);
    ASSERT_EQ (color.v, 0.75);
}

TEST (HSVOperatorEquals, TrueWhenAllSame)
{
    auto const color_l = color::hsv {0.25, 0.50, 0.75};
    auto const color_r = color::hsv {0.25, 0.50, 0.75};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVOperatorEquals, FalseWhenHueDifferent)
{
    auto const color_l = color::hsv {0.25, 0.50, 0.75};
    auto const color_r = color::hsv {0, 0.50, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (HSVOperatorEquals, FalseWhenSaturationDifferent)
{
    auto const color_l = color::hsv {0.25, 0.50, 0.75};
    auto const color_r = color::hsv {0.25, 0, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (HSVOperatorEquals, FalseWhenValueDifferent)
{
    auto const color_l = color::hsv {0.25, 0.50, 0.75};
    auto const color_r = color::hsv {0.25, 0.50, 0};
    ASSERT_NE (color_l, color_r);
}

TEST (HSVBlack, InitializesCorrectly)
{
    auto const color_l = color::hsv::black();
    auto const color_r = color::hsv {-1, 0, 0};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVGray, InitializesCorrectly)
{
    auto const color_l = color::hsv::gray();
    auto const color_r = color::hsv {-1, 0, 0.5};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVWhite, InitializesCorrectly)
{
    auto const color_l = color::hsv::white();
    auto const color_r = color::hsv {-1, 0, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVRed, InitializesCorrectly)
{
    auto const color_l = color::hsv::red();
    auto const color_r = color::hsv {0, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVYellow, InitializesCorrectly)
{
    auto const color_l = color::hsv::yellow();
    auto const color_r = color::hsv {60, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVGreen, InitializesCorrectly)
{
    auto const color_l = color::hsv::green();
    auto const color_r = color::hsv {120, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVCyan, InitializesCorrectly)
{
    auto const color_l = color::hsv::cyan();
    auto const color_r = color::hsv {180, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVBlue, InitializesCorrectly)
{
    auto const color_l = color::hsv::blue();
    auto const color_r = color::hsv {240, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVMagenta, InitializesCorrectly)
{
    auto const color_l = color::hsv::magenta();
    auto const color_r = color::hsv {300, 1, 1};
    ASSERT_EQ (color_l, color_r);
}
