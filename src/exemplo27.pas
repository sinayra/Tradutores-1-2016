program Exe21;

var 
	a, b: integer;

begin
	read(a,b);
	
	while (a < 10) or (b <= 10) do
	begin
		b := b + a;
		write(b);
		write(a);
		a := a + 1;
	end
	

end.