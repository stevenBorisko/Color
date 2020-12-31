#include <gmock/gmock.h>

#include <color.h>

TEST (HSVConstructorDefault, DefaultsToBlack)
{
    auto const color = color::hsv {};
    ASSERT_FALSE (color.h.has_value());
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

TEST (HSVConstructorValue, ThrowsOnDefinedHueWithZeroSaturation)
{
    ASSERT_THROW ((color::hsl {0, 0, 0}), color::exception);
}

TEST (HSVConstructorValues, ThrowsOnUndefinedHueWithNonZeroSaturation)
{
    ASSERT_THROW ((color::hsv {std::nullopt, 1, 0}), color::exception);
}

TEST (HSVConstructorValues, ThrowsOnOutOfRangeInput)
{
    ASSERT_THROW ((color::hsv {-1, 1, 0}), color::exception);
    ASSERT_THROW ((color::hsv {361, 1, 0}), color::exception);
    ASSERT_THROW ((color::hsv {0, -1, 0}), color::exception);
    ASSERT_THROW ((color::hsv {0, 2, 0}), color::exception);
    ASSERT_THROW ((color::hsv {0, 1, -1}), color::exception);
    ASSERT_THROW ((color::hsv {0, 1, 2}), color::exception);
}

TEST (HSVOperatorEquals, TrueWhenAllSameWithHue)
{
    auto const color_l = color::hsv {0.25, 0.50, 0.75};
    auto const color_r = color::hsv {0.25, 0.50, 0.75};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVOperatorEquals, TrueWhenAllSameWithoutHue)
{
    auto const color_l = color::hsv {std::nullopt, 0, 0.75};
    auto const color_r = color::hsv {std::nullopt, 0, 0.75};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVOperatorEquals, FalseWhenHueDifferent)
{
    auto const color_l = color::hsv {0.25, 0.50, 0.75};
    auto const color_r = color::hsv {0.50, 0.50, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (HSVOperatorEquals, FalseWhenSaturationDifferent)
{
    auto const color_l = color::hsv {0.25, 0.50, 0.75};
    auto const color_r = color::hsv {0.25, 0.25, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (HSVOperatorEquals, FalseWhenValueDifferent)
{
    auto const color_l = color::hsv {0.25, 0.50, 0.75};
    auto const color_r = color::hsv {0.25, 0.50, 0.50};
    ASSERT_NE (color_l, color_r);
}

TEST (HSVBlack, InitializesToBlack)
{
    auto const color_l = color::hsv::black();
    auto const color_r = color::hsv {std::nullopt, 0, 0};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVGray, InitializesToGray)
{
    auto const color_l = color::hsv::gray();
    auto const color_r = color::hsv {std::nullopt, 0, 0.5};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVWhite, InitializesToWhite)
{
    auto const color_l = color::hsv::white();
    auto const color_r = color::hsv {std::nullopt, 0, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVRed, InitializesToRed)
{
    auto const color_l = color::hsv::red();
    auto const color_r = color::hsv {0, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVYellow, InitializesToYellow)
{
    auto const color_l = color::hsv::yellow();
    auto const color_r = color::hsv {60, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVGreen, InitializesToGreen)
{
    auto const color_l = color::hsv::green();
    auto const color_r = color::hsv {120, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVCyan, InitializesToCyan)
{
    auto const color_l = color::hsv::cyan();
    auto const color_r = color::hsv {180, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVBlue, InitializesToBlue)
{
    auto const color_l = color::hsv::blue();
    auto const color_r = color::hsv {240, 1, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSVMagenta, InitializesToMagenta)
{
    auto const color_l = color::hsv::magenta();
    auto const color_r = color::hsv {300, 1, 1};
    ASSERT_EQ (color_l, color_r);
}
