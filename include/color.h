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
    static auto red() -> hsl { return {0, 0.5, 1}; }
    static auto yellow() -> hsl { return {60, 0.5, 1}; }
    static auto green() -> hsl { return {120, 0.5, 1}; }
    static auto cyan() -> hsl { return {180, 0.5, 1}; }
    static auto blue() -> hsl { return {240, 0.5, 1}; }
    static auto magenta() -> hsl { return {300, 0.5, 1}; }

private:

    auto assert_valid() const -> void
    {
        if (s == 0 && h.has_value())
            throw exception {"Defined hue with zero saturation"};
        if (s != 0 && !h.has_value())
            throw exception {"Undefined hue with non-zero saturation"};
        if (h.has_value() && (h.value() < 0 || 360 < h.value()))
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

private:

    auto assert_valid() const -> void
    {
        if (s == 0 && h.has_value())
            throw exception {"Defined hue with zero saturation"};
        if (s != 0 && !h.has_value())
            throw exception {"Undefined hue with non-zero saturation"};
        if (h.has_value() && (h.value() < 0 || 360 < h.value()))
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

private:

    auto assert_valid() -> void
    {
        if (r < 0 || 1 < r)
            throw exception {"Out of range red"};
        if (g < 0 || 1 < g)
            throw exception {"Out of range green"};
        if (b < 0 || 1 < b)
            throw exception {"Out of range blue"};
    }
};

}

#endif
