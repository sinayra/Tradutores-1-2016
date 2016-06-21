program Exe21;

var 
	a, b: integer;

begin
	read(a,b);
	
	if a <= 10 then
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