#include <gmock/gmock.h>

#include <color.h>

TEST (HSLConstructorDefault, DefaultsToBlack)
{
    auto const color = color::hsl {};
    ASSERT_FALSE (color.h.has_value());
    ASSERT_EQ (color.s, 0);
    ASSERT_EQ (color.l, 0);
}

TEST (HSLConstructorValues, InitializesFromList)
{
    auto const color = color::hsl {0.25, 0.50, 0.75};
    ASSERT_EQ (color.h, 0.25);
    ASSERT_EQ (color.s, 0.50);
    ASSERT_EQ (color.l, 0.75);
}

TEST (HSLConstructorValues, ThrowsOnDefinedHueWithZeroSaturation)
{
    ASSERT_THROW ((color::hsl {0, 0, 0}), color::exception);
}

TEST (HSLConstructorValues, ThrowsOnUndefinedHueWithNonZeroSaturation)
{
    ASSERT_THROW ((color::hsl {std::nullopt, 1, 0}), color::exception);
}

TEST (HSLConstructorValues, ThrowsOnOutOfRangeInput)
{
    ASSERT_THROW ((color::hsl {-1, 1, 0}), color::exception);
    ASSERT_THROW ((color::hsl {361, 1, 0}), color::exception);
    ASSERT_THROW ((color::hsl {0, -1, 0}), color::exception);
    ASSERT_THROW ((color::hsl {0, 2, 0}), color::exception);
    ASSERT_THROW ((color::hsl {0, 1, -1}), color::exception);
    ASSERT_THROW ((color::hsl {0, 1, 2}), color::exception);
}

TEST (HSLOperatorEquals, TrueWhenAllSameWithHue)
{
    auto const color_l = color::hsl {0.25, 0.50, 0.75};
    auto const color_r = color::hsl {0.25, 0.50, 0.75};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLOperatorEquals, TrueWhenAllSameWithoutHue)
{
    auto const color_l = color::hsl {std::nullopt, 0, 0.75};
    auto const color_r = color::hsl {std::nullopt, 0, 0.75};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLOperatorEquals, FalseWhenHueDifferent)
{
    auto const color_l = color::hsl {0.25, 0.50, 0.75};
    auto const color_r = color::hsl {0.50, 0.50, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (HSLOperatorEquals, FalseWhenSaturationDifferent)
{
    auto const color_l = color::hsl {0.25, 0.50, 0.75};
    auto const color_r = color::hsl {0.25, 0.25, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (HSLOperatorEquals, FalseWhenBrightnessDifferent)
{
    auto const color_l = color::hsl {0.25, 0.50, 0.75};
    auto const color_r = color::hsl {0.25, 0.50, 0.50};
    ASSERT_NE (color_l, color_r);
}

TEST (HSLBlack, InitializesToBlack)
{
    auto const color_l = color::hsl::black();
    auto const color_r = color::hsl {std::nullopt, 0, 0};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLGray, InitializesToGray)
{
    auto const color_l = color::hsl::gray();
    auto const color_r = color::hsl {std::nullopt, 0, 0.5};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLWhite, InitializesToWhite)
{
    auto const color_l = color::hsl::white();
    auto const color_r = color::hsl {std::nullopt, 0, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLRed, InitializesToRed)
{
    auto const color_l = color::hsl::red();
    auto const color_r = color::hsl {0, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLYellow, InitializesToYellow)
{
    auto const color_l = color::hsl::yellow();
    auto const color_r = color::hsl {60, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLGreen, InitializesToGreen)
{
    auto const color_l = color::hsl::green();
    auto const color_r = color::hsl {120, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLCyan, InitializesToCyan)
{
    auto const color_l = color::hsl::cyan();
    auto const color_r = color::hsl {180, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLBlue, InitializesToBlue)
{
    auto const color_l = color::hsl::blue();
    auto const color_r = color::hsl {240, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLMagenta, InitializesToMagenta)
{
    auto const color_l = color::hsl::magenta();
    auto const color_r = color::hsl {300, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}
