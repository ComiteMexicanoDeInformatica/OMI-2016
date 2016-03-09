class program {

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
    define volteaOeste(){
       while(notFacingWest){
        turnleft();
       }
    }


    //Deja el maximo entre n y (1,1) en la casilla (1,1)
    define ponMaximo(n){
        iterate(n){
            if(nextToABeeper)
                pickbeeper();
        }
        iterate(n){
            putbeeper();
        }
    }

    //Funci?n que lleva a Karel a comparar la variable contra la casilla (1,1)
    //Guarda en el stack los pasos que dio pero no modifica la variable
    //Al llegar a la (1,1) manda llamar ponMaximo y despu?s regresa recursivamente
    define compara(n){
        volteaOeste();
        if(frontIsClear){
             move();
             compara(n);
             volteaEste();
             move();
        }else{
             ponMaximo(n);
        }
    }

    define ponCeroYTermina(){
    	volteaOeste();
        while( frontIsClear ){
           move();
        }
        while(nextToABeeper){
        	pickbeeper();
        }
        turnoff();
        
    }

    //Funcion recursiva principal, agrega a la variable el monton de beepers actual. al terminar manda comprar contra la pila de la casilla (1,1)
    define aumentaPoder(n){

        if(nextToABeeper){
          pickbeeper();
          aumentaPoder(succ(n));
        }else{
          compara(n);
          volteaEste();
          if(frontIsBlocked){
              turnoff();
          }
          move();
          if(notNextToABeeper && iszero(pred(n))){
               ponCeroYTermina();
          }
          aumentaPoder(pred(n));
        }

    }
  
    program () {
	//Caso base cuando no hay poder inicial
        if(notNextToABeeper){
             turnoff();
        }

        aumentaPoder(0);
        turnoff();
    }
}
