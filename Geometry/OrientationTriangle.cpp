// Given three points p1, p2 and p3, calculate an oriented (
// signed) area of a triangle formed by them. The sign of 
// the area is determined in the following way: imagine you are 
// standing in the plane at point p1 and are facing p2. You go to 
// p2 and if p3 is to your right (then we say the three vectors turn 
// "clockwise"), the sign of the area is positive, otherwise it is 
// negative. If the three points are collinear, the area is zero.

int signed_area_parallelogram(point2d p1, point2d p2, point2d p3) {
    return cross(p2 - p1, p3 - p2);
}

double triangle_area(point2d p1, point2d p2, point2d p3) {
    return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
}

bool clockwise(point2d p1, point2d p2, point2d p3) {
    return signed_area_parallelogram(p1, p2, p3) < 0;
}

bool counter_clockwise(point2d p1, point2d p2, point2d p3) {
    return signed_area_parallelogram(p1, p2, p3) > 0;
}