//
// Created by Rostyslav on 25.03.2023.
//
#include "Vector2D.h"

Vector2D::Vector2D() {
    x = 0.0f;
    y = 0.0f;
}

Vector2D::Vector2D(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2D &Vector2D::Add(const Vector2D &vec) {
    this->x += vec.x;
    this->y += vec.y;
    return *this;
}

Vector2D &Vector2D::Substract(const Vector2D &vec) {
    this->x -= vec.x;
    this->y -= vec.y;
    return *this;
}

Vector2D &Vector2D::Multiply(const Vector2D &vec) {
    this->x *= vec.x;
    this->y *= vec.y;
    return *this;
}

Vector2D &Vector2D::Divide(const Vector2D &vec) {
    this->x /= vec.x;
    this->y /= vec.y;
    return *this;
}

Vector2D &operator+(Vector2D &vec1, const Vector2D &v2) {
    return vec1.Add(v2);
}

Vector2D &operator-(Vector2D &vec1, const Vector2D &v2) {
    return vec1.Substract(v2);
}

Vector2D &operator*(Vector2D &vec1, const Vector2D &v2) {
    return vec1.Multiply(v2);
}

Vector2D &operator/(Vector2D &vec1, const Vector2D &v2) {
    return vec1.Divide(v2);
}

Vector2D &Vector2D::operator+=(const Vector2D &vec) {
    this->Add(vec);
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &vec) {
    this->Substract(vec);
    return *this;
}

Vector2D &Vector2D::operator*=(const Vector2D &vec) {
    this->Multiply(vec);
    return *this;
}

Vector2D &Vector2D::operator/=(const Vector2D &vec) {
    this->Divide(vec);
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Vector2D &vec) {
    stream << "(" << vec.x << ", " << vec.y << ")";
    return stream;
}
