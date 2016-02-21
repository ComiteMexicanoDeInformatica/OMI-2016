class program {

void sigueCamino(){
    while(notNextToABeeper){
        if(frontIsClear) move();
        if(leftIsClear)
            turnleft();
        if(rightIsClear)
            iterate(3) turnleft();
    }
}

program() {
    if(facingNorth){
        sigueCamino();
        while(notFacingNorth) turnleft();
        turnoff();
    }
    if(facingEast){
        sigueCamino();
        while(notFacingEast) turnleft();
        turnoff();
    }
    if(facingSouth){
        sigueCamino();
        while(notFacingSouth) turnleft();
        turnoff();
    }
    if(facingWest){
        sigueCamino();
        while(notFacingWest) turnleft();
        turnoff();
    }
    turnoff();
}

}
