#include "Vector2D.hpp"

Vector2D::Vector2D():m_x(0), m_y(0) { }    
Vector2D::Vector2D(float x, float y): m_x(x), m_y(y) {}

Vector2D::~Vector2D(){}
    
float Vector2D::getX() const { return m_x; }
 float Vector2D::getY() const { return m_y; }

void Vector2D::setX(float x) { m_x = x; }
void Vector2D::setY(float y) { m_y = y; }

int Vector2D::length() { return sqrt(m_x * m_x + m_y * m_y); }
     
void Vector2D::normalize() {
    int l = length();
    if ( l > 0)
    {
        (*this) *= 1 / l;
    }
}
    