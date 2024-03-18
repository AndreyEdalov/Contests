#include <cmath>

class Complex
{
public:
    Complex(double real, double imaginary = 0.0) : re(real), im(imaginary)
    {}

    double Re() const
    {
        return re;
    }

    double Im() const
    {
        return im;
    }

    Complex operator+() const
    {
        return *this;
    }

    Complex operator-() const
    {
        return Complex(-re, -im);
    }

    Complex operator+(const Complex& other) const
    {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    Complex operator/(const Complex& other) const
    {
        double denominator = other.re * other.re + other.im * other.im;
        return Complex((re * other.re + im * other.im) / denominator,
                       (im * other.re - re * other.im) / denominator);
    }

    Complex operator+(double rhs) const
    {
        return Complex(re + rhs, im);
    }

    Complex operator-(double rhs) const
    {
        return Complex(re - rhs, im);
    }

    Complex operator*(double rhs) const
    {
        return Complex(re * rhs, im * rhs);
    }

    Complex operator/(double rhs) const
    {
        return Complex(re / rhs, im / rhs);
    }

    bool operator==(const Complex& other) const
    {
        return re == other.re && im == other.im;
    }

    bool operator!=(const Complex& other) const
    {
        return !(*this == other);
    }

private:
    double re, im;
};

Complex operator+(double lhs, const Complex& rhs)
{
    return rhs + lhs;
}

Complex operator-(double lhs, const Complex& rhs)
{
    return Complex(lhs) - rhs;
}

Complex operator*(double lhs, const Complex& rhs)
{
    return rhs * lhs;
}

Complex operator/(double lhs, const Complex& rhs)
{
    return Complex(lhs) / rhs;
}

double abs(const Complex& complex)
{
    return sqrt(complex.Re() * complex.Re() + complex.Im() * complex.Im());
}
