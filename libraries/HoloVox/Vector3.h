#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
  public:
    Vector3() : x(0), y(0), z(0) {}
    Vector3(const float _x, const float _y, const float _z) : x(_x), y (_y), z(_z) {};

    float x;
    float y;
    float z;

    float magnitude() const;
    float sqrMag() const;
    void normalize();


    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    void operator+=(const Vector3& other);

    Vector3 operator*(const Vector3& other) const;
    Vector3 operator*(const int other) const;
    Vector3 operator*(const float other) const;
    void operator*=(const Vector3& other);
    void operator*=(const int other);
    void operator*=(const float other);
};

#endif
