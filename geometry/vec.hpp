#pragma once

template<class T>
struct vec
{
    T x, y;
    
    vec() : x(0), y(0) {}
    vec(T x, T y) : x(x), y(y) {}
    
    vec operator +(const vec& rhs) const { return vec(x + rhs.x, y + rhs.y); }
    vec operator -(const vec& rhs) const { return vec(x - rhs.x, y - rhs.y); }
    vec operator *(T k) const { return vec(x * k, y * k); }
    vec operator /(T k) const { return vec(x / k, y / k); }
    vec operator %(ll k) const { return vec(x % k, y % k); }
    vec &operator +=(const vec& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    vec &operator -=(const vec& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    vec &operator *=(T k) {
        x *= k;
        y *= k;
        return *this;
    }
    vec &operator /=(T k) {
        x /= k;
        y /= k;
        return *this;
    }
    vec &operator %=(ll k) {
        x %= k;
        y %= k;
        return *this;
    }
    bool operator ==(const vec& rhs) const {
        return (x==rhs.x && y==rhs.y);
    }
    bool operator !=(const vec& rhs) const {
        return (x != rhs.x || y != rhs.y);
    }
    bool operator <(const vec &rhs) const {
        if (x != rhs.x) return (x < rhs.x);
        else return (y < rhs.y);
    }
    bool operator >(const vec &rhs) const {
        if (x != rhs.x) return (x > rhs.x);
        else return (y > rhs.y);
    }

    T norm1() const {
        return abs(x) + abs(y);
    }
    T norm2() const {
        return x * x + y * y;
    }
    ld abs() const {
        return sqrtl(norm2());
    }
};
template <class T>
vec<T> operator *(T k, const vec<T>& v) {
    return vec<T>(k * v.x, k * v.y);
}
template<class T>
ostream& operator <<(ostream& os, const vec<T>& rhs)
{
    os << '(' << rhs.x << ',' << rhs.y << ')';
    return os;
}
template<class T>
istream& operator>>(istream& is, vec<T>& rhs)
{
    is >> rhs.x >> rhs.y;
    return is;
}
template <class T>
bool cmp_y(const vec<T>& a, const vec<T>& b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}