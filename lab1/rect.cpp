#include "rect.hpp"
#include <iostream>

Rect::Rect()
{
    left = right = top = bottom = 0;
    std::cout << "Rect()        this=" << this << "\n";
}

Rect::Rect(int l, int r, int t, int b)
{
    left = l;
    right = r;
    top = t;
    bottom = b;
    std::cout << "Rect(int...)  this=" << this << "\n";
}

Rect::Rect(const Rect& other)
{
    left = other.left;
    right = other.right;
    top = other.top;
    bottom = other.bottom;
    std::cout << "Rect(copy)    this=" << this << " from=" << &other << "\n";
}

Rect::~Rect()
{
    std::cout << "~Rect()       this=" << this << "\n";
}

int Rect::getLeft() const { return left; }
int Rect::getRight() const { return right; }
int Rect::getTop() const { return top; }
int Rect::getBottom() const { return bottom; }

void Rect::setAll(int l, int r, int t, int b)
{
    left = l;
    right = r;
    top = t;
    bottom = b;
}

void Rect::inflate(int amount)
{
    inflate(amount, amount, amount, amount);
}

void Rect::inflate(int dw, int dh)
{
    inflate(dw, dw, dh, dh);
}

void Rect::inflate(int dLeft, int dRight, int dTop, int dBottom)
{
    left -= dLeft;
    right += dRight;
    top += dTop;
    bottom -= dBottom;
}

void Rect::move(int dx, int dy)
{
    left += dx;
    right += dx;
    top += dy;
    bottom += dy;
}