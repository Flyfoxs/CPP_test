#include <vector>
#include <iostream>

float mianji(float a){
    return (4-2*a)*a*(8-2*a);
}
int main() {
    for(int i=1; i<200; i++)
        std::cout<<i << " " <<mianji(i/100.0) << std::endl;

    return 0;
}

