#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;


int Fractal(Pen^ pen1, Pen^ pen2, Graphics^ g, PointF p1, PointF p2, PointF p3, int iter)
{
    if (iter > 0)  //условие выхода из рекурсии
    {
        //средн€€ треть отрезка
        PointF p4 = PointF((p2.X + 2 * p1.X) / 3, (p2.Y + 2 * p1.Y) / 3);
        PointF p5 = PointF((2 * p2.X + p1.X) / 3, (p1.Y + 2 * p2.Y) / 3);
        //координаты вершины угла
        PointF ps = PointF((p2.X + p1.X) / 2, (p2.Y + p1.Y) / 2);
        PointF pn = PointF((4 * ps.X - p3.X) / 3, (4 * ps.Y - p3.Y) / 3);
        //рисуем его
        g->DrawLine(pen1, p4, pn);
        g->DrawLine(pen1, p5, pn);
        g->DrawLine(pen2, p4, p5);

        //рекурсивно вызываем функцию нужное число раз
        Fractal(pen1, pen2, g, p4, pn, p5, iter - 1);
        Fractal(pen1, pen2, g, pn, p5, p4, iter - 1);
        Fractal(pen1, pen2, g, p1, p4, PointF((2 * p1.X + p3.X) / 3, (2 * p1.Y + p3.Y) / 3), iter - 1);
        Fractal(pen1, pen2, g, p5, p2, PointF((2 * p2.X + p3.X) / 3, (2 * p2.Y + p3.Y) / 3), iter - 1);

    }
    return iter;
}
