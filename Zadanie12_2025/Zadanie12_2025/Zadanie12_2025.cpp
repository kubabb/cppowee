#include <iostream>
using namespace std;
#include <cstdint>

int f(int num) {
    std::uint8_t a = num & 0x1F;
    std::uint8_t b = ((a << 2) | 0x03) ^ 0xA5;
    std::uint8_t c = (b % 26);
    return c;
}

int main()
{
    
    cout << f(11) << endl; 
    cout << f(305) << endl;
    cout << f(557) << endl;
    cout << f(1101) << endl;



}

