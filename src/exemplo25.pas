program Exe21;

var 
	a, b: integer;

begin
	read(a,b);
	
	if (a > 10) and (b <= 10) then
	begin
		b := b + a;
		write(b);
		if b <> 16 then
		begin
			write(a);
		end
	end
	

end.