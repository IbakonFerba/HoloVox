#include "Vector3.h"
#include <Arduino.h>


float Vector3::magnitude() const {
  return sqrt(x * x + y * y + z * z);
}

float Vector3::sqrMag() const {
  return x * x + y * y + z * z;
}

void Vector3::normalize()
{
  const float mag = magnitude();

  if (mag != 0) {
    x /= mag;
    y /= mag;
    z /= mag;
  }
}


Vector3 Vector3::operator+(const Vector3& other) const {
  return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
  return Vector3(x - other.x, y - other.y, z - other.z);
}

void Vector3::operator+=(const Vector3& other) {
  x += other.x;
  y += other.y;
  z += other.z;
}

Vector3 Vector3::operator*(const Vector3& other) const {
  return Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3 Vector3::operator*(const int other) const {
  return Vector3(x * other, y * other, z * other);
}

Vector3 Vector3::operator*(const float other) const {
  return Vector3(x * other, y * other, z * other);
}

void Vector3::operator*=(const Vector3& other) {
  x *= other.x;
  y *= other.y;
  z *= other.z;
}

void Vector3::operator*=(const int other) {
  x *= other;
  y *= other;
  z *= other;
}

void Vector3::operator*=(const float other) {
  x *= other;
  y *= other;
  z *= other;
}

