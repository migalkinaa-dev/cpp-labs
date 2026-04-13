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

    void inflate(int amount);
    void inflate(int dw, int dh);
    void inflate(int dLeft, int dRight, int dTop, int dBottom);

    void move(int dx, int dy = 0);
};

#endif // RECT_HPP