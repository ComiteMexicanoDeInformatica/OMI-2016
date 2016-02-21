class program {
    void turnright() {
        iterate(3)
            turnleft();
    }

    void darUnPaso() {
        if (frontIsClear) {
            move(); 
        } else if (facingWest) {
            turnright();
            if (frontIsClear) {
                move();
                turnright();
            }
        } else if (facingEast) {
            turnleft();
            if (frontIsClear) {
                move();
                turnleft();
            }
        }
    }

    program () {
        turnright();
        while (notFacingNorth) {
            if (nextToABeeper)
                pickbeeper();
            else putbeeper();
            darUnPaso();
        }
        turnoff();
    }
}
