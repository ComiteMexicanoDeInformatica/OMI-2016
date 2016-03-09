class program {

    //Pone un beeper. Reducida para que el archivo fuente pese menos.
    define pb(){
        pickbeeper();
    }

    define volteaNorte(){
       while(notFacingNorth){
        turnleft();
       }
    }

    define volteaSur(){
       while(notFacingSouth){
        turnleft();
       }
    }

    define volteaEste(){
       while(notFacingEast){
        turnleft();
       }
    }

    define p(n){
        iterate(n){
            putbeeper();
        }
    }

    //Mete a la pila la variable n y se mueve a la siguiente casilla.
    //En caso de no poder moverse, termina el programa.
    define m(n){
        volteaEste();
        if(frontIsBlocked){
             turnoff();
        }
        move();
        pila(n);
    }

    //Funcion generada por codigo.
    //Pone n beepers en la casilla e inserta en la pila el valor inicial de la casilla.
    //p(n) pone n beepers
    //m(n) mete a la pila la variable n
    define ponBeepersEmpuja(n){
        pickbeeper();
        if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb(); if( nextToABeeper ){pb();
        }else{p(n);m(101);} }else{p(n);m(100);} }else{p(n);m(99);} }else{p(n);m(98);} }else{p(n);m(97);} }else{p(n);m(96);} }else{p(n);m(95);} }else{p(n);m(94);} }else{p(n);m(93);} }else{p(n);m(92);} }else{p(n);m(91);} }else{p(n);m(90);} }else{p(n);m(89);} }else{p(n);m(88);} }else{p(n);m(87);} }else{p(n);m(86);} }else{p(n);m(85);} }else{p(n);m(84);} }else{p(n);m(83);} }else{p(n);m(82);} }else{p(n);m(81);} }else{p(n);m(80);} }else{p(n);m(79);} }else{p(n);m(78);} }else{p(n);m(77);} }else{p(n);m(76);} }else{p(n);m(75);} }else{p(n);m(74);} }else{p(n);m(73);} }else{p(n);m(72);} }else{p(n);m(71);} }else{p(n);m(70);} }else{p(n);m(69);} }else{p(n);m(68);} }else{p(n);m(67);} }else{p(n);m(66);} }else{p(n);m(65);} }else{p(n);m(64);} }else{p(n);m(63);} }else{p(n);m(62);} }else{p(n);m(61);} }else{p(n);m(60);} }else{p(n);m(59);} }else{p(n);m(58);} }else{p(n);m(57);} }else{p(n);m(56);} }else{p(n);m(55);} }else{p(n);m(54);} }else{p(n);m(53);} }else{p(n);m(52);} }else{p(n);m(51);} }else{p(n);m(50);} }else{p(n);m(49);} }else{p(n);m(48);} }else{p(n);m(47);} }else{p(n);m(46);} }else{p(n);m(45);} }else{p(n);m(44);} }else{p(n);m(43);} }else{p(n);m(42);} }else{p(n);m(41);} }else{p(n);m(40);} }else{p(n);m(39);} }else{p(n);m(38);} }else{p(n);m(37);} }else{p(n);m(36);} }else{p(n);m(35);} }else{p(n);m(34);} }else{p(n);m(33);} }else{p(n);m(32);} }else{p(n);m(31);} }else{p(n);m(30);} }else{p(n);m(29);} }else{p(n);m(28);} }else{p(n);m(27);} }else{p(n);m(26);} }else{p(n);m(25);} }else{p(n);m(24);} }else{p(n);m(23);} }else{p(n);m(22);} }else{p(n);m(21);} }else{p(n);m(20);} }else{p(n);m(19);} }else{p(n);m(18);} }else{p(n);m(17);} }else{p(n);m(16);} }else{p(n);m(15);} }else{p(n);m(14);} }else{p(n);m(13);} }else{p(n);m(12);} }else{p(n);m(11);} }else{p(n);m(10);} }else{p(n);m(9);} }else{p(n);m(8);} }else{p(n);m(7);} }else{p(n);m(6);} }else{p(n);m(5);} }else{p(n);m(4);} }else{p(n);m(3);} }else{p(n);m(2);} }else{p(n);m(1);}
    }
 
    //Funcion "bool" que regresa verdadero si la casilla es mayor igual que la variable, de lo contrario false.
    //Norte es true y sur false.
    define esCasillaMayorIgualQueVariable(n){
        if( iszero(n) ){
             volteaNorte();
             return();
        } else{
            if(notNextToABeeper){
                 volteaSur();
                 return();
            }
            pickbeeper();
            esCasillaMayorIgualQueVariable(pred(n));
            putbeeper();
        }
    }




    //Pregunta si la casilla es mayor igual que la variable n, es decir el top del stack
    //En caso de ser verdadero, pone en la variable n la cantidad de beepers en la casilla
    //y deja en la casilla el valor anterior de n, es decir, pone el ultimo prisionero que ve
    //y mete en la pila el prisionero actual. 
    //En caso de que la casilla sea menor que n, saca el elemento de la pila con return();
    define pila(n){

        iterate(100){
         esCasillaMayorIgualQueVariable(n); //Norte signfica true y Sur false
        if(facingSouth){
           ponBeepersEmpuja(n);
        }else{
           return();
        }
       }

    }

    //El primer elmento de la pila siempre deja 0 zumbadores en la casilla antes de ser incertado
    define llenaPrimerElementoPila(n){
        if(nextToABeeper){
           pickbeeper();
           llenaPrimerElementoPila(succ(n));
        }else{
           volteaEste();
           if(frontIsBlocked){
               turnoff();
           }
           move();
           pila(n);
        }
    }

    program () {
	
	//Itera 100 veces por la pila se vacia en cada prisionero
        iterate(100){
          volteaEste();
          llenaPrimerElementoPila(0);
        }
        turnoff();
    }
}
