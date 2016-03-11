unit fiesta;

interface
	procedure BusquedaCool(n: LongInt);

implementation

uses Main;

procedure BusquedaCool(n: LongInt);
begin
    result := 0; // Ninguno de los dos es un chico popular.

    if (n = 1) result := 1; Caso especial de una persona.

    // Si 2 conoce a 1 y 1 no conoce a 2, entonces 1 es popular.
    if (Preguntar(2, 1)) and (not Preguntar(1, 2)) then result := 1;

    // Si 1 conoce a 2 y 2 no conoce a 1, entonces 2 es popular.
    if (Preguntar(1, 2)) and (not Preguntar(2, 1)) then result := 2;
end;

end.
