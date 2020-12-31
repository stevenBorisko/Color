#include <gmock/gmock.h>

#include <color.h>

TEST (HSLConstructorDefault, DefaultsToBlack)
{
    auto const color = color::hsl {};
    ASSERT_EQ (color.h, -1);
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

TEST (HSLOperatorEquals, TrueWhenAllSame)
{
    auto const color_l = color::hsl {0.25, 0.50, 0.75};
    auto const color_r = color::hsl {0.25, 0.50, 0.75};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLOperatorEquals, FalseWhenHueDifferent)
{
    auto const color_l = color::hsl {0.25, 0.50, 0.75};
    auto const color_r = color::hsl {0, 0.50, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (HSLOperatorEquals, FalseWhenSaturationDifferent)
{
    auto const color_l = color::hsl {0.25, 0.50, 0.75};
    auto const color_r = color::hsl {0.25, 0, 0.75};
    ASSERT_NE (color_l, color_r);
}

TEST (HSLOperatorEquals, FalseWhenValueDifferent)
{
    auto const color_l = color::hsl {0.25, 0.50, 0.75};
    auto const color_r = color::hsl {0.25, 0.50, 0};
    ASSERT_NE (color_l, color_r);
}

TEST (HSLBlack, InitializesCorrectly)
{
    auto const color_l = color::hsl::black();
    auto const color_r = color::hsl {-1, 0, 0};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLGray, InitializesCorrectly)
{
    auto const color_l = color::hsl::gray();
    auto const color_r = color::hsl {-1, 0, 0.5};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLWhite, InitializesCorrectly)
{
    auto const color_l = color::hsl::white();
    auto const color_r = color::hsl {-1, 0, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLRed, InitializesCorrectly)
{
    auto const color_l = color::hsl::red();
    auto const color_r = color::hsl {0, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLYellow, InitializesCorrectly)
{
    auto const color_l = color::hsl::yellow();
    auto const color_r = color::hsl {60, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLGreen, InitializesCorrectly)
{
    auto const color_l = color::hsl::green();
    auto const color_r = color::hsl {120, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLCyan, InitializesCorrectly)
{
    auto const color_l = color::hsl::cyan();
    auto const color_r = color::hsl {180, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLBlue, InitializesCorrectly)
{
    auto const color_l = color::hsl::blue();
    auto const color_r = color::hsl {240, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}

TEST (HSLMagenta, InitializesCorrectly)
{
    auto const color_l = color::hsl::magenta();
    auto const color_r = color::hsl {300, 0.5, 1};
    ASSERT_EQ (color_l, color_r);
}
