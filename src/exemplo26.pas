program Exe21;

var 
	a, b: integer;

begin
	read(a,b);
	
	if (a > 10) or (b <= 10) then
	begin
		b := b + a;
		write(b);
		if b <> 16 then
		begin
			write(a, a + 2, 9);
		end
	end
	else
	begin
		b := 5;
		write(b, b + 2, 9);
	end
	

end.