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


// 1.9 

void Rect::inflate(int dLeft, int dRight, int dTop, int dBottom)
{
    left -= dLeft;
    right += dRight;
    top += dTop;
    bottom -= dBottom;
}

void Rect::inflate(int amount)
{
    inflate(amount, amount, amount, amount);

}

void Rect::inflate(int dw, int dh)
{
    inflate(dw, dw, dh, dh);

}



void Rect::move(int dx, int dy)
{
    left += dx;
    right += dx;
    top += dy;
    bottom += dy;
}


// 1.10
static int minInt(int a, int b) { return (a < b) ? a : b; }
static int maxInt(int a, int b) { return (a > b) ? a : b; }

static int rectMinX(const Rect& r) { return minInt(r.getLeft(), r.getRight()); }
static int rectMaxX(const Rect& r) { return maxInt(r.getLeft(), r.getRight()); }
static int rectMinY(const Rect& r) { return minInt(r.getBottom(), r.getTop()); }
static int rectMaxY(const Rect& r) { return maxInt(r.getBottom(), r.getTop()); }

Rect boundingRect(Rect r1, Rect r2)
{
    int left   = minInt(rectMinX(r1), rectMinX(r2));
    int right  = maxInt(rectMaxX(r1), rectMaxX(r2));
    int bottom = minInt(rectMinY(r1), rectMinY(r2));
    int top    = maxInt(rectMaxY(r1), rectMaxY(r2));

    return Rect(left, right, top, bottom);
}

void printRect(Rect &r)
{
    std::cout << "Rect: L=" << r.getLeft()
              << " R=" << r.getRight()
              << " T=" << r.getTop()
              << " B=" << r.getBottom()
              << "\n";
}

// 1.11
int Rect::getWidth() const
{
    int minX = (left < right) ? left : right;
    int maxX = (left > right) ? left : right;
    return maxX - minX;
}

int Rect::getHeight() const
{
    int minY = (bottom < top) ? bottom : top;
    int maxY = (bottom > top) ? bottom : top;
    return maxY - minY;
}

int Rect::getSquare() const
{
    return getWidth() * getHeight();
}

// Важно: “не меняя координаты точки с минимальными X и Y”.
// То есть фиксируем minX/minY, двигаем только противоположную сторону.
void Rect::setWidth(int w)
{
    if (w < 0) w = -w;

    if (left <= right) {
        // minX = left, оставляем left как есть
        right = left + w;
    } else {
        // minX = right, оставляем right как есть
        left = right + w;
    }
}

void Rect::setHeight(int h)
{
    if (h < 0) h = -h;

    if (bottom <= top) {
        // minY = bottom, оставляем bottom как есть
        top = bottom + h;
    } else {
        // minY = top, оставляем top как есть
        bottom = top + h;
    }
}