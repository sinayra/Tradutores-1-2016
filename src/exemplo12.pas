program Exe21;

var 
	a, b: integer;

begin
	a := 5;
	b := 10;
	
	if a < 10 then
	begin
		write(b);
	end
	else
	begin
		b := b + b;
		write(b);
	end


	write(a);
end.