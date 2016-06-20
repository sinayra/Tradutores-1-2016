program Exe15;

var 
	a, b, aux: integer;

begin
	a := 1;
	b := 1;
	
	while b < 11 do
	begin
		a := 1;
		while a < 11 do
		begin
			aux := a * b;
			write(aux);
			a := a + 1;
		end
		b := b + 1;
	end
end.