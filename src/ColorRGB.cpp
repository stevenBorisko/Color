#include <Color.hpp>

//---------------------------------------------------------------------------//
// ColorRGB
//---------------------------------------------------------------------------//

// --- Standard Functions --- //
ColorRGB::ColorRGB(): r(0), g(0), b(0) { }

ColorRGB::ColorRGB(const float& _r, const float& _g, const float& _b):
	r(_r), g(_g), b(_b)
{ }

ColorRGB::ColorRGB(const Color& color) {
	*this = ColorRGB::getConst(color);
}

ColorRGB::ColorRGB(const ColorRGB& rhs):
	r(rhs.r), g(rhs.g), b(rhs.b)
{ }

ColorRGB::~ColorRGB() { }

ColorRGB& ColorRGB::operator=(const ColorRGB& rhs) {
	this->r = rhs.r;
	this->g = rhs.g;
	this->b = rhs.b;
	return *this;
}

// --- Conversions --- //
ColorHSV ColorRGB::toHSV() const {
	float max, min, d;
	ColorHSV ret = {0, 0, 0};

	max = std::max(this->r, std::max(this->g, this->b));
	min = std::min(this->r, std::min(this->g, this->b));
	d = max - min;

	ret.v = max;
	ret.s = (max == 0.0) ? (0.0) : d / max;
	if(ret.s == 0.0) {
		ret.h = -1.0;
	}
	else {
		if(this->r == max)
			ret.h = (this->g - this->b) / d;
		else if(this->g == max)
			ret.h = 2.0 + (this->b - this->r) / d;
		else if(this->b == max)
			ret.h = 4.0 + (this->r - this->g) / d;
		ret.h *= 60;
		if(ret.h < 0.0) ret.h += 360.0;
	}

	return ret;
}

ColorHSL ColorRGB::toHSL() const {
	float max, min, d, a;
	ColorHSL ret = {0, 0, 0};

	max = std::max(this->r, std::max(this->g, this->b));
	min = std::min(this->r, std::min(this->g, this->b));

	a = max + min;

	ret.l = a / 2;
	if(max == min) {
		ret.s = 0.0;
		ret.h = -1.0;
	}
	else {
		d = max - min;

		ret.s = d / ((ret.l <= 0.5) ? a : (2 - a));

		if(this->r == max)
			ret.h = (this->g - this->b) / d;
		else if(this->g == max)
			ret.h = 2.0 + (this->b - this->r) / d;
		else if(this->b == max)
			ret.h = 4.0 + (this->r - this->g) / d;
		ret.h *= 60;
		if(ret.h < 0.0) ret.h += 360.0;
	}

	return ret;
}

ColorRGBc ColorRGB::toRGBc() const {
	ColorRGBc ret = {
		(unsigned char)(this->r * (float)255),
		(unsigned char)(this->g * (float)255),
		(unsigned char)(this->b * (float)255)
	};
	return ret;
}

// --- Combining --- //
ColorRGB ColorRGB::combine(
	const float* weights,
	const ColorRGB* colors,
	const size_t& colorCount
) {
	float newR = 0.0;
	float newG = 0.0;
	float newB = 0.0;
	register float tempW = 0.0;
	for(size_t i = 0;i < colorCount;++i) {
		tempW = weights[i];
		newR += tempW * colors[i].r;
		newG += tempW * colors[i].g;
		newB += tempW * colors[i].b;
	}
	return ColorRGB(newR, newG, newB);
}

// --- Other --- //
ColorRGB ColorRGB::getConst(const Color& color) {
	return ColorHSV::getConst(color).toRGB();
}

std::ostream& operator<<(std::ostream& os, const ColorRGB& c) {
	return os << "{" << c.r << "," << c.g << "," << c.b << "}";
}
