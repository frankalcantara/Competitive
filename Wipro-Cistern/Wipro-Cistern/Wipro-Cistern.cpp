#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

// Fast integer reading function
inline int read_int() {
    int c, sign = 1, x = 0;
    while ((c = getchar()) < '-');
    if (c == '-') {
        sign = -1;
        c = getchar();
    }
    for (; c >= '0'; c = getchar())
        x = x * 10 + (c - '0');
    return x * sign;
}

// Fast integer output function using putchar
inline void write_int(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write_int(x / 10);
    putchar(x % 10 + '0');
}

const double PI = 3.14159265358979323846;

int main() {
    // Read input values
    int r = read_int();
    getchar(); // Ignore comma
    int h = read_int();
    getchar(); // Ignore comma
    int s = read_int();
    int d = read_int();
    getchar(); // Ignore comma
    int g = read_int();

    // Normalize angle g to be between 0 and 359 degrees
    g = (g % 360 + 360) % 360;

    double min_distance = 0.0;

    if (d > 0) {
        // Destination is on the lateral surface
        int t = d;
        // Calculate vertical distance
        double delta_h = abs(s - t);

        // Calculate the arc length on the cylinder's surface
        // The bug needs to travel (g/360) of the full circumference
        double arc_length = (g * 2 * PI * r) / 360.0;

        // Calculate direct path distance using Pythagorean theorem
        min_distance = hypot(delta_h, arc_length);
    }
    else {
        // Destination is on the top surface
        int a = -d;

        // Distance to reach the top
        min_distance = s;

        // Convert angle to radians
        double angle_rad = g * PI / 180.0;

        // Calculate distance on top surface using polar to Cartesian conversion
        double distance_BF = hypot(r - a * cos(angle_rad), a * sin(angle_rad));
        min_distance += distance_BF;
    }

    // Round to nearest integer
    int result_final = static_cast<int>(round(min_distance));

    // Use optimized function to print the result
    write_int(result_final);
    putchar('\n');

    return 0;
}