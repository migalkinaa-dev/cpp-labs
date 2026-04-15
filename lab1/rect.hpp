#ifndef RECT_HPP
#define RECT_HPP

class Rect
{
private:
    int left;
    int right;
    int top;
    int bottom;

public:
    Rect();
    Rect(int l, int r, int t, int b);
    Rect(const Rect& other);
    ~Rect();

    int getLeft() const;
    int getRight() const;
    int getTop() const;
    int getBottom() const;

    void setAll(int left, int right, int top, int bottom);

// 1.9
    void inflate(int amount);
    void inflate(int dw, int dh);
    void inflate(int dLeft, int dRight, int dTop, int dBottom);

    void move(int dx, int dy = 0);

// 1.11
    int getWidth() const;
    int getHeight() const;
    int getSquare() const;

    void setWidth(int w);
    void setHeight(int h);
};

// 1.10 (Это функции. Не методы класса Rect)
Rect boundingRect(Rect r1, Rect r2);
void printRect(Rect &r);

#endif // RECT_HPP