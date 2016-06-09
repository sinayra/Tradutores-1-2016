program Exe10;

var 
	a, b: integer;

begin
	a := 2;
	b := a;
	write(b);

	a := a + b;
	b := a;
	write(b);
end.