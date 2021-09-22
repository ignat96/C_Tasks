#include <stdlib.h>
#include <math.h>

double trigl_P(double a, double b, double c) {
	double _rslt = a + b + c;
	return _rslt;
}

double trigl_S(double a, double b, double c) {
	double _sqr, _p;
	_p = trigl_P(a, b, c) / 2;
	_sqr = sqrt(_p*(_p - a)*(_p - b)*(_p - c));
	return _sqr;
}