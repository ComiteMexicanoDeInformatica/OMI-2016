unit pesca;
{
	unit Main;
	function UsarApp(x1: LongInt; y1: LongInt; x2: LongInt; y2: LongInt): LongInt;
	function TirarRed(x1: LongInt; y1: LongInt; x2: LongInt; y2: LongInt): LongInt;
}

interface
	procedure Pescar(w: LongInt; h: LongInt; n: LongInt; k: LongInt);

implementation

uses Main;

procedure Pescar(w: LongInt; h: LongInt; n: LongInt; k: LongInt);
begin

  //preguntamos en todo el mapa
  for i := 0 to w-1 do begin
      for j := 0 to h-1 do begin
          usarApp(i,j,i+1,j+1);
      end;
  end;
  //buscamos en la primar posicion
  TirarRed(1,1,2,2);

end;

end.         