program Exe22;
(*
	Se a, b e c forem menores que 10
		escreva 10
	escreva a
*)
var 
	a, b, c: integer;

begin
	read(a, b, c);
	
	if a < 10 then
		if b < 10 then
			if c < 10 then
				write(10);
	write(a);
end.