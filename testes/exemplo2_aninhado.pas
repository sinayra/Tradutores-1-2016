program Exe2;
(*
	Se a, b, c, d, e e f forem menores que 10
		escreva 10
	escreva a
*)
var 
	a, b, c, d, e, f: integer;

begin
	read(a, b, c, d, e, f);
	
	if a < 10 then
		if b < 10 then
			if c < 10 then
				if d < 10 then
					if e < 10 then
						if f < 10 then
							write(10);
	write(a);
end.