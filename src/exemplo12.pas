program Exe12;

var 
	a, b: integer;

begin
	a := 5;
	b := 10;
	
	if a < 10 then
	begin
		if b < 20 then
		begin
			a := a + b;
			write(b);
		end
	end
	else
	begin
		b := b + b;
		write(b);
	end


	write(a);
end.