iniciar-programa
    define-nueva-instruccion orientar-al-este como inicio
        mientras no-orientado-al-este hacer inicio
            gira-izquierda;
        fin;
    fin;
    
    define-nueva-instruccion girar(n) como inicio
        repetir n veces inicio
            gira-izquierda;
        fin;
    fin;
    
    define-nueva-instruccion vuelta-y-regreso como inicio
        girar(2);
        mientras frente-libre hacer inicio
            avanza;
        fin;
    fin;
    
    define-nueva-instruccion dibuja-alfombra(n) como inicio
        mientras frente-libre hacer inicio
            repetir n veces inicio
                avanza;
            fin;
            girar(3);
            repetir n veces inicio
                mientras frente-libre hacer inicio
                    repetir n veces inicio
                        avanza;
                    fin;
                    repetir n veces inicio
                        si no-junto-a-zumbador entonces inicio
                            deja-zumbador;
                        fin;
                        avanza;
                    fin;
                    repetir precede(n) veces inicio
                        avanza;
                    fin;
                    si frente-libre entonces inicio
                        avanza;
                    fin;
                fin;
                vuelta-y-regreso;
                girar(3);
                avanza;
                girar(3);
            fin;
            gira-izquierda;
            repetir precede(n) veces inicio
                avanza;
            fin;
            si frente-libre entonces inicio
                avanza;
            fin;
        fin;
    fin;

    define-nueva-instruccion dividir-por-3(n) como inicio
        si junto-a-zumbador entonces inicio
            repetir 3 veces inicio
                si junto-a-zumbador entonces inicio
                    coge-zumbador;
                fin sino inicio
                    gira-izquierda;
                fin;
            fin;
            dividir-por-3(sucede(n));
        fin sino inicio
            si orientado-al-norte entonces inicio
                repetir n veces inicio
                    deja-zumbador;
                fin;
                dibuja-alfombra(n);
                vuelta-y-regreso;
                girar(2);
            fin;
        fin;
    fin;
    
    define-nueva-instruccion cuenta(n) como inicio
        si frente-libre entonces inicio
            avanza;
            cuenta(sucede(n));
        fin sino inicio
            vuelta-y-regreso;
            repetir sucede(n) veces inicio
                deja-zumbador;
            fin;
        fin;
    fin;

    inicia-ejecucion
        cuenta(0);
        girar(2);
        mientras orientado-al-norte hacer inicio
            dividir-por-3(0);
        fin;
    termina-ejecucion
finalizar-programa
