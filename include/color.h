#ifndef COLOR_H
#define COLOR_H

namespace color {

struct hsl;
struct hsv;
struct rgb;

/**
 * @brief Hue-saturation-brightness model
 */
struct hsl {

    float h, s, l;

    hsl()
        : h {-1} , s {} , l {}
    { }
    hsl(float hue, float saturation, float brightness)
        : h {hue} , s {saturation} , l {brightness}
    { }

    bool operator==(hsl const& rhs) const
    {
        return h == rhs.h && s == rhs.s && l == rhs.l;
    }
    bool operator!=(hsl const& rhs) const { return !(*this == rhs); }

    static auto black() -> hsl { return {-1, 0, 0}; }
    static auto gray() -> hsl { return {-1, 0, 0.5}; }
    static auto white() -> hsl { return {-1, 0, 1}; }
    static auto red() -> hsl { return {0, 0.5, 1}; }
    static auto yellow() -> hsl { return {60, 0.5, 1}; }
    static auto green() -> hsl { return {120, 0.5, 1}; }
    static auto cyan() -> hsl { return {180, 0.5, 1}; }
    static auto blue() -> hsl { return {240, 0.5, 1}; }
    static auto magenta() -> hsl { return {300, 0.5, 1}; }
};

/**
 * @brief Hue-saturation-value model
 */
struct hsv {

    float h, s, v;

    hsv()
        : h {-1} , s {} , v {}
    { }
    hsv(float hue, float saturation, float value)
        : h {hue} , s {saturation} , v {value}
    { }

    bool operator==(hsv const& rhs) const
    {
        return h == rhs.h && s == rhs.s && v == rhs.v;
    }
    bool operator!=(hsv const& rhs) const { return !(*this == rhs); }

    static auto black() -> hsv { return {-1, 0, 0}; }
    static auto gray() -> hsv { return {-1, 0, 0.5}; }
    static auto white() -> hsv { return {-1, 0, 1}; }
    static auto red() -> hsv { return {0, 1, 1}; }
    static auto yellow() -> hsv { return {60, 1, 1}; }
    static auto green() -> hsv { return {120, 1, 1}; }
    static auto cyan() -> hsv { return {180, 1, 1}; }
    static auto blue() -> hsv { return {240, 1, 1}; }
    static auto magenta() -> hsv { return {300, 1, 1}; }
};

/**
 * @brief Reg-green-blue model
 */
struct rgb {

    float r, g, b;

    rgb() = default;
    rgb(float red, float green, float blue)
        : r {red} , g {green} , b {blue}
    { }

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
};

}

#endif
