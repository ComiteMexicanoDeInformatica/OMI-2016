class program {

    void girar(n) {
        iterate(n)
            turnleft();
    }

    void hastaBeeper() {
        while (notNextToABeeper)
            move();
    }
    
    void hastaPared() {
        while (frontIsClear)
            move();
    }
    
    void volverAlInicio() {
        while (facingEast) {
            while (frontIsClear &&
                rightIsBlocked) move();
            girar(3);
            if (frontIsClear) {
                move();
                girar(3);
                while (frontIsClear)
                    move();
                girar(2);
            } else {
                girar(3);
                hastaPared();
            }
        }
    }
    
    void colocar(n) {
        volverAlInicio();
        iterate(succ(n))
            iterate(succ(n))
                putbeeper();
        turnoff();
    }

    void checarColumna(n) {
        putbeeper();
        turnleft();
        iterate(n) {
            if (facingNorth) {
                if (frontIsClear)
                    move();
                else
                    girar(2);
            }
        }
        if (facingNorth) {
            girar(2);
            hastaBeeper();
            turnleft();
        } else {
            hastaBeeper();
            girar(3);
        }
        pickbeeper();
    }

    void checarFila(n) {
        putbeeper();
        iterate(n) {
            if (facingEast) {
                checarColumna(n);
                if (facingEast) {
                    if (frontIsClear)
                        move();
                    else
                        girar(2);
                }
            }
        }
        if (facingEast)
            checarColumna(n);

        if (facingEast) {
            girar(2);
            hastaBeeper();
            pickbeeper();
            hastaPared();
            girar(2);
            colocar(n);
        } else {
            hastaBeeper();
            pickbeeper();
            girar(2);
        }
    }

    void intentar(n) {
        while (facingEast) {
            checarFila(n);
            if (frontIsBlocked) {
                girar(2);
                while (frontIsClear &&
                    rightIsBlocked) move();
                girar(3);
                if (frontIsClear) {
                    move();
                    turnleft();
                    while (frontIsClear)
                        move();
                    girar(2);
                } else {
                    girar(3);
                    volverAlInicio();
                }
            } else
                move();
        }
        girar(2);
        intentar(pred(n));
    }

    program () {
        while (notFacingWest)
            turnleft();
        girar(2);
        volverAlInicio();
        intentar(49);
    }
}
