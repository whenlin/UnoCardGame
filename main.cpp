//
//  main.cpp
//  res
//
//  Created by WHenlin on 2017-06-04.
//  Copyright © 2017 WHenlin. All rights reserved.
//

#include <iostream>
#include "UnoGame.h"
using namespace std;

int main()
{
    cout<<"Welcome to UNO!"<<endl;
    UnoGame game;
    game.play();
    cout<<"The game has ended"<<endl;
    return 0;
}
