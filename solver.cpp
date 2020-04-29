#include "solver.hpp"
#include <exception>
#include <iostream>
#include <math.h>

using namespace solver;
using namespace std;

///////////////operator^/////////////
RealVariable solver::RealVariable::operator^(double x) {
    if (x == 2) {
        return (*this) * (*this);
    }
    else if (x == 1) {
        return *this;
    }
    else if (x == 0) {
        return RealVariable(0, 0, 1);
    }
    else throw std::runtime_error("error");
}

/////////////// operator* /////////////
RealVariable solver::operator*(double x,const RealVariable &z) {
    return RealVariable(z._a*x,z._b*x,z._c*x);
}

RealVariable solver::RealVariable::operator*(double x) {
    return RealVariable(this->_a*x,this->_b*x,this->_c*x);
}

RealVariable solver::RealVariable::operator*(const RealVariable& x) {
    if ((this->_a != 0 && (x._a != 0 || x._b != 0)) || (x._a != 0 && this->_b != 0)){
        throw std::runtime_error("error");}
    else if (this->_a != 0)
        return (*this) * x._c;
    else if (x._a != 0)
        return RealVariable(x._a*this->_c,x._b*this->_c,x._c*this->_c);
    return RealVariable(this->_b * x._b,this->_c * x._b + this->_b * x._c,this->_c * x._c);
}

/////////////// operator/ /////////////
RealVariable solver::RealVariable::operator/(double x) {
    return RealVariable(this->_a / x,this->_b / x,this->_c / x);
}

RealVariable solver::operator/(double x,const RealVariable& z) {
return RealVariable(z._a / x,z._b / x,z._c / x);
}

/////////////// operator+ //////////////
RealVariable solver::operator+(double x,const RealVariable &z) {
    return RealVariable(z._a,z._b,x+z._c);
}

RealVariable solver::RealVariable::operator+(double x) {
    return RealVariable(this->_a,this->_b,this->_c+x);
}

RealVariable solver::RealVariable::operator+(const RealVariable& z) {
    return RealVariable(this->_a+z._a,this->_b+z._b,this->_c+z._c);
}

/////////////// operator- //////////////
RealVariable solver::operator-(double x,const RealVariable &z) {
    return RealVariable(-z._a,-z._b,x-z._c);
}

RealVariable solver::RealVariable::operator-(double x) {
    return RealVariable(this->_a,this->_b,this->_c-x);
}

RealVariable solver::RealVariable::operator-(const RealVariable& z) {
    return RealVariable(this->_a-z._a,this->_b-z._b,this->_c-z._c);
}


/////////////// operator== //////////////
RealVariable solver::operator==(double x, const RealVariable &z) {
    return RealVariable(z._a,z._b,z._c-x);
}
RealVariable solver::RealVariable::operator==(double x) {
    return (*this)-x;
}
RealVariable solver::RealVariable::operator==(const RealVariable &x) {

    return (*this) - x;
}

/////////////// sqaureRoot_RealVariable //////////////
double solver::sqaureRoot(const RealVariable &x) {
    double Dalta = (x._b * x._b) - 4 * x._a * x._c;
    if (Dalta >= 0) {
        return (-x._b + sqrt(Dalta)) / (2 * x._a);
    } else {
        throw runtime_error("error");
    }
}

/////////////// solve //////////////
double solver::solve(const solver::RealVariable x) {
    if (x._a != 0) {
        return sqaureRoot(x);
    } else if (x._b != 0) {
        return (-x._c) / x._b;
    } else if (x._c == 0) {
        return 0;
    } else throw runtime_error("error");
}

/////////////////////////////////////ComplexVariable::operator^//////////////////////////
ComplexVariable solver::ComplexVariable::operator^(int x) {
    if (x == 2) {
        return (*this)*(*this);
    }
    else if (x == 1) {
        return *this;
    }
    else if (x == 0) {
        return ComplexVariable(0, 0, 1);
    }
    else throw std::runtime_error("error");
}


/////////////// operator+ //////////////
ComplexVariable solver::operator+(std::complex<double> x,const ComplexVariable &z) {
    return ComplexVariable(z._a,z._b,x+z._c);
}

ComplexVariable solver::ComplexVariable::operator+(std::complex<double> x) {
    return ComplexVariable(this->_a,this->_b,this->_c+x);
}

ComplexVariable solver::ComplexVariable::operator+(const ComplexVariable& z) {
    return ComplexVariable(this->_a+z._a,this->_b+z._b,this->_c+z._c);
}

/////////////// operator- //////////////
ComplexVariable solver::operator-(std::complex<double> x,const ComplexVariable &z) {
    return ComplexVariable(-z._a,-z._b,x-z._c);
}

ComplexVariable solver::ComplexVariable::operator-(std::complex<double> x) {
    return ComplexVariable(this->_a,this->_b,this->_c-x);
}

ComplexVariable solver::ComplexVariable::operator-(const ComplexVariable& z) {
    return ComplexVariable(this->_a-z._a,this->_b-z._b,this->_c-z._c);
}


/////////////// operator* /////////////
ComplexVariable solver::operator*(std::complex<double> x,const ComplexVariable &z) {
    return ComplexVariable(z._a*x,z._b*x,z._c*x);
}

ComplexVariable solver::ComplexVariable::operator*(std::complex<double> x) {
    return ComplexVariable(this->_a*x,this->_b*x,this->_c*x);
}

ComplexVariable solver::ComplexVariable::operator*(const ComplexVariable& x) {
    if ((this->_a != 0.0 && (x._a != 0.0 || x._b != 0.0)) || (x._a != 0.0 && this->_b != 0.0)){
        throw std::runtime_error("error");}
    else if (this->_a != 0.0)
        return (*this) * x._c;
    else if (x._a != 0.0)
        return ComplexVariable(x._a*this->_c,x._b*this->_c,x._c*this->_c);
    return ComplexVariable(this->_b * x._b,this->_c * x._b + this->_b * x._c,this->_c * x._c);
}

/////////////// operator== //////////////
ComplexVariable solver::operator==(std::complex<double> x, const ComplexVariable &z) {
    return ComplexVariable(z._a,z._b,z._c-x);
}
ComplexVariable solver::ComplexVariable::operator==(std::complex<double> x) {
    return (*this)-x;
}
ComplexVariable solver::ComplexVariable::operator==(const ComplexVariable &x) {

    return (*this) - x;
}

/////////////// operator/ /////////////
ComplexVariable solver::ComplexVariable::operator/(std::complex<double> x) {
    return ComplexVariable(this->_a / x,this->_b / x,this->_c / x);
}

ComplexVariable solver::operator/(std::complex<double> x,const ComplexVariable& z) {
    return ComplexVariable(z._a / x,z._b / x,z._c / x);
}

/////////////// sqaureRoot_ComplexVariable //////////////
std::complex<double> solver::sqaureRoot(const ComplexVariable &x) {
    std::complex<double> Dalta = (x._b * x._b) - 4.0 * x._a * x._c;
    return (-x._b + sqrt(Dalta)) / (2.0 * x._a);
}

/////////////// solve //////////////
std::complex<double> solver::solve(const solver::ComplexVariable x) {
    if (x._a != 0.0) {
        return sqaureRoot(x);
    } else if (x._b != 0.0) {
        return (-x._c) / x._b;
    } else if (x._c == 0.0) {
        return 0;
    } else throw runtime_error("error");
}