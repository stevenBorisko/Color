#include <Color.hpp>

//---------------------------------------------------------------------------//
// ColorHSV
//---------------------------------------------------------------------------//

// --- Standard Functions --- //
ColorHSV::ColorHSV(): h(-1), s(0), v(0) { }

ColorHSV::ColorHSV(const float& _h, const float& _s, const float& _v):
	h(_h), s(_s), v(_v)
{ }

ColorHSV::ColorHSV(const Color& color) {
	*this = ColorHSV::getConst(color);
}

ColorHSV::ColorHSV(const ColorHSV& rhs):
	h(rhs.h), s(rhs.s), v(rhs.v)
{ }

ColorHSV::~ColorHSV() { }

ColorHSV& ColorHSV::operator=(const ColorHSV& rhs) {
	this->h = rhs.h;
	this->s = rhs.s;
	this->v = rhs.v;
	return *this;
}

// --- Conversions --- //
ColorHSL ColorHSV::toHSL() const {
	return this->toRGB().toHSL();
}

ColorRGB ColorHSV::toRGB() const {
	float H = this->h;
	float S = this->s;
	float V = this->v;
	float fract, p, q, t;
	int sextant;
	ColorRGB ret = {0, 0, 0};

	if(this->v == 0.0) return ret;

	const bool H_NDEF = (H < 0.0 || 360.0 < H);

	if(this->s == 0.0) {
		if(H_NDEF) {
			ret = {V, V, V};
		}
		else {
			std::cerr << "Invalid HSV to convert to RGB\n";
			return ret;
		}
	}
	else {
		H = (H == 360.0) ? (0.0) : (H / 60.0);
		sextant = floor(H);
		fract = H - (float)sextant;
		p = V * (1 - S);
		q = V * (1 - (S * fract));
		t = V * (1 - (S * (1 - fract)));
		switch(sextant) {
		case 0: ret = {v, t, p}; break;
		case 1: ret = {q, v, p}; break;
		case 2: ret = {p, v, t}; break;
		case 3: ret = {p, q, v}; break;
		case 4: ret = {t, p, v}; break;
		case 5: ret = {v, p, q}; break;
		default: std::cerr << "Invalid HSV to convert to RGB\n";
		}
	}
	return ret;
}

ColorRGBc ColorHSV::toRGBc() const {
	return this->toRGB().toRGBc();
}

// --- Other --- //
ColorHSV ColorHSV::getConst(const Color& color) {
	ColorHSV ret = {0,0,0};
	switch(color) {
	case Red: ret = {0,1,1}; break;
	case Orange: ret = {30,1,1}; break;
	case Yellow: ret = {60,1,1}; break;
	case Green: ret = {120,1,1}; break;
	case Cyan: ret = {180,1,1}; break;
	case Blue: ret = {240,1,1}; break;
	case Purple: ret = {270,1,1}; break;
	case Magenta: ret = {300,1,1}; break;
	case Black: ret = {-1,0,0}; break;
	case White: ret = {-1,0,1}; break;
	default: ret = ColorHSV::getConst(Black); break;
	}
	return ret;
}

std::ostream& operator<<(std::ostream& os, const ColorHSV& c) {
	return os << "{" << c.h << "," << c.s << "," << c.v << "}";
}

