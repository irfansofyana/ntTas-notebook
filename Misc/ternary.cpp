/*We are given a function f(x) which is unimodal on an interval [l;r]. By unimodal function, we mean one of two behaviors of the function:

The function strictly increases first, reaches a maximum (at one point or at a segment), and then strictly decreases.

The function strictly decreases first, reaches a minimum, and then strictly increases.

In this article we will assume the first scenario, and the second is be completely symmetrical to it.

The task is to find the maximum of function f(x) on the interval [l;r].*/
double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}