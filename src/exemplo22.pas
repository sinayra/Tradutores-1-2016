program Exe22;
(*Imprime valor de c se a, b e c forem menores que 10*)

var 
	a, b, c: integer;

begin
	read(a, b, c);
	
	if a < 10 then
		if b < 10 then
			if c < 10 then
				write(c);
	a := 10;
	write(a);
end.