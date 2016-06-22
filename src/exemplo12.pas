program Exe12;

var 
	a, b: integer;

begin
	read(a, b);
	
	if a < 10 then
		write(b);
	else
		a := b + b;

	write(a);
end.