program Exe3;
(*Imprime a tabuada de 1 até 9*)
var 
	a, b, aux: integer;

begin

	b := 1;	
	while b < 10 do
	begin
		a := 1;
		while a <= 10 do
		begin
			aux := a * b;
			write(aux);
			a := a + 1;
		end
		b := b + 1;
	end
end.