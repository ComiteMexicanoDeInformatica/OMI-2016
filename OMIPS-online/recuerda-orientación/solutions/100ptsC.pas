iniciar-programa
    define-nueva-instruccion caminar(n) como inicio
        mientras no-junto-a-zumbador hacer inicio
            si frente-libre entonces inicio
                avanza;
            fin sino si izquierda-libre entonces inicio
                gira-izquierda;
            fin sino inicio
                gira-izquierda;
                gira-izquierda;
                gira-izquierda;
            fin;
        fin;
        mientras no-orientado-al-norte hacer inicio
            gira-izquierda;
        fin;
        repetir n veces inicio
            gira-izquierda;
        fin;
    fin;

    inicia-ejecucion
        si orientado-al-norte entonces inicio
            caminar(0);
        fin sino si orientado-al-oeste entonces inicio
            caminar(1);
        fin sino si orientado-al-sur entonces inicio
            caminar(2);
        fin sino inicio
            caminar(3);
        fin;
    termina-ejecucion
finalizar-programa
