#include <complex>

using namespace std;

namespace solver {

    class RealVariable {

    public:
        double _a = 0, _b = 1, _c = 0;

        RealVariable() : _a(0), _b(1), _c(0) {}

        RealVariable(double a, double b, double c) : _a(a), _b(b), _c(c) {}

        ///////////////operator^/////////////
        RealVariable operator^(double x);

        /////////////// operator* /////////////
        friend RealVariable operator*(double x, const RealVariable &z);

        RealVariable operator*(double x);

        RealVariable operator*(const RealVariable &x);

        /////////////// operator/ /////////////

        RealVariable operator/(double x);

        friend RealVariable operator/(double x, const RealVariable &z);

        /////////////// operator+ //////////////
        friend RealVariable operator+(double x, const RealVariable &z);

        RealVariable operator+(double x);

        RealVariable operator+(const RealVariable &x);

        /////////////// operator- //////////////
        friend RealVariable operator-(double x, const RealVariable &z);

        RealVariable operator-(double x);

        RealVariable operator-(const RealVariable &x);

        /////////////// operator== //////////////
        friend RealVariable operator==(double x, const RealVariable &z);

        RealVariable operator==(double x);

        RealVariable operator==(const RealVariable &x);
    };

    /////////////// sqaureRoot //////////////
    double sqaureRoot(const RealVariable &x);

    /////////////// solve //////////////
    double solve(solver::RealVariable x);



    /////////////// ComplexVariable //////////////

    class ComplexVariable {

    public:
        complex<double> _a, _b, _c;

        ComplexVariable() : _a(0), _b(1), _c(0) {}

        ComplexVariable(complex<double> a, complex<double> b, complex<double> c) : _a(a), _b(b), _c(c) {}

        ///////////////operator^/////////////
        ComplexVariable operator^(int x);

        ///////////// operator+ //////////////
        friend ComplexVariable operator+(complex<double> x,const ComplexVariable &z);
        ComplexVariable operator+(complex<double> x);
        ComplexVariable operator+(const ComplexVariable &x);

        /////////////// operator- //////////////
        friend ComplexVariable operator-(complex<double> x,const ComplexVariable &z);
        ComplexVariable operator-(complex<double> x);
        ComplexVariable operator-(const ComplexVariable &x);

        /////////////// operator* /////////////
        friend ComplexVariable operator*(complex<double> x,const ComplexVariable &z);
        ComplexVariable operator*(complex<double> x);
        ComplexVariable operator*(const ComplexVariable &x);

        /////////////// operator/ /////////////
        ComplexVariable operator/(complex<double> x);
        friend ComplexVariable operator/(complex<double> x,const ComplexVariable &z);
//


        /////////////// operator== //////////////
        friend ComplexVariable operator==(complex<double> x, const ComplexVariable &z);
        ComplexVariable operator==(complex<double> x);
        ComplexVariable operator==(const ComplexVariable &x);
    };

    /////////////// sqaureRoot //////////////
    complex<double> sqaureRoot(const ComplexVariable &x);

    /////////////// solve //////////////
    complex<double> solve(solver::ComplexVariable x);
}
