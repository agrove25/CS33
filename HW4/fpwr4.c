#include <stdio.h>

static float u2f(unsigned u) {
	union convert {
		unsigned i;
		float f;
	} c;

	c.i = u;
	return c.f;
}

float fpwr4(int x) {
	unsigned exp, frac;
	unsigned u;

	if (x < -74) {
		exp = 0;
		frac = 0;
	}
	else if (x < -63) {
		exp = 0;
		frac = 1 << (x*2 + 149);
	}
	else if (x < 64) {
		exp = x + x*2;
		frac = 0
	}
	else {
		exp = 255;
		frac = 0;
	}

	u = exp << 23 | frac;
	return u2f(u);
}

int main() {
	printf("%f", fpwr4(2));
	printf("%f", fpwr4(3));
}