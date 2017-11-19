#include <iostream>

struct Time
{
    int hour;
    int minute;
};
int main(void) {
    Time first, second;
    int hours, minutes;
    std::cout << "Input 1st value hours and minutes: ";
    std::cin >> first.hour >> first.minute;
    std::cout << "Input 2nd value hours and minutes: ";
    std::cin >> second.hour >> second.minute;
    if(first.hour > 23 || first.hour < 0 || first.minute > 60 || first.minute < 0 || second.hour > 23 || second.hour < 0 || second.minute > 60 || second.minute < 0 
    || first.hour > second.hour || (first.hour > second.hour && first.minute > second.minute))
        std::cout << "Wrong time!";
    else
    {
        if(first.minute > second.minute)
        {
            second.hour--;
            minutes = 60 - (first.minute - second.minute); 
        }
        else
            minutes = second.minute - first.minute;
        hours = second.hour - first.hour;
    }
    std::cout << hours << ":" << minutes;
    return 0;
}
