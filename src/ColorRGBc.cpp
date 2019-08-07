#include <Color.hpp>

//---------------------------------------------------------------------------//
// ColorRGBc
//---------------------------------------------------------------------------//

// --- Standard Functions --- //
ColorRGBc::ColorRGBc(): r(0), g(0), b(0) { }

ColorRGBc::ColorRGBc(
	const unsigned char& _r,
	const unsigned char& _g,
	const unsigned char& _b
):
	r(_r), g(_g), b(_b)
{ }

ColorRGBc::ColorRGBc(const Color& color) {
	*this = ColorRGBc::getConst(color);
}

ColorRGBc::ColorRGBc(const ColorRGBc& rhs):
	r(rhs.r), g(rhs.g), b(rhs.b)
{ }

ColorRGBc::~ColorRGBc() { }

ColorRGBc& ColorRGBc::operator=(const ColorRGBc& rhs) {
	this->r = rhs.r;
	this->g = rhs.g;
	this->b = rhs.b;
	return *this;
}

// --- Conversions --- //
ColorHSV ColorRGBc::toHSV() const {
	return this->toRGB().toHSV();
}

ColorHSL ColorRGBc::toHSL() const {
	return this->toRGB().toHSL();
}

ColorRGB ColorRGBc::toRGB() const {
	ColorRGB ret = {
		(float)this->r / (float)225,
		(float)this->g / (float)225,
		(float)this->b / (float)225
	};
	return ret;
}

// --- Other --- //
ColorRGBc ColorRGBc::getConst(const Color& color) {
	return ColorHSV::getConst(color).toRGBc();
}

void ColorRGBc::print(std::ostream& os) const {
	os << this->r << this->g << this->b;
}

std::ostream& operator<<(std::ostream& os, const ColorRGBc& c) {
	return os << "{" << (int)c.r << "," << (int)c.g << "," << (int)c.b << "}";
}
