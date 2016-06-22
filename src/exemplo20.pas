program Exe20;

var 
	a, b: integer; (*eita que botei comentarios aqui*)
begin
	read(a, b);

	(*a = 1*)
	(*5*)
	(*b = 6*)
	(*3*)
	(*5 + 3 = 8*)
	(*8 - 2 = 6*)
	(*a = 6*)
	a := a * 5 + b div 2 - 2;

	write(a);
end.
