#include <Color.hpp>

//---------------------------------------------------------------------------//
// ColorHSL
//---------------------------------------------------------------------------//

// --- Standard Functions --- //
ColorHSL::ColorHSL(): h(-1), s(0), l(0) { }

ColorHSL::ColorHSL(const float& _h, const float& _s, const float& _l):
	h(_h), s(_s), l(_l)
{ }

ColorHSL::ColorHSL(const Color& color) {
	*this = ColorHSL::getConst(color);
}

ColorHSL::ColorHSL(const ColorHSL& rhs):
	h(rhs.h), s(rhs.s), l(rhs.l)
{ }

ColorHSL::~ColorHSL() { }

ColorHSL& ColorHSL::operator=(const ColorHSL& rhs) {
	this->h = rhs.h;
	this->s = rhs.s;
	this->l = rhs.l;
	return *this;
}

// --- Conversions --- //
ColorHSV ColorHSL::toHSV() const {
	return this->toRGB().toHSV();
}

ColorRGB ColorHSL::toRGB() const {
	float H = this->h;
	float S = this->s;
	float L = this->l;
	float v, min, sv, fract, vsf, mid1, mid2;
	int sextant;

	ColorRGB ret = {0, 0, 0};

	const bool H_NDEF = (H < 0.0 || 360.0 < H);

	if(S == 0.0) {
		if(H_NDEF) {
			ret = {L, L, L};
			return ret;
		}
		else {
			std::cerr << "Invalid HSL to convert to RGB: "
				<< (*this) <<"\n";
			return ret;
		}
	}
	v = (L <= 0.5) ? (L * (1 + S)) : (L + S - L * S);
	if(v == 0.0) {
		ret = {0, 0, 0};
	}
	else {
		min = 2 * L - v;
		sv = (v - min) / v;
		H = (H == 360.0) ? (0.0) : (H / 60.0);
		sextant = floor(H);
		fract = H - (float)sextant;
		vsf = v * sv * fract;
		mid1 = min + vsf;
		mid2 = v - vsf;
		switch(sextant) {
		case 0: ret = {v, mid1, min}; break;
		case 1: ret = {mid2, v, min}; break;
		case 2: ret = {min, v, mid1}; break;
		case 3: ret = {min, mid2, v}; break;
		case 4: ret = {mid1, min, v}; break;
		case 5: ret = {v, min, mid2}; break;
		default:
			std::cerr << "Invalid HSL to convert to RGB: "
				<< (*this) <<"\n";
		}
	}
	return ret;
}

ColorRGBc ColorHSL::toRGBc() const {
	return this->toRGB().toRGBc();
}

// --- Other --- //
ColorHSL ColorHSL::getConst(const Color& color) {
	return ColorHSV::getConst(color).toHSL();
}

std::ostream& operator<<(std::ostream& os, const ColorHSL& c) {
	return os << "{" << c.h << "," << c.s << "," << c.l << "}";
}

// --- Other --- //
ColorHSL ColorHSL::illuminate(
	const ColorHSL& color,
	const float& illuCoef
) {
	ColorHSL ret(color);
	ret.l = std::min(ret.l * illuCoef, (float)1.0);
	return ret;
}
