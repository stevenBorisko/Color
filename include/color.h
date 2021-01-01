#ifndef COLOR_H
#define COLOR_H

#include <optional>

namespace color {

struct hsl;
struct hsv;
struct rgb;

class exception : std::runtime_error {
public: exception(std::string const& m): std::runtime_error(m) { }
};

/**
 * @brief Hue-saturation-brightness model
 */
struct hsl {

    std::optional<float> h;
    float s, l;

    hsl() = default;
    hsl(std::optional<float> hue, float saturation, float brightness)
        : h {hue} , s {saturation} , l {brightness}
    {
        assert_valid();
    }

    bool operator==(hsl const& rhs) const
    {
        if (h.has_value() && rhs.h.has_value())
        {
            return h == rhs.h && s == rhs.s && l == rhs.l;
        }
        else if (!h.has_value() && !rhs.h.has_value())
        {
            return s == rhs.s && l == rhs.l;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(hsl const& rhs) const { return !(*this == rhs); }

    static auto black() -> hsl { return {std::nullopt, 0, 0}; }
    static auto gray() -> hsl { return {std::nullopt, 0, 0.5}; }
    static auto white() -> hsl { return {std::nullopt, 0, 1}; }
    static auto red() -> hsl { return {0, 1, 0.5}; }
    static auto yellow() -> hsl { return {60, 1, 0.5}; }
    static auto green() -> hsl { return {120, 1, 0.5}; }
    static auto cyan() -> hsl { return {180, 1, 0.5}; }
    static auto blue() -> hsl { return {240, 1, 0.5}; }
    static auto magenta() -> hsl { return {300, 1, 0.5}; }

    auto assert_valid() const -> void
    {
        if (s == 0 && h.has_value())
            throw exception {"Defined hue with zero saturation"};
        if (s != 0 && !h.has_value())
            throw exception {"Undefined hue with non-zero saturation"};
        if (h.has_value() && (h.value() < 0 || 360 <= h.value()))
            throw exception {"Out of range hue"};
        if (s < 0 || 1 < s)
            throw exception {"Out of range saturation"};
        if (l < 0 || 1 < l)
            throw exception {"Out of range brightness"};
    }
};

/**
 * @brief Hue-saturation-value model
 */
struct hsv {

    std::optional<float> h;
    float s, v;

    hsv() = default;
    hsv(std::optional<float> hue, float saturation, float value)
        : h {hue} , s {saturation} , v {value}
    {
        assert_valid();
    }

    bool operator==(hsv const& rhs) const
    {
        if (h.has_value() && rhs.h.has_value())
        {
            return h == rhs.h && s == rhs.s && v == rhs.v;
        }
        else if (!h.has_value() && !rhs.h.has_value())
        {
            return s == rhs.s && v == rhs.v;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(hsv const& rhs) const { return !(*this == rhs); }

    static auto black() -> hsv { return {std::nullopt, 0, 0}; }
    static auto gray() -> hsv { return {std::nullopt, 0, 0.5}; }
    static auto white() -> hsv { return {std::nullopt, 0, 1}; }
    static auto red() -> hsv { return {0, 1, 1}; }
    static auto yellow() -> hsv { return {60, 1, 1}; }
    static auto green() -> hsv { return {120, 1, 1}; }
    static auto cyan() -> hsv { return {180, 1, 1}; }
    static auto blue() -> hsv { return {240, 1, 1}; }
    static auto magenta() -> hsv { return {300, 1, 1}; }

    auto assert_valid() const -> void
    {
        if (s == 0 && h.has_value())
            throw exception {"Defined hue with zero saturation"};
        if (s != 0 && !h.has_value())
            throw exception {"Undefined hue with non-zero saturation"};
        if (h.has_value() && (h.value() < 0 || 360 <= h.value()))
            throw exception {"Out of range hue"};
        if (s < 0 || 1 < s)
            throw exception {"Out of range saturation"};
        if (v < 0 || 1 < v)
            throw exception {"Out of range value"};
    }
};

/**
 * @brief Reg-green-blue model
 */
struct rgb {

    float r, g, b;

    rgb() = default;
    rgb(float red, float green, float blue)
        : r {red} , g {green} , b {blue}
    {
        assert_valid();
    }

    bool operator==(rgb const& rhs) const
    {
        return r == rhs.r && g == rhs.g && b == rhs.b;
    }
    bool operator!=(rgb const& rhs) const { return !(*this == rhs); }

    static auto black() -> rgb { return {0, 0, 0}; }
    static auto gray() -> rgb { return {0.5, 0.5, 0.5}; }
    static auto white() -> rgb { return {1, 1, 1}; }
    static auto red() -> rgb { return {1, 0, 0}; }
    static auto yellow() -> rgb { return {1, 1, 0}; }
    static auto green() -> rgb { return {0, 1, 0}; }
    static auto cyan() -> rgb { return {0, 1, 1}; }
    static auto blue() -> rgb { return {0, 0, 1}; }
    static auto magenta() -> rgb { return {1, 0, 1}; }

    auto assert_valid() const -> void
    {
        if (r < 0 || 1 < r)
            throw exception {"Out of range red"};
        if (g < 0 || 1 < g)
            throw exception {"Out of range green"};
        if (b < 0 || 1 < b)
            throw exception {"Out of range blue"};
    }
};

namespace convert {

static auto to_unit_circle_deg(float const d) -> float
{
    auto ret {d};
    while (ret < 0.0f) ret += 360.0f;
    while (360.0f <= ret) ret -= 360.0f;
    return ret;
}

static auto to_rgb(color::hsl const& hsl) -> color::rgb
{
    hsl.assert_valid();

    if (hsl.s == 0.0)
        return {hsl.l, hsl.l, hsl.l};

    auto const v = (hsl.l <= 0.5f)
        ? (hsl.l * (1.0f + hsl.s))
        : (hsl.l + hsl.s - hsl.l * hsl.s);

    if (v == 0.0)
        return {0.0, 0.0, 0.0};

    auto const min = 2.0f * hsl.l - v;
    auto const sv = (v - min) / v;
    auto const h = hsl.h.value() / 60.0f;
    auto const sextant = static_cast<unsigned int>(std::floor(h));
    auto const fract = h - static_cast<float>(sextant);
    auto const vsf = v * sv * fract;
    auto const mid1 = min + vsf;
    auto const mid2 = v - vsf;

    switch (sextant)
    {
    case 0: return {v, mid1, min};
    case 1: return {mid2, v, min};
    case 2: return {min, v, mid1};
    case 3: return {min, mid2, v};
    case 4: return {mid1, min, v};
    case 5: return {v, min, mid2};
    default: throw exception {"failed to convert hsl to rgb"};
    }
}

static auto to_rgb(color::hsv const& hsv) -> color::rgb
{
    hsv.assert_valid();

    if (hsv.v == 0.0)
        return {0.0, 0.0, 0.0};

    if (hsv.s == 0.0)
        return {hsv.v, hsv.v, hsv.v};

    auto const h = hsv.h.value() / 60.0f;
    auto const sextant = static_cast<unsigned int>(std::floor(h));
    auto const fract = h - static_cast<float>(sextant);
    auto const p = hsv.v * (1.0f - hsv.s);
    auto const q = hsv.v * (1.0f - (hsv.s * fract));
    auto const t = hsv.v * (1.0f - (hsv.s * (1.0f - fract)));

    switch (sextant)
    {
    case 0: return {hsv.v, t, p};
    case 1: return {q, hsv.v, p};
    case 2: return {p, hsv.v, p};
    case 3: return {p, q, hsv.v};
    case 4: return {t, p, hsv.v};
    case 5: return {hsv.v, p, q};
    default: throw exception {"failed to convert hsv to rgb"};
    }
}

static auto to_hsv(color::hsl const& hsl) -> color::hsv
{
    hsl.assert_valid();

    auto const v = hsl.l + hsl.s * std::min(hsl.l, 1.0f - hsl.l);
    return {
        hsl.h,
        (v == 0.0f) ? 0.0f : (2.0f * (1.0f - (hsl.l / v))),
        v};
}

static auto to_hsv(color::rgb const& rgb) -> color::hsv
{
    rgb.assert_valid();

    auto const max = std::max(rgb.r, std::max(rgb.g, rgb.b));
    auto const min = std::min(rgb.r, std::min(rgb.g, rgb.b));
    auto const d = max - min;

    auto const s = (max == 0.0f) ? 0.0f : (d / max);

    if (s == 0.0f)
        return {std::nullopt, s, max};
    if (rgb.r == max)
        return {to_unit_circle_deg(60.0f * (rgb.g - rgb.b) / d), s, max};
    if (rgb.g == max)
        return {to_unit_circle_deg(60.0f * (2.0f + (rgb.b - rgb.r) / d)), s, max};
    if (rgb.b == max)
        return {to_unit_circle_deg(60.0f * (4.0f + (rgb.r - rgb.g) / d)), s, max};

    throw exception {"failed to convert rgb to hsv"};
}

static auto to_hsl(color::hsv const& hsv) -> color::hsl
{
    hsv.assert_valid();

    auto const l = hsv.v * (1 - (hsv.s / 2.0f));
    return {
        hsv.h,
        (l == 0 || l == 1) ? 0.0f : ((hsv.v - l) / std::min(l, 1.0f - l)),
        l};
}

static auto to_hsl(color::rgb const& rgb) -> color::hsl
{
    rgb.assert_valid();

    auto const max = std::max(rgb.r, std::max(rgb.g, rgb.b));
    auto const min = std::min(rgb.r, std::min(rgb.g, rgb.b));
    auto const a = max + min;

    auto const l = a / 2.0f;
    auto const d = max - min;

    if (d == 0.0f)
        return {std::nullopt, 0.0f, l};

    auto const s = d / ((l <= 0.5f) ? a : (2.0f - a));

    if (rgb.r == max)
        return {to_unit_circle_deg(60.0f * (rgb.g - rgb.b) / d), s, l};
    if (rgb.g == max)
        return {to_unit_circle_deg(60.0f * (2.0f + (rgb.b - rgb.r) / d)), s, l};
    if (rgb.b == max)
        return {to_unit_circle_deg(60.0f * (4.0f + (rgb.r - rgb.g) / d)), s, l};

    throw exception {"failed to convert rgb to hsv"};
}

}

}

#endif
