#include <iostream>
#include <stdio.h>
#include "../include/Screen.h"



int main()
{
    Screen screen("Teste", 800, 800);
    while(!screen.isClosed()){
        screen.update();
        screen.render();
    }
    return 0;
}
