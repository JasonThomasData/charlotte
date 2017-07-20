/* Based on a range of 200, these are the PWM signals that can be sent to the servos safely. These are
 * extremes for doing so with the small, 9g, sg90 servos.
 */

struct Positions
{
    int off = 0;
    int minimum = 2;
    int current = 0;
    int maximum = 24;
};
